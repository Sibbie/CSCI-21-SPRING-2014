FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc19: pc19.o SLNode.o SList.o
	g++ $(FLAGS) -o pc19 pc19.o SLNode.o SList.o

pc19.o: pc19.cpp
	g++ -c $(FLAGS) pc19.cpp -o pc19.o

SLNode.o: SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

SList.o: SList.cpp
	g++ -c $(FLAGS) SList.cpp -o SList.o

clean:
	del *.o

cleanall:clean
	del Project3Driver.exe
