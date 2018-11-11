#im no makefile expert

m?=anagram_adv
CFLAGS = -Werror -Wall -std=gnu++17
all:
	g++ $(CFLAGS) $(m).cc -o $(m)
