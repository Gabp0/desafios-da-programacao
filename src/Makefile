CC = c++
CFLAGS = -g -std=c++20 -O2 -Wall -fsanitize=address,undefined 

VPATH = src:src/*

.PHONY: all

all: %

% : %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
