FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

all: pc28.o item.o fooditem.o magicitem.o
	g++ $(FLAGS) -o pc28.exe pc28.o item.o fooditem.o magicitem.o

pc28.o: pc28.cpp
	g++ -c $(FLAGS) pc28.cpp -o pc28.o

item.o: item.cpp item.h
	g++ -c $(FLAGS) item.cpp -o item.o

fooditem.o: fooditem.cpp fooditem.h
	g++ -c $(FLAGS) fooditem.cpp -o fooditem.o

magicitem.o: magicitem.cpp magicitem.h
	g++ -c $(FLAGS) magicitem.cpp -o magicitem.o

clean:
	del *.o

cleanall:clean
	del *.exe
