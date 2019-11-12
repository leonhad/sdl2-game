all: game

clean:
	rm -f *.o game

run: all
	./game

OBJ=main.o

main.o: main.c constants.h

game: $(OBJ)
	gcc $(OBJ) -o game `sdl2-config --libs`

.c.o:
	gcc -c $< -o $@ -std=c99 -Wall `sdl2-config --cflags`