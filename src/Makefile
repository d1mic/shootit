PROGRAM = main
CC      = gcc
CFLAGS  = -g -ansi -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib 
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o hoop.o ball.o field.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) ball.o hoop.o main.o field.o $(LDLIBS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM)

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
