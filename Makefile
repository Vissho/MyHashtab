CC = gcc

CFLAGS = -g3 -O0 -Wall -Wextra -Werror -fPIC
LIBS = -I include/ -I thirdparty/

.PHONY: all

all: myHashtab.out

myHashtab.out: src/main.c myHashtab.a
	$(CC) $(CFLAGS) $(LIBS) -o $@ -L. $^

myHashtab.a: src/myHashtab.c
	$(CC) $(CFLAGS) $(LIBS) -c $^
	ar r myHashtab.a myHashtab.o

.PHONY: clean
clean:
	find . -type f -name "*.so" -exec rm -f {} \;
	find . -type f -name "*.a" -exec rm -f {} \;
	find . -type f -name "*.out" -exec rm -f {} \;
	find . -type f -name "*.o" -exec rm -f {} \;
	find . -type f -name "*.d" -exec rm -f {} \;

rebuild: clean all

run:
	./myHashtab.out

memory_check:
	valgrind --leak-check=full ./myHashtab.out
