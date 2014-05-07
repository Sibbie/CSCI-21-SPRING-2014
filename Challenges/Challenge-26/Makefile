FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

all: pc26.o BSTNode.o BSTree.o
	g++ $(FLAGS) -o pc26.exe pc26.o BSTNode.o BSTree.o

pc26.o: pc26.cpp
	g++ -c $(FLAGS) pc26.cpp -o pc26.o

BSTNode.o: BSTNode.cpp
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

BSTree.o: BSTree.cpp
	g++ -c $(FLAGS) BSTree.cpp -o BSTree.o

clean:
	del *.o

cleanall:clean
	del *.exe
