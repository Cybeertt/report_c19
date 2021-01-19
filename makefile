CFLAGS=-g -Wall
CC=gcc
objects= main.o mapArrayList.o mapElem.o listArrayList.o utils.o patient.o loadp.o loadr.o date.o commands.o listElem.o region.o stringCode.o
prog: $(objects)
	$(CC) $(CFLAGS) -o prog $^ -lm

test:
	$(CC) -g -o prog main.c 

all:
	$(CC) -g -o prog main.c commands.c date.c patient.c utils.c listElem.c listArrayList.c loadp.c loadr.c mapElem.c mapArrayList.c region.c utils.c stringCode.c

clean:
	rm -f prog $(objects)

listArrayList.o: list.h

listElem.o: listElem.h

mapArrayList.o: map.h

mapElem.o: mapElem.h

utils.o: utils.h

patient.o: patient.h

loadr.o: loadr.h

loadp.o: loadp.h

date.o: date.h

commands.o: commands.h

stringCode.o: stringCode.h
