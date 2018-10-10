P=$(m)
#im no makefile expert
CFLAGS=-Wall -Werror -Wno-unused-variable -Wno-unused-value  -std=gnu++17 -g
OBJECTS= anagram_base.o anagram_main.o anagram_wordgen.o
dir=sources
all:$(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o $(P)
	rm *.o

anagram_base.o:
	g++ $(CFLAGS) -c $(dir)/anagram_base.cc -o anagram_base.o

anagram_main.o:
	g++ $(CFLAGS) -c $(dir)/anagram_main.cc -o anagram_main.o

anagram_wordgen.o:
	g++ $(CFLAGS) -c $(dir)/anagram_wordgen.cc -o anagram_wordgen.o
