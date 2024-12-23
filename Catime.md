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
ffmpeg -i input.mp4 -vf "fps=10" output_%04d.png
```

这个命令的解释如下：

- `-i input.mp4`：指定输入的 MP4 文件。
- `-vf "fps=1"`：使用视频滤镜 (`-vf`)，`fps=1` 表示每秒提取 1 帧。如果你希望提取更多帧，可以调整 `fps` 的值。例如，`fps=30` 会每秒提取 30 帧。
- `output_%04d.png`：输出的文件名格式，`%04d` 是一个占位符，它会根据提取的帧编号自动编号，例如 `output_0001.png`、`output_0002.png` 等。

如果你想提取所有帧，只需要去掉 `fps=1`，如下所示：

```bash
ffmpeg -i input.mp4 output_%04d.png
```

这样会提取视频中的每一帧并保存为 PNG 图片。



一帧 = 15ms

fps = 10