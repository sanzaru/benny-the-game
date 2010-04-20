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

TTF_Font *theFont;
SDL_Color scorefontcolor = {255,0,0};

/* Load a Font */
TTF_Font *LoadText(char *theTxt)
{
	theFont = TTF_OpenFont(theTxt, 16);
	if (theFont){
		printf("\n\tText: %s loaded sucessfully...\n", theTxt);
		return theFont;
	}
	else{
		printf("\n\tText: %s cannot be loaded...\n\n", theTxt);
	}
}


/* Draw integer */
SDL_Surface *DrawInt(TTF_Font *font, SDL_Rect rect, int myTxt, char *beginTxt, char *endTxt)
{
	SDL_Surface *surface;
	char buffer[255];
	sprintf(buffer,"%s %d %s",beginTxt,myTxt,endTxt);
	
	surface = TTF_RenderText_Solid(font,buffer,scorefontcolor);
	return surface;
}


/* Draw float */
SDL_Surface *DrawFloat(TTF_Font *font, SDL_Rect rect, float myTxt, char *beginTxt, char *endTxt)
{
	SDL_Surface *surface;
	char buffer[255];
	sprintf(buffer,"%s %0.f %s",beginTxt,myTxt,endTxt);
	
	surface = TTF_RenderText_Solid(font,buffer,scorefontcolor);
	return surface;
}
