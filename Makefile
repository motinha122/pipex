CC = gcc

CFLAGS = -Wall -Iincludes -g

SRC_DIR = src
INCLUDE_DIR = includes
BUILD_DIR = build

# Nome do executável
NAME = $(BUILD_DIR)/pipex

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test:
	./$(NAME) 

# run: 
# 	./$(NAME) file1 cmd1 cmd2 file2

run: 
	./$(NAME) file1 ls cmd2 file2

valquiria:
	valgrind ./$(NAME)

clean:
	rm -rf $(BUILD_DIR)

re: clean all

redo: clean all run

#commands 
.PHONY: all clean run valquiria re