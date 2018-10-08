P=$(m)

CFLAGS=-Wall  -Werror -Wno-unused-variable -Wno-unused-value  -std=gnu++17 -g
OBJECTS=

all:
	g++ $(CFLAGS) $(P).cc $(OBJECTS) -o $(P) $(LDLIBS)
