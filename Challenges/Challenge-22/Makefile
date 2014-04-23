FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc22: pc22.o SList.h
	g++ $(FLAGS) -o pc22 pc22.o

pc22.o: pc22.cpp
	g++ -c $(FLAGS) pc22.cpp -o pc22.o

clean:
	del *.o
