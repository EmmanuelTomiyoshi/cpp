CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

all: contact

contact: main.o
	$(CC) $(CFLAGS) main.o -o contact

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o contact