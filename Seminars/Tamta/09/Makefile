CC = gcc

test: sparsestringarray_tests.o sparsestringarray.o
	$(CC) -o tests.out sparsestringarray_tests.o sparsestringarray.o vector.o

clean:
	rm -f sparsestringarray_tests.o sparsestringarray.o tests.out