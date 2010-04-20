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
#include "general.h"

/*Class Functions
SDL_Surface* LoadBtn(SDL_Surface *name, SDL_Surface *surface, char *image, SDL_Rect rect){
	SDL_Surface *tmp;
	tmp=SDL_LoadBMP(image);
	name=SDL_DisplayFormat(tmp);
	if (!name){
		printf("\t\nButton (%s) cannot be loaded...\n", file);
		exit(1);
	}
	else{
		printf("\n\tButton (%s) loaded successfully...\n", file);
	}
	SDL_FreeSurface(tmp);
}
*/


/* Load a GUI screen */
SDL_Surface* LoadGUI(SDL_Surface *surface)
{
	surface = SDL_SetVideoMode(800,600,16,SDL_HWSURFACE | SDL_DOUBLEBUF);// | SDL_FULLSCREEN);
	if (!surface){
		printf("\n\tGUI cannot be loaded...\n");
		exit(1);
	}
	else{
		printf("\n\tGUI loaded successfully...\n");
		return surface;
	}
}


/* Load a button for the menu */
SDL_Surface *LoadBtn(SDL_Surface *name, char *file, SDL_Rect rect)
{
	SDL_Surface *tmp;

	tmp = IMG_Load(file);
	name = SDL_DisplayFormat(tmp);
	if (!name){
		printf("\t\nButton (%s) cannot be loaded...\n", file);
		exit(-1);
	}
	else{
		printf("\n\tButton (%s) loaded successfully...\n", file);
		return name;
	}
	SDL_FreeSurface(tmp);
}


/* Draw the Button */
void DrawButton(SDL_Surface *image, SDL_Surface *surface, SDL_Rect rect){
	SDL_BlitSurface(image,NULL,surface,&rect);
}
