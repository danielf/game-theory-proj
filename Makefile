CC=g++
CFLAGS=-Wall

all: input_gen

input_gen: input_gen.cpp
	$(CC) $(CFLAGS) input_gen.cpp -o input_gen

clean:
	rm -rf *.o
