CC = gcc
INC_DIR = include
SRC_DIR = src
CFLAGS = -Wall -g

SRC = src/DynamicString.c \
			src/SimpleMemoryPool.c \
			src/rbtree.c

target = DynamicString_main \
				 SimpleMemoryPool_main \
				 rbtree_main

all: $(target)

DynamicString_main: $(SRC)
	${CC} -o $@ $@.c $^ -I$(INC_DIR) $(CFLAGS)

SimpleMemoryPool_main: $(SRC)
	${CC} -o $@ $@.c $^ -I$(INC_DIR) $(CFLAGS)

rbtree_main: $(SRC)
	$(CC) -o $@ $@.c $^ -I$(INC_DIR) $(CFLAGS)

clean: $(target)
	rm -rf $^
