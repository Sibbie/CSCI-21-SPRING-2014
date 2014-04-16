FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc20: pc20.o SLNode.o SList.o
	g++ $(FLAGS) -o pc20 pc20.o SLNode.o SList.o

pc20.o: pc20.cpp
	g++ -c $(FLAGS) pc20.cpp -o pc20.o

SLNode.o: SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

SList.o: SList.cpp
	g++ -c $(FLAGS) SList.cpp -o SList.o

clean:
	del *.o
