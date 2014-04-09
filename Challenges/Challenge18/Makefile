FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc18: pc18.o SLNode.o SList.o
	g++ $(FLAGS) -o pc18 pc18.o SLNode.o SList.o

pc18.o: pc18.cpp
	g++ -c $(FLAGS) pc18.cpp -o pc18.o

SLNode.o: SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

SList.o: SList.cpp
	g++ -c $(FLAGS) SList.cpp -o SList.o

clean:
	del *.o

cleanall:clean
	del Project3Driver.exe
