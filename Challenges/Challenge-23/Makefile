FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc23: pc23.o
	g++ $(FLAGS) -o pc23 pc23.o

pc23.o: pc23.cpp
	g++ -c $(FLAGS) pc23.cpp -o pc23.o

clean:
	del *.o
