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
#ifndef GUI_H_
#define GUI_H_

#include "gui.cpp"

//Set Variables
SDL_Surface *gui_screen,
			*gui_backgr,
			*opt_menu,
			*tmp_button,
			*start_button,
			*start_button02,
			*opt_button,
			*opt_button02,
			*radio_button,
			*radio_cross,
			*quit_button,
			*quit_button02;

SDL_Rect 	rect_btn01, 
			rect_btn02, 
			rect_btn03;

/*
	NOT YET USED
*/
class gui_btn{
	SDL_Rect rect_btn;
	int xPos;
	int yPos;
	public:
		SDL_Surface* LoadBtn(SDL_Surface *name, SDL_Surface *surface, char *image, SDL_Rect rect);
		void DrawButton(SDL_Surface *image, SDL_Surface *surface, SDL_Rect rect);
};

/* Function Prototypes */
SDL_Surface* LoadGUI(SDL_Surface *surface);
SDL_Surface *LoadBtn(SDL_Surface *name, char *file, SDL_Rect rect);
void DrawButton(SDL_Surface *image, SDL_Surface *surface, SDL_Rect rect);
#endif
