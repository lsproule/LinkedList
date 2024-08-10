CC=clang++
CFLAGS=-I./include
VERSION=c++23

cpp:
	$(CC) -std=$(VERSION) -o build/main src/*.cpp $(CFLAGS) 

setup:
	mkdir -p build


.PHONY: all

all: cpp setup 
