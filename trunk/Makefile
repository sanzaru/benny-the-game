str = Everything compiled without problems
all:
	gcc -c `sdl-config --cflags` source/main.cpp source/sprite.cpp source/timer.cpp -lrt 
	gcc -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lrt -o BennySDL main.o sprite.o timer.o `sdl-config --sdl-libs`
	clear
	echo $(str)

