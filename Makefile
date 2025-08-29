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

run: 
	./$(NAME) file1 cmd1 cmd2 file2

runa: 
	./$(NAME) documento.txt grep 

runb: 
	./$(NAME) print_argv grep Unix cmd2 file2

runc:
	./$(NAME) cat documento.txt batata cenoura ^ grep mainha

valquiria: 
	valgrind ./$(NAME) cat documento.txt batata cenoura ^ grep mainha

clean:
	rm -rf $(BUILD_DIR)

re: clean all

redo: clean all run

test: clean all runc

testa: clean all runa

#commands 
.PHONY: all clean run runa runb runc valquiria re