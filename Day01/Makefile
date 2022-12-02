CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g

NAME1 = puzzle1
NAME2 = puzzle2

p1: $(NAME1).c
	$(CC) $(CFLAGS) $(NAME1).c -o $(NAME1).exe

p2: $(NAME2).c
	$(CC) $(CFLAGS) $(NAME2).c -o $(NAME2).exe

clean:
	rm -rf *.exe

all: p1 p2
