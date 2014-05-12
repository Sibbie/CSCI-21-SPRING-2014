FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

all: pc27.o BSTNode.o BSTree.o
	g++ $(FLAGS) -o pc27.exe pc27.o BSTNode.o BSTree.o

pc27.o: pc27.cpp
	g++ -c $(FLAGS) pc27.cpp -o pc27.o

BSTNode.o: BSTNode.cpp
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

BSTree.o: BSTree.cpp
	g++ -c $(FLAGS) BSTree.cpp -o BSTree.o

clean:
	del *.o

cleanall:clean
	del *.exe
