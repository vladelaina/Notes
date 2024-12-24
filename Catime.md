你希望在启动新实例时，若检测到已有相同的实例在运行，就将旧实例的倒计时重置为 25 分钟。为了实现这一点，我们可以通过以下步骤来修改代码：

### 主要思路：

1. **检测已有实例**：你已经使用了互斥体（`CreateMutex`）来确保只有一个实例在运行。当检测到已有实例时，可以通过消息机制（如 `WM_COPYDATA`）向旧实例发送倒计时重置的请求。
2. **处理消息**：修改窗口过程函数（`WindowProcedure`）来处理来自新实例的消息，并重置倒计时。

### 修改步骤：

#### 1. 修改 `WM_COPYDATA` 处理逻辑：

在旧实例中，你需要在 `WindowProcedure` 函数里处理 `WM_COPYDATA` 消息，并根据 `dwData` 字段判断是否是倒计时重置请求。如果是，则重置倒计时。

#### 2. 新实例发送重置请求：

当新实例检测到旧实例正在运行时，通过 `SendMessage` 发送一个 `WM_COPYDATA` 消息，告诉旧实例将倒计时重置为 25 分钟。

sudo pacman -S gcc g++ make



sudo pacman -S sdl2 sdl2_image

###### 动态连接库

x86_64-w64-mingw32-gcc  -o main.exe main.c \
  -I/home/vladelaina/code/catime/src/test/libs/SDL2/include \
  -I/home/vladelaina/code/catime/src/test/libs/SDL2_image/include \
  -L/home/vladelaina/code/catime/src/test/libs/SDL2/lib \
  -L/home/vladelaina/code/catime/src/test/libs/SDL2_image/lib \
  -lSDL2 -mwindows -lSDL2_image



> 将/home/vladelaina/code/catime/src/test/libs/SDL2/include/SDL2的头文件复制到/home/vladelaina/code/catime/src/test/libs/SDL2_image/include 提供使用







find "$(pwd)" -type f -name "SDL.h"

cp /home/vladelaina/code/catime/src/test/libs/SDL2/include/SDL2 /home/vladelaina/code/catime/src/test/libs/SDL2_image/include/SDL2/ -r

### 6.1 基本操作代码示例

对于初次接触WezTerm的新手来说，掌握一些基本操作的代码示例是快速上手的关键。下面，我们将通过几个简单的例子来展示如何使用WezTerm进行日常的命令行操作。首先，让我们来看看如何打开一个新的终端会话。在WezTerm中，只需按下`Ctrl + Shift + T`组合键，即可轻松开启一个新的会话窗口。如果你想要在现有的窗口中添加一个新标签页，那么`Ctrl + T`就是你的得力助手。此外，通过`Ctrl + Tab`和`Ctrl + Shift + Tab`，用户还可以方便地在不同的会话之间来回切换，极大地提升了多任务处理的效率。当然，除了这些基本的快捷键外，WezTerm还提供了丰富的自定义选项，允许用户根据个人喜好调整快捷键设置，从而达到更高的操作流畅度。

ls

sudo pacman -S ffmpeg

你可以使用 `ffmpeg` 将 MP4 视频逐帧提取并保存为 PNG 格式的图片。具体命令如下：

```bash
ffmpeg -i 1.mp4 -vf "fps=10" %d.png
python "D:\Date\Tool\rmbg\try.py" .
```

这个命令的解释如下：

- `-i input.mp4`：指定输入的 MP4 文件。
- `-vf "fps=1"`：使用视频滤镜 (`-vf`)，`fps=1` 表示每秒提取 1 帧。如果你希望提取更多帧，可以调整 `fps` 的值。例如，`fps=30` 会每秒提取 30 帧。
- `output_%04d.png`：输出的文件名格式，`%04d` 是一个占位符，它会根据提取的帧编号自动编号，例如 `output_0001.png`、`output_0002.png` 等。

如果你想提取1帧，只需要去掉 `fps=1`，如下所示：

```bash
ffmpeg -i 1.mp4 %d.png
```

这样会提取视频中的每一帧并保存为 PNG 图片。

- 执行以下命令：
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

choco install ffmpeg

ffmpeg -version

一帧 = 15ms

fps = 10



#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_syswm.h>
#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// 常量定义
#define IMAGE_DIR "./cat"       // 图片文件夹目录
#define SWITCH_INTERVAL 50     // 图片切换时间（毫秒）

// 判断文件是否为 PNG 格式
int is_png(const char *filename) {
    const char *ext = strrchr(filename, '.');
    return ext != NULL && strcmp(ext, ".png") == 0;
}

// 获取指定目录下的所有 PNG 文件
int get_png_files(const char *dir, char ***image_files) {
    DIR *d = opendir(dir);
    if (d == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", dir);
        return 0;
    }

    struct dirent *entry;
    int count = 0;
    while ((entry = readdir(d)) != NULL) {
        if (is_png(entry->d_name)) {
            (*image_files) = realloc(*image_files, sizeof(char*) * (count + 1));
            (*image_files)[count] = malloc(strlen(dir) + strlen(entry->d_name) + 2);
            sprintf((*image_files)[count], "%s/%s", dir, entry->d_name);
            count++;
        }
    }
    closedir(d);
    return count;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 初始化 SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // 初始化 SDL_image
    if (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG == 0) {
        fprintf(stderr, "IMG_Init Error: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }
    
    // 获取 IMAGE_DIR 目录下的所有 PNG 文件
    char **image_files = NULL;
    int image_count = get_png_files(IMAGE_DIR, &image_files);
    if (image_count == 0) {
        fprintf(stderr, "No PNG files found in %s\n", IMAGE_DIR);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    // 获取第一张图片的宽高
    SDL_Surface *image = IMG_Load(image_files[0]);
    if (image == NULL) {
        fprintf(stderr, "IMG_Load Error: %s\n", IMG_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    int imgWidth = image->w;
    int imgHeight = image->h;
    
    // 创建窗口，窗口大小根据图片大小调整
    SDL_Window *window = SDL_CreateWindow("SDL2 Image Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, imgWidth, imgHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_FreeSurface(image);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    // 获取窗口的原始窗口句柄
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (SDL_GetWindowWMInfo(window, &wmInfo) != 1) {
        fprintf(stderr, "SDL_GetWindowWMInfo failed\n");
        SDL_DestroyWindow(window);
        SDL_FreeSurface(image);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    HWND hwnd = wmInfo.info.win.window;
    
    // 设置为工具窗口
    LONG_PTR style = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
    SetWindowLongPtr(hwnd, GWL_EXSTYLE, style | WS_EX_TOOLWINDOW | WS_EX_LAYERED | WS_EX_TRANSPARENT);
    
    // 设置窗口透明并允许鼠标穿透
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY); // 设置透明色键为黑色
    
    // 设置窗口为置顶
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    
    // 创建渲染器
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_FreeSurface(image);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    // 创建纹理
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image); // 不再需要表面了
    if (texture == NULL) {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    // 设置混合模式
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND); // 设置纹理的混合模式为混合
    
    // 设置托盘图标
    NOTIFYICONDATA nid;
    ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = 1;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
    nid.uCallbackMessage = WM_APP; // 设置消息回调
    nid.hIcon = (HICON)LoadImage(NULL, "icon.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE); // 图标路径
    
    // 修改 nid.szTip 的类型为 wchar_t 数组
    wchar_t szTip[128];  // 定义为 wchar_t 类型
    wcsncpy(szTip, L"My Tray Icon", sizeof(szTip) / sizeof(wchar_t)); // 宽字符字符串
    wcscpy((wchar_t*)nid.szTip, szTip); // 使用宽字符字符串填充
    
    Shell_NotifyIcon(NIM_ADD, &nid);
    
    // 事件循环
    SDL_Event e;
    int quit = 0;
    int current_image_index = 0;
    Uint32 last_time = SDL_GetTicks();
    
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    
        // 每隔SWITCH_INTERVAL切换一次图片
        Uint32 current_time = SDL_GetTicks();
        if (current_time - last_time >= SWITCH_INTERVAL) {
            last_time = current_time;
            current_image_index = (current_image_index + 1) % image_count;
    
            // 加载下一张图片
            SDL_Surface *new_image = IMG_Load(image_files[current_image_index]);
            if (new_image == NULL) {
                fprintf(stderr, "IMG_Load Error: %s\n", IMG_GetError());
                continue;
            }
    
            // 创建新纹理
            SDL_Texture *new_texture = SDL_CreateTextureFromSurface(renderer, new_image);
            SDL_FreeSurface(new_image);
    
            if (new_texture == NULL) {
                fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
                continue;
            }
    
            SDL_DestroyTexture(texture);  // 销毁旧纹理
            texture = new_texture;        // 更新为新纹理
        }
    
        // 渲染图片
        SDL_RenderClear(renderer);
        SDL_Rect dstRect = {0, 0, imgWidth, imgHeight}; // 目标矩形，指定显示的图片大小
        SDL_RenderCopy(renderer, texture, NULL, &dstRect); // 使用指定大小渲染
        SDL_RenderPresent(renderer);
    
        SDL_Delay(10); // 防止占用过多 CPU
    }
    
    // 清理资源
    Shell_NotifyIcon(NIM_DELETE, &nid); // 删除托盘图标
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
    // 释放图片文件名数组
    for (int i = 0; i < image_count; i++) {
        free(image_files[i]);
    }
    free(image_files);
    
    return 0;
}