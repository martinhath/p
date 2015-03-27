CC=clang
FLAGS=-g -O2 #-Weverything
NAME=p

main:
	$(CC) $(FLAGS) p.c -o $(NAME)

install: main
	cp p /usr/bin/p
