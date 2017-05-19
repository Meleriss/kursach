all: bin/kursach

.PHONY: all clean mkdir

mkdir:
	mkdir bin build

build/Heap.o: src/Heap.c
	gcc -fPIC -c src/Heap.c -o build/Heap.o

build/Selection.o: src/Selection.c 
	gcc -fPIC -c src/Selection.c -o build/Selection.o

libsort.so: build/Heap.o build/Selection.o
	gcc -shared build/Selection.o build/Heap.o -o libsort.so

build/main.o: src/main.c src/sort.h
	gcc -c src/main.c -o build/main.o

bin/kursach: build/Selection.o build/Heap.o build/main.o libsort.so
	gcc build/main.o -L. -lsort -o bin/kursach -g

clean: 
	rm -rf build bin libsort.so
