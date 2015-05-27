CC = g++ -std=c++11
OBJS = main.o tetrisBlocks.o tetrisGameManager.o
CFLAGS = -Wall -c
LFLAGS = -Wall

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o SpaceT -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

tetrisBlocks.o : src/tetrisBlocks.cpp include/tetrisBlocks.h
	$(CC) $(CFLAGS) src/tetrisBlocks.cpp

tetrisGameManager.o : src/tetrisGameManager.cpp include/tetrisGamemanager.h
	$(CC) $(CFLAGS) src/tetrisGameManager.cpp

clean :
	rm -f *.o SpaceT
