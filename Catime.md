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

动态连接库

x86_64-w64-mingw32-gcc -o main.exe main.c \
  -I/home/vladelaina/.libs/SDL2-2.30.10/x86_64-w64-mingw32/include \
  -L/home/vladelaina/.libs/SDL2-2.30.10/x86_64-w64-mingw32/lib \
  -lSDL2 -mwindows



