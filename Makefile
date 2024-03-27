CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17

main: main.o task.o menu.o

main.o: main.cpp
task.o: task.cpp task.hpp
menu.o: menu.cpp menu.hpp

clean:
	@echo "cleaning up"
	$(RM) */*.o main *.o