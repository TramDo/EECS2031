CC=gcc
CFLAGS=-lWarn -pedantic
LDFLAGS=-lwiringPi


tester: tester.o libmyifttt.a
	$(CC) tester.o -L. -lmyifttt -lcurl -o tester

alarm: alarm.o
	$(CC) alarm.o $(LDFLAGS) -o alarm

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

alarm.o: 	irtester.c
	$(CC) -c -ansi Wall -pedantic

all:	tester alarm

clean:
	rm tester *.o
