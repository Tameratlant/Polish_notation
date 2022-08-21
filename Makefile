CC=gcc -Wall -Werror -Wextra
CFLAGS=-c 
LDFLAGS=
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE1=../build/graph


all:$(SOURCES) $(EXECUTABLE1)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

rebuild:
	rm -rf $(EXECUTABLE1)


clean: 
	rm -rf $(OBJECTS)
	rm -rf *.o

$(EXECUTABLE1):
	$(CC) convert.c stack.c main.c rpneval.c -o $(EXECUTABLE1)
	rm -rf *.o