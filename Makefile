CC = gcc
CFLAGS = -Iinclude

LIB_NAME = libminmax.a

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TEST_DIR = test
LIB_DIR = lib

SRC_FILES = $(SRC_DIR)/min_max.c
OBJ_FILES = $(BUILD_DIR)/min_max.o

all: $(LIB_DIR)/$(LIB_NAME)

$(LIB_DIR)/$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/min_max.o: $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

test: all
	$(CC) $(TEST_DIR)/main.c -o $(TEST_DIR)/main -L$(LIB_DIR) -lminmax $(CFLAGS)
	$(TEST_DIR)/main
