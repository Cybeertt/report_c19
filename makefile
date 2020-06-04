CFLAGS=-g -Wall
CC=gcc
objects= main.o list.o utils.o patient.o
prog: $(objects)
	$(CC) $(CFLAGS) -o prog $^ -lm

$(objects):

test:
	gcc -g -o prog main.c

n1:
	gcc -g -o prog main.c patient.c utils.c listElem.c listArrayList.c
n2:
	gcc -g -o prog main2.c kahootReport.c utils.c listElem.c listArrayList.c
n3:
	gcc -g -o prog main3.c kahootReport.c utils.c listElem.c listArrayList.c
n4:
	gcc -g -o prog main4.c kahootReport.c utils.c listElem.c listArrayList.c
n5:
	#gcc -g -o prog main5.c kahootReport.c utils.c listElem.c listLinkedList.c
	gcc -g -o prog main5.c kahootReport.c utils.c listElem.c listArrayList.c
clean:
	rm -f prog

list.o: list.h

utils.o: utils.h

patient.o: patient.h
