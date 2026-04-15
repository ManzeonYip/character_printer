# 基本配置
CC = gcc
CFLAGS = -fPIC -Wall -Wextra -I./include  # 头文件路径
LDFLAGS = -shared -fPIC -Wall       # 编译动态库需要

# 目录定义
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = bin

# 目标文件
LIB_TARGET = $(LIB_DIR)/libnumber_cmp.so
BIN_TARGET = $(BIN_DIR)/number_cmp

# 源文件 / 目标文件
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

LIB_LINKS = -L./lib -lnumber_cmp

# 默认编译动态库 + 测试程序
all: $(LIB_TARGET) $(BIN_TARGET)

# 编译动态库
$(LIB_TARGET): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $@

# 编译测试程序
$(BIN_TARGET): $(LIB_TARGET)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_FILES) $(LIB_LINKS) -o $@

# 编译 .o 文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR)

