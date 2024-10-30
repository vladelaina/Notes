# 简介

GNU Compiler Collection

> GNU’s Not Unix编辑器集合



```bash
sudo apt install gcc g++
```

- gcc 编译C
- g++ 编译C++



```bash
gcc --version
```

# 在 Windows 上安装 GCC

MinGW（Minimalist GNU for Windows），一个适用于 Windows 的极简 GNU 工具集



[MinGW-w64

- 

- 将解压后的 `bin` 目录添加到系统环境变量 `PATH` 中







```bash
gcc <File.Name> 

gcc -o <Out.Name> <File.Name>  	#指定输出文件名
     output
```



```bash
./a.exe  # Windows
./a.out  # Linux
```





### C++ 文件编译

1. 准备一个 C++ 源文件（例如 `hello.cpp`）。
2. 在命令行中，输入以下命令编译 C++ 文件：

```bash
g++ hello.cpp
```

3. 同样，可以使用 `-o` 选项指定输出文件名：

```bash
g++ -o hello hello.cpp
```

## 4. 编译过程详解

编译过程可以分为四个阶段：预处理、编译、汇编和链接。我们来逐步了解每个阶段的操作。

### 预处理

预处理阶段处理 `#include` 指令、宏定义和注释等。可以使用 `-E` 选项查看预处理后的结果：

```bash
gcc -E hello.c -o hello.i
```

### 编译

编译阶段将预处理后的文件转换为汇编代码。可以使用 `-S` 选项查看编译后的汇编代码：

```bash
gcc -S hello.i -o hello.s
```

### 汇编

汇编阶段将汇编代码转换为机器指令。可以使用 `-c` 选项生成目标文件：

```bash
gcc -c hello.s -o hello.o
```

### 链接

链接阶段将目标文件和所需的库文件链接生成可执行文件。直接执行以下命令：

```bash
gcc hello.o -o hello
```

## 5. 编译选项

### 编译警告

GCC 提供多种警告选项帮助检测代码中的潜在问题。常见的警告选项有：

- `-Wall`：开启所有常见的警告。
- `-Werror`：将警告视为错误，阻止编译通过。

```bash
gcc -Wall -Werror hello.c
```

### 优化选项

GCC 提供了多种优化选项，可以通过 `-O` 系列选项进行代码优化：

- `-O0`：不进行优化（默认）。
- `-O1`：基本优化。
- `-O2`：进一步优化。
- `-O3`：包括增加代码大小的所有优化。

```bash
gcc -O2 hello.c -o hello
```

### 编码选项

如果需要处理不同编码的文件，可以使用 `-finput-charset` 和 `-fexec-charset` 选项：

```bash
gcc -finput-charset=UTF-8 -fexec-charset=GBK hello.c
```

## 6. 动态链接与静态链接

### 动态链接

默认情况下，GCC 使用动态链接。这意味着运行时会加载所需的库文件，而不是将库文件复制到可执行文件中。

```bash
gcc hello.c -o hello
```

### 静态链接

静态链接将所需的库文件直接复制到可执行文件中，生成的文件较大，但独立性更强。使用 `-static` 选项进行静态链接：

```bash
gcc -static hello.c -o hello
```

## 7. 处理编码问题

在编译包含中文字符的代码时，可能会遇到乱码问题。解决方法如下：

### 方法一：转换源文件编码

将源文件的编码转换为命令行窗口使用的编码（例如 GBK）。

### 方法二：修改命令行编码

修改命令行窗口的编码为源文件的编码（例如 UTF-8）：

```bash
chcp 65001
```

### 方法三：编译时指定编码

在编译时指明源文件和执行环境的编码：

```bash
gcc -finput-charset=UTF-8 -fexec-charset=GBK hello.c -o hello
```

## 8. 查看 GCC 文档

GCC 的官网提供了详细的文档，可以在官网查看或下载：

[GCC 文档](https://gcc.gnu.org/onlinedocs/)

## 结论

通过本指南，你应该对 GCC 的基本操作和使用有了较为全面的了解。无论是在 Linux 还是 Windows 系统上，GCC 都是一个强大而灵活的编译工具。希望这些内容能帮助你在学习和使用 C 语言及其他编程语言时更加得心应手。