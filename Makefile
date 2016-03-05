#targets
CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic

all: src/main.cpp
	test -d bin || mkdir bin
	g++ $(CC_FLAGS) src/main.cpp -o bin/rshell


rshell: src/main.cpp
	test -d bin || mkdir bin
	g++ $(CC_FLAGS) src/main.cpp -o bin/rshell
clean:
	rm -rf bin
