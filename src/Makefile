all: game

clean:
	rm -f *.o game

run: all
	./game

OBJ=main.o

main.o: main.c

game: $(OBJ)
	gcc $(OBJ) -o game

.c.o:
	gcc -c $< -o $@ -std=c99 -Wall