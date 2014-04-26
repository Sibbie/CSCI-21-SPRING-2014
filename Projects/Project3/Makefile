FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

all: project3.o DLNode.h DLList.h
	g++ $(FLAGS) -o project3 project3.o

project3.o: project3.cpp DLNode.h DLList.h
	g++ -c $(FLAGS) project3.cpp -o project3.o

clean:
	cmd /C del*.o

clanall: clean
	cmd /C del *.exe
