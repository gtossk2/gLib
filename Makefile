CC = gcc
INC_DIR = include
SRC_DIR = src
CFLAGS = -Wall

all: DynamicString_main

DynamicString_main: $(SRC_DIR)/DynamicString.c
	${CC} -o $@ $@.c $^ -I$(INC_DIR)

clean:
	rm -rf DynamicString_main
