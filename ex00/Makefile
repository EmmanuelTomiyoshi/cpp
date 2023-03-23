CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

all: megaphone

megaphone: main.o
	$(CC) $(CFLAGS) main.o -o megaphone

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -rf *.o megaphone