P=anagram
#im no makefile expert
CFLAGS=-Wall -Werror -Wno-unused-variable -Wno-unused-value  -std=gnu++17 -g
OBJECTS= anagram_base.o anagram_main.o anagram_wordgen.o anagram_gameloop.o


all:$(OBJECTS)
	g++  $(CFLAGS) $(OBJECTS) -o $(P)

anagram_base.o: anagram_base.h anagram_base.cc
	g++ $(CFLAGS) -c anagram_base.cc -o anagram_base.o

anagram_main.o: anagram_main.cc anagram_main.h
	g++ $(CFLAGS) -c anagram_main.cc -o anagram_main.o

anagram_wordgen.o: anagram_wordgen.cc anagram_wordgen.h
	g++ $(CFLAGS) -c anagram_wordgen.cc -o anagram_wordgen.o

anagram_gameloop.o:anagram_gameloop.cc anagram_gameloop.h
	g++ $(CFLAGS) -c anagram_gameloop.cc -o anagram_gameloop.o
