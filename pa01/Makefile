# Makefile
CXX_FLAG = --std=c++11 -g

all: game

game: main.cpp cards.cpp utility.cpp
	g++ main.cpp cards.cpp cards.h utility.cpp utility.h $(CXX_FLAG) -o game

tests: tests.cpp cards.cpp
	g++ tests.cpp cards.cpp cards.h $(CXX_FLAG) -o tests
	./tests

clean:
	rm -f game tests *.o