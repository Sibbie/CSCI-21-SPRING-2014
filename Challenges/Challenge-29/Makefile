FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

all: pc29.o treasurechest.o
	g++ $(FLAGS) -o pc29.exe pc29.o treasurechest.o

pc29.o: pc29.cpp
	g++ -c $(FLAGS) pc29.cpp -o pc29.o

treasurechest.o: treasurechest.cpp treasurechest.h
	g++ -c $(FLAGS) treasurechest.cpp -o treasurechest.o

clean:
	del *.o

cleanall:clean
	del *.exe
