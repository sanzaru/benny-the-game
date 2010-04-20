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
#ifndef __FONTS_H__
#define __FONTS_H__

#include "fonts.cpp"

class Font{
	public:
		Font(TTF_Font *font, int x, int y);
		void SetString(char *str);
		SDL_Surface *DrawText(SDL_Surface *target);
	protected:
		int inp_int[255];
		float inp_float[255];
		char inp_str[255];
		SDL_Rect rect;
		TTF_Font *theFont;
};

/* function prototypes */
TTF_Font *LoadText(char *theTxt);
SDL_Surface *DrawInt(TTF_Font *font, SDL_Rect rect, int myTxt, char *beginTxt, char *endTxt);
SDL_Surface *DrawFloat(TTF_Font *font, SDL_Rect rect, float myTxt, char *beginTxt, char *endTxt);
#endif
