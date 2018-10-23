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
