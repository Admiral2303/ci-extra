all:
	gcc -c src/*.c -std=c99 -Werror -Wall -pedantic-errors -I./include
	gcc *.o -o a.out -lcheck
	rm *.o
	./a.out