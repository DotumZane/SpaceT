CC = g++
OBJS = main.o
CFLAGS = -Wall -c
LFLAGS = -Wall

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o SpaceT -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean :
	rm -f *.o SpaceT
