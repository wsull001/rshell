#targets
CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic

all: main.cpp
	test -d bin || mkdir bin
	g++ $(CC_FLAGS) main.cpp -o bin/rshell


rshell: main.cpp
	test -d bin || mkdir bin
	g++ $(CC_FLAGS) main.cpp -o bin/rshell
clean:
	rm -rf bin



#EXEC = a.out
#SOURCES = $(wildcard *.cpp)
#OBJECTS = $(SOURCES:.cpp=.o)

#build: make_directories $(EXEC)

#make_directories:
#mkdir bin

#$(EXEC): $(OBJECTS)
#	$(CC) $(OBJECTS) -o bin/$(EXEC)
#	$(CC) $(OBJECTS) -o bin/rshell

#%.o: %.cpp
#	$(CC) -c $(CC_FLAGS) $< -o $@

#clean:
#	rm -f $(EXEC) $(OBJECTS)
#	rm -rf bin

