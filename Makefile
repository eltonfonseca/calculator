CC=gcc
NULL=/dev/null
EXEC=calculator
FOLDER_LIB=lib
FOLDER_INCLUDE=include
FLAGS=-Wall
TARGET=src/calculator.c
LIB=lib/operators.a
OBJS=lib/sum.o lib/multiply.o lib/division.o lib/minus.o
SOURCES=src/division.c src/minus.c src/multiply.c src/sum.c

all: $(EXEC)

$(FOLDER_LIB):
	@rm -rf lib 
	@mkdir lib 

$(OBJS): $(FOLDER_LIB)

lib/%.o: src/%.c
	@$(CC) $(FLAGS) -o $@ -c $<  

$(LIB): $(OBJS)
	@ar rc $@ $^ 
	@ranlib $@ 
	@rm $(OBJS) 

$(EXEC): $(TARGET) $(LIB)
	@$(CC) $(FLAGS) -I./$(FOLDER_INCLUDE) -L./$(FOLDER_LIB) -o $@ $^ 

.PHONY: clean

clean: 
	@rm -rf $(EXEC) $(LIB)