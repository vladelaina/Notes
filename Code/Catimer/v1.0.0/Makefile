# 设置编译器
CC = x86_64-w64-mingw32-gcc
WINDRES = x86_64-w64-mingw32-windres

# 获取当前时间，格式为 MM_DD-HH_MM_SS
DATE = $(shell date +%m_%d-%H_%M_%S)

# 设置目标文件夹路径
OUTPUT_DIR = /mnt/c/Users/vladelaina/Desktop/catime-$(DATE)
ASSET_DIR = $(OUTPUT_DIR)/asset

# 设置源文件路径
SRC_DIR = src
RESOURCE_DIR = resources
BUILD_DIR = build

# 设置文件名
SRC_FILES = $(SRC_DIR)/main.c
RC_FILE = $(RESOURCE_DIR)/resource.rc
OBJ_FILE = $(BUILD_DIR)/resource.o
IMAGE_DIR = $(RESOURCE_DIR)/images

# 编译选项
CFLAGS = -mwindows

# 生成目标
all: $(OUTPUT_DIR)/catime.exe

# 编译资源文件，将 .o 放到 build 目录
$(OBJ_FILE): $(RC_FILE)
	@$(WINDRES) $(RC_FILE) -o $(OBJ_FILE)

# 链接编译目标文件，输出到输出目录
$(OUTPUT_DIR)/catime.exe: $(SRC_FILES) $(OBJ_FILE)
	@mkdir -p $(OUTPUT_DIR)  # 创建输出目录
	@mkdir -p $(ASSET_DIR)    # 创建资产目录
	@$(CC) -o $(OUTPUT_DIR)/catime.exe $(SRC_FILES) $(OBJ_FILE) $(CFLAGS)
	@cp -r $(IMAGE_DIR) $(ASSET_DIR)  # 复制 images 文件夹到 asset 目录

# 清理构建文件，删除生成的 .o 文件和目标文件
clean:
	@rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

