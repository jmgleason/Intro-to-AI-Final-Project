CC = g++
CFLAGS = -std=c++14 -Wall

all: main clean

main.o: BTmain.cpp Backtracking.hpp
	$(CC) -c BTmain.cpp -o $@ $(CFLAGS)

main: main.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main.o