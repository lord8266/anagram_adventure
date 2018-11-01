P=anagram
#im no makefile expert
all:
	cd sources && make
	mv sources/$(P) ./

rebuild: clear all

clear:
	rm sources/*.o
