FLAGS = -Wall -Wextra -Werror -pedantic

pc17: pc17.o SLNode.o
	g++ $(FLAGS) -o pc17 pc17.o SLNode.o

pc17.o: pc17.cpp
	g++ -c $(FLAGS) pc17.cpp -o pc17.o

SLNode.o: SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
