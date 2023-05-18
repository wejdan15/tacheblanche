prog:main.o pres.o sauv.o 
	gcc main.o pres.o sauv.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
pres.o:pres.c
	gcc -c pres.c -g
sauv.o:sauv.c
	gcc -c sauv.c -g

