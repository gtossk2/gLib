CC = gcc
INC_DIR = include
SRC_DIR = src
CFLAGS = -Wall

all: DynamicString_main SimpleMemoryPool_main

DynamicString_main: $(SRC_DIR)/DynamicString.c
	${CC} -o $@ $@.c $^ -I$(INC_DIR)

SimpleMemoryPool_main: $(SRC_DIR)/SimpleMemoryPool.c
	${CC} -o $@ $@.c $^ -I$(INC_DIR)

clean:
	rm -rf DynamicString_main
	rm -rf SimpleMemoryPool_main
