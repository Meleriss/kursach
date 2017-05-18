all:
	gcc -fPIC -c Selection.c
	gcc -fPIC -c Heap.c
	gcc -shared -o libsort.so Selection.o Heap.o
	gcc -c main.c
	gcc main.o -L. -lsort -o main -g
