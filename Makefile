CC=gcc
EXEC=calculator
FOLDER_LIB=lib
FLAGS=-Wall
TARGET=src/calculator.c
OBJS=lib/sum.o lib/multiply.o lib/division.o lib/minus.o
SOURCES=src/division.c src/minus.c src/multiply.c src/sum.c

all: $(EXEC)

$(FOLDER_LIB):
	rm -rf lib
	mkdir lib

$(OBJS): $(FOLDER_LIB)

lib/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC): $(TARGET) $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

.PHONY: clean

clean: 
	rm -rf $(EXEC) $(OBJS)