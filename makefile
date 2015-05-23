CC = g++
OBJS = main.o
CFLAGS = -Wall -c
LFLAGS = -Wall

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o  

main.o : main.cpp main.h
	$(CC) $(CFLAGS) main.cpp

clean :
	rm -f *.o hello
