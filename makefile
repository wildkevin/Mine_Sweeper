mine_sweeper.out: main.o board.o gameover.o getinput.o initial.o
	gcc -g -Wall -Werror -o mine_sweeper.out main.o board.o gameover.o getinput.o initial.o
main.o: main.c board.h gameover.h getinput.h initial.h
	gcc -g -Wall -Werror -c main.c
board.o: board.c board.h initial.h
	gcc -g -Wall -Werror -c board.c
gameover.o: gameover.c gameover.h initial.h
	gcc -g -Wall -Werror -c gameover.c
getinput.o: getinput.c getinput.h initial.h
	gcc -g -Wall -Werror -c getinput.c
initial.o: initial.c initial.h
	gcc -g -Wall -Werror -c initial.c
clean:
	rm -fr *.o *.out
