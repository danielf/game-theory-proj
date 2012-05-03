CC=g++
CFLAGS=-Wall

all: input_gen

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

input_gen: input_gen.cpp
	$(CC) $(CFLAGS) input_gen.cpp -o input_gen

clean:
	rm -rf *.o
