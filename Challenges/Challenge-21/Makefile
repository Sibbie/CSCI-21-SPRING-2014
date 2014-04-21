FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc21: pc21.o box.h
	g++ $(FLAGS) -o pc21 pc21.o

pc21.o: pc21.cpp
	g++ -c $(FLAGS) pc21.cpp -o pc21.o

clean:
	del *.o
