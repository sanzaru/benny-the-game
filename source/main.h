/********************************************************************************************
        Benny - The game
        
        Author: Martin Albrecht <martin.albrecht@javacoffee.de>
        Date: Something like 2004/2005... maybe? ;)
        Website: http://code.javacofee.de
                
DEPENDENCIES:
-------------
        - SDL library with SDL_TTF, SDL_MIXER, SDL_TIMER and SDL_IMAGE 
		  see http://www.libsdl.org/ for more information.

LICENSE:
--------
        This program is free software; you can redistribute it and/or modify it under
        the terms of the GNU General Public License as published by the Free Software
        Foundation; either version 2 of the License, or (at your option) any later version.

        This program is distributed in the hope that it will be useful, but WITHOUT ANY
        WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
        PARTICULAR PURPOSE. See the GNU General Public License for more details.

        You should have received a copy of the GNU General Public License along with this
        program; if not, write to the

        Free Software Foundation, Inc.,
        59 Temple Place, Suite 330,
        Boston, MA 02111-1307, USA.
        
********************************************************************************************/
#ifndef __MAIN_H__
#define __MAIN_H__

#include "init.cpp"
#include "sprite.h"
#include "timer.h"

//Version
#define VERSION "1.0.0a"

//Resolution
#define SCRHEIGHT 640
#define SCRWIDTH 480

/* Speed of Benny, Enemy and the Maximum count
of enemies in the game */
unsigned int	BENNYSPEED = 10,
 			ENEMYSPEED=2,
			ENEMY_COUNT = 3;


/* Surfaces to load */
SDL_Surface	*main_screen,
			*theBack,
			*frames,
			*caught;

/* Fonts to load */
TTF_Font		*scoreFont, 
			*fpsFont;

/* Rects to load */
SDL_Rect 	rect_main,
			rect_scores,
			rect_frames,
			rect_apple[7],
			rect_caught,
			rect_appl;

/* Mouse coordinates and pause variable*/
int mouseX, mouseY;
int pause=0;

//VARIABLES
	Uint8 *keys;
	bool fullscreen=true;
	int sec=0;
	float fps, frame;
	int gotCaught=100;
	unsigned int lvl=1;
	char *usrName;;
		//Define Background Picture
		char *back_pic="gfx/space.png";
		//Benny
		Sprite *theBenny;
		SDL_Surface *benny[4];
		//Enemy
		Sprite *Enemy[5];
		SDL_Surface *enemy;
		//Apple Menu
		Sprite *Menu_Apple[8];
		SDL_Surface *apple_menu[7];
		//Time
		Timer *my_timer;
		SDL_Surface *sur_time;
		SDL_Rect rect_time;
		//Apple
		Sprite *Apple;
		SDL_Surface *sur_apple;
		Timer *apple_timer;
		unsigned int ch_pos = 4;
		int apple_count=0;
		SDL_Surface *appl_count;
		SDL_Rect rect_count;
		//Health Package
		Sprite *hpPkg;
		SDL_Surface *sur_hpPkg;
		Timer *hpPkg_timer;
		//FPS 
		SDL_Surface *theFPS;
		SDL_Rect rect_fps;

/* Function prototypes */
void initGame(void);
void load_game(void);
int start_game(void);
#endif
