#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 5000            // 增大存储单词数量的限制
#define MAX_WORD_LENGTH 46       // 最大单词长度增加到 45
#define MAX_CLIPBOARD_SIZE 1048576 // 1MB 剪切板数据最大大小限制
#define MAX_SINGLE_WORD_LENGTH 90  // 最大单词长度限制为 90

// 函数：检查单词是否已存在
int word_exists(char words[][MAX_WORD_LENGTH], int word_count, const char* word) {
    for (int i = 0; i < word_count; ++i) {
        if (strcmp(words[i], word) == 0) {
            return 1;  // 单词已存在
        }
    }
    return 0;  // 单词不存在
}

// 函数：检查单词是否为无效的
int is_invalid_word(const char* word) {
    if (strlen(word) < 3 || strlen(word) > 46) {
        return 1;  // 无效单词：长度小于 3 或超过 46
    }
    for (int i = 0; word[i] != '\0'; ++i) {
        if (isdigit(word[i])) {
            return 1;  // 无效单词：包含数字
        }
    }
    return 0;  // 有效单词
}

// 函数：提取并处理剪切板中的单词
void process_clipboard_data(char *pbuf, char words[][MAX_WORD_LENGTH], int *word_count) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    // 清除前导的非字母和数字字符
    while (*pbuf && !isalnum(*pbuf)) {
        ++pbuf;
    }

    if (*pbuf == 0) return;  // 如果已到文本末尾

    // 提取单词
    while (*pbuf && isalnum(*pbuf)) {
        // 限制最大单词长度为 MAX_SINGLE_WORD_LENGTH
        if (i >= MAX_SINGLE_WORD_LENGTH) {
            // 跳过当前单词，处理下一个
            while (*pbuf && isalnum(*pbuf)) {
                ++pbuf;
            }
            return;
        }
        word[i++] = *pbuf++;  // 将字母或数字字符赋给 word
    }
    word[i] = '\0';  // 添加字符串结束符

    // 如果该单词是有效的并且尚未存在，添加到 words 数组
    if (is_invalid_word(word) == 0 && !word_exists(words, *word_count, word)) {
        strcpy(words[*word_count], word);  // 保存单词到数组
        (*word_count)++;
    }
}

// 函数：处理剪切板数据（分批处理大数据）
void handle_large_clipboard_data(char *pbuf, char words[][MAX_WORD_LENGTH], int *word_count) {
    int data_size = 0;

    // 读取数据，直到达到最大大小
    while (*pbuf != '\0' && data_size < MAX_CLIPBOARD_SIZE) {
        process_clipboard_data(pbuf, words, word_count);

        // 跳过已处理的字母和数字字符，跳过空白字符
        while (*pbuf && isalnum(*pbuf)) {
            ++pbuf;
        }
        while (*pbuf && !isalnum(*pbuf)) {
            ++pbuf;
        }

        // 增加读取的字节数
        data_size = pbuf - (char *)GlobalLock(GetClipboardData(CF_TEXT));  // 计算已读取的数据字节数
    }
}

// 函数：将文本内容复制到剪切板
void copy_to_clipboard(const char *text) {
    // 打开剪切板
    if (OpenClipboard(NULL)) {
        // 清空剪切板
        EmptyClipboard();

        // 获取文本长度
        size_t len = strlen(text) + 1;  // 包括结束符

        // 分配剪切板缓冲区
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
        if (hMem) {
            // 锁定内存块
            char *p = (char *)GlobalLock(hMem);
            if (p) {
                // 将文本拷贝到内存块中
                memcpy(p, text, len);
                GlobalUnlock(hMem);

                // 将数据设置到剪切板
                SetClipboardData(CF_TEXT, hMem);
            }
            // 清理内存
            GlobalFree(hMem);
        }
        // 关闭剪切板
        CloseClipboard();
    }
}

// 函数：通过 Chrome 打开 URL
void open_url_in_chrome(const char *url) {
    // 使用 ShellExecute 打开浏览器
    ShellExecute(NULL, "open", "chrome.exe", url, NULL, SW_SHOWNORMAL);
}

// 函数：模拟按键（Alt + X）
void simulate_alt_x() {
    // 模拟按下 Alt 键
    keybd_event(VK_MENU, 0, 0, 0);
    // 模拟按下 X 键
    keybd_event('X', 0, 0, 0);
    // 模拟释放 X 键
    keybd_event('X', 0, KEYEVENTF_KEYUP, 0);
    // 模拟释放 Alt 键
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
}

// Windows 执行程序的入口点
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HANDLE hclip;
    char *pbuf = NULL;
    DWORD clipboardSize;
    char words[MAX_WORDS][MAX_WORD_LENGTH];  // 存储单词的数组
    int word_count = 0;  // 单词计数器

    // 打开剪切板，获取其中的数据
    if (OpenClipboard(NULL) == 0) {
        return -1;
    }

    // 检查剪切板是否包含文本数据
    if (!IsClipboardFormatAvailable(CF_TEXT)) {
        CloseClipboard();
        return -1;
    }

    // 获取剪切板数据
    hclip = GetClipboardData(CF_TEXT);
    pbuf = (char *)GlobalLock(hclip);  // 锁定剪切板数据

    if (pbuf == NULL) {
        CloseClipboard();
        return -1;
    }

    // 获取剪切板数据的大小
    clipboardSize = GlobalSize(hclip);

    // 处理剪切板数据
    handle_large_clipboard_data(pbuf, words, &word_count);

    // 计算总单词数的 10%
    int top_difficult_word_count = word_count / 10;
    if (top_difficult_word_count == 0) top_difficult_word_count = 1;  // 至少提取一个单词

    // 构建结果文本
    char result[MAX_CLIPBOARD_SIZE] = {0};
    snprintf(result, sizeof(result), 
             "Extract the %d most difficult words from the middle, and append the Chinese translation after each word, The first letter of the English word is lowercase, At the same time, no numbering is required at the beginning, Format: English Word - Chinese Translation:\n\n", 
             top_difficult_word_count);

    // 将有效单词追加到结果文本
    for (int i = 0; i < word_count; i++) {
        strcat(result, words[i]);
        strcat(result, "\n");
    }

    // 将结果文本复制到剪切板
    copy_to_clipboard(result);

    // 关闭资源
    GlobalUnlock(hclip);  // 解锁剪切板数据
    CloseClipboard();     // 关闭剪切板

    // 打开 Chrome 浏览器访问网址
    open_url_in_chrome("https://chatgpt.com/");

    // 延迟 0.5 秒
    Sleep(400);  // 延迟 500 毫秒

    // 模拟按下 Alt + X 快捷键
    simulate_alt_x();

    return 0;
}

