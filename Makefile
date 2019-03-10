CC = g++ -c
GG = g++
POST = -Wall -Werror -ansi -pedantic
BST = -lboost_regex
CLIENTS = $(OBJECTS) app_make
OBJECTS = ps7a.o

all: $(CLIENTS)

ps7a.o:	ps7a.cpp
	$(CC) ps7a.cpp $(POST)

app_make: $(OBJECTS)
	$(GG) $(OBJECTS) -o ps7a $(BST)
	
clean:
	rm $(OBJECTS) ps7a
