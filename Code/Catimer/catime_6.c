#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_TIME 1500  // 默认倒计时时长为 25 分钟 = 1500 秒
#define ID_TRAY_APP_ICON  1001
#define ID_TRAY_EXIT      1002
#define WM_TRAYICON        (WM_USER + 1)  // 自定义消息 ID
#define WINDOW_CLASS_NAME  "PomodoroTimerWindow"  // 确保窗口类名唯一

static int elapsed_time = 0;  // 已经过的时间，全局变量
static int TOTAL_TIME = DEFAULT_TIME;  // 全局倒计时总时间
NOTIFYICONDATA nid;  // 托盘图标数据

// 格式化倒计时文本的函数
void FormatTime(int remaining_time, char* time_text) {
    int minutes = remaining_time / 60;
    int seconds = remaining_time % 60;
    if (minutes == 0 && seconds < 10) {
        sprintf(time_text, "%d", seconds);  // 只显示秒数
    } else if (minutes == 0) {
        sprintf(time_text, "%d", seconds);
    } else {
        sprintf(time_text, "%d:%02d", minutes, seconds);
    }
}

// 退出程序的函数
void ExitProgram() {
    Shell_NotifyIcon(NIM_DELETE, &nid);  // 删除托盘图标
    PostQuitMessage(0);  // 退出消息循环
}

// 托盘图标的右键菜单响应函数
void ShowContextMenu(HWND hwnd) {
    HMENU hMenu = CreatePopupMenu();
    AppendMenu(hMenu, MF_STRING, ID_TRAY_EXIT, "退出");

    POINT pt;
    GetCursorPos(&pt);
    SetForegroundWindow(hwnd);  // 确保菜单显示在应用程序的窗口上
    TrackPopupMenu(hMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN, pt.x, pt.y, 0, hwnd, NULL);
    DestroyMenu(hMenu);
}

// 处理消息的窗口过程函数
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    static char time_text[50];  // 存储倒计时文本

    switch (msg) {
        case WM_PAINT: {
            // 获取绘图上下文
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            int remaining_time = TOTAL_TIME - elapsed_time;

            // 如果倒计时已经结束，不显示时间
            if (elapsed_time >= TOTAL_TIME) {
                sprintf(time_text, "Time's up!");  // 显示“时间到！”
            } else {
                FormatTime(remaining_time, time_text);
            }

            SetTextColor(hdc, RGB(255, 255, 255));  // 设置文本颜色
            SetBkMode(hdc, TRANSPARENT);  // 设置背景透明
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
            TextOutA(hdc, 10, 10, time_text, strlen(time_text));
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_TIMER: {
            // 每秒更新倒计时
            if (elapsed_time < TOTAL_TIME) {
                elapsed_time++;
                InvalidateRect(hwnd, NULL, TRUE);  // 强制重绘窗口
            } else {
                InvalidateRect(hwnd, NULL, TRUE);  // 最后一次更新
                MessageBox(hwnd, "Time's up! The specified time has passed.", "Pomodoro Timer", MB_OK);
                KillTimer(hwnd, 1);  // 停止定时器
            }
            break;
        }
        case WM_DESTROY:
            ExitProgram();  // 删除托盘图标并退出
            break;
        case WM_TRAYICON: {
            if (wp == WM_RBUTTONUP) {
                ShowContextMenu(hwnd);  // 显示右键菜单
            } else if (wp == ID_TRAY_EXIT) {
                ExitProgram();  // 点击退出
            }
            break;
        }
        case WM_COPYDATA: {  // 处理从另一个实例发送的参数
            PCOPYDATASTRUCT cds = (PCOPYDATASTRUCT)lp;
            if (cds->dwData == 1) {  // 使用自定义数据标识
                int new_time = atoi((char*)cds->lpData);
                if (new_time > 0) {
                    TOTAL_TIME = new_time;  // 更新倒计时总时间
                    elapsed_time = 0;  // 重置计时器
                    if (SetTimer(hwnd, 1, 1000, NULL) == 0) {
                        // 如果 SetTimer 失败，记录日志或进行错误处理
                        MessageBox(hwnd, "Failed to set timer!", "Error", MB_OK);
                    }
                }
            }
            break;
        }
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

// GUI 程序的入口点 WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 解析命令行参数
    if (lpCmdLine != NULL && strlen(lpCmdLine) > 0) {
        char* time_str = lpCmdLine;
        int length = strlen(time_str);
        if (length > 1 && time_str[length - 1] == 's') {
            time_str[length - 1] = '\0';  // 去掉 's'
            TOTAL_TIME = atoi(time_str);
            if (TOTAL_TIME <= 0) {
                TOTAL_TIME = DEFAULT_TIME;
            }
        } else {
            TOTAL_TIME = atoi(time_str) * 60;
            if (TOTAL_TIME <= 0) {
                TOTAL_TIME = DEFAULT_TIME;
            }
        }
    }

    // 创建互斥体，确保只有一个实例
    HANDLE hMutex = CreateMutex(NULL, TRUE, "PomodoroTimerMutex");
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        // 如果已有实例运行，则将参数发送给该实例
        HWND hwnd = FindWindow(WINDOW_CLASS_NAME, "Pomodoro Timer");  // 确保正确传递窗口类名
        if (hwnd) {
            COPYDATASTRUCT cds;
            cds.dwData = 1;
            char time_str[10];
            sprintf(time_str, "%d", TOTAL_TIME);
            cds.lpData = time_str;
            cds.cbData = strlen(time_str) + 1;
            SendMessage(hwnd, WM_COPYDATA, (WPARAM)hwnd, (LPARAM)&cds);
        }
        return 0;
    }

    // 注册窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProcedure;  // 窗口过程函数
    wc.hInstance = hInstance;
    wc.lpszClassName = WINDOW_CLASS_NAME;  // 设置唯一的窗口类名
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // 创建无边框透明窗口，使用 WS_EX_TOOLWINDOW 隐藏任务栏图标
    HWND hwnd = CreateWindowEx(
        WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW,  // 添加 WS_EX_TOOLWINDOW 隐藏任务栏
        WINDOW_CLASS_NAME,  // 使用唯一的窗口类名
        "Pomodoro Timer",  // 窗口标题
        WS_POPUP,
        1, 1,
        90, 65,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // 设置窗口的透明度
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

    // 托盘图标设置
    nid.cbSize = sizeof(nid);
    nid.uID = ID_TRAY_APP_ICON;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
    nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
    nid.hWnd = hwnd;
    nid.uCallbackMessage = WM_TRAYICON;  // 使用自定义消息
    strcpy(nid.szTip, "Pomodoro Timer");
    Shell_NotifyIcon(NIM_ADD, &nid);  // 添加托盘图标

    // 启动计时器
    if (SetTimer(hwnd, 1, 1000, NULL) == 0) {
        MessageBox(hwnd, "Failed to set timer!", "Error", MB_OK);
        return 0;
    }

    // 显示窗口并进入消息循环
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

