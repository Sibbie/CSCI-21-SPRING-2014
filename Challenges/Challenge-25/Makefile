FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc25: pc25.o BSTNode.o
	g++ $(FLAGS) -o pc25 pc25.o BSTNode.o

pc25.o: pc25.cpp
	g++ -c $(FLAGS) pc25.cpp -o pc25.o

BSTNode.o: BSTNode.cpp
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	del *.o

cleanall:clean
	del *.exe
