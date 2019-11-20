all: game

clean:
	rm -f *.o game

run: all
	./game

SRCS = main.c

OBJ=main.o

game: $(OBJ)
	gcc $(OBJ) -o game `sdl2-config --libs`

%.o: %.c
	gcc -c $< -o $@ -std=c99 -Wall `sdl2-config --cflags`

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF  ./.depend;

include .depend