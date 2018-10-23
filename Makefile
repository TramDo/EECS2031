<<<<<<< HEAD
CC=gcc
CFLAGS=-lWarn -pedantic
LDFLAGS=-lwiringPi

tester: tester.o libmyifttt.a
	$(CC) tester.o -L. -lmyifttt -lcurl -o tester

alarm: irtester.o libmyifttt.a
	$(CC) irtester.o -L. -lmyifttt -lcurl -lwiringPi -o alarm

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

irtester.o: 	irtester.c ifttt.h
	$(CC) -c -ansi $(CFLAGS) $<

all:	tester alarm

clean:
	rm tester *.o
=======
OBJS=main.o morsecode.o
LDFLAGS=-lwiringPi
CC=gcc
CFLAGS=-Wall -pedantic 

%.o:	%.c morsecode.h
	$(CC) $(CFLAGS) -c -ansi $<


main:	${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o main $(LDFLAGS)
    


>>>>>>> 1283e3aa4a9dfd69d61c8f8da990ffd500e4f3f8
