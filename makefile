CFLAGS=-g -Wall
CC=gcc
objects= main.o list.o utils.o patient.o load.o sort.o date.o string.o
prog: $(objects)
	$(CC) $(CFLAGS) -o prog $^ -lm

$(objects):

test:
	gcc -g -o prog main.c

all:
<<<<<<< HEAD
	gcc -g -o prog main.c date.c patient.c utils.c listElem.c listArrayList.c loadp.c sort.c

=======
	gcc -g -o prog main.c date.c patient.c utils.c listElem.c listArrayList.c loadp.c
>>>>>>> 135c963576168064c39fd14a9d85fc96b5106a05
clean:
	rm -f prog

list.o: list.h

utils.o: utils.h

patient.o: patient.h

load.o: load.h

sort.o: sort.h

date.o: date.h

string.o:cadeia_carateres.h
