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

SDL_Surface* LoadSurface(SDL_Surface *name, bool fs,int width, int height)
{
	if (fs==false){
		name=SDL_SetVideoMode(width,height,16,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWACCEL | SDL_PREALLOC);
		return name;
	}
	else{
		name=SDL_SetVideoMode(width,height,16,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_HWACCEL | SDL_PREALLOC);
		return name;
	}
}

SDL_Surface* LoadGfx(SDL_Surface *name, char *file)
{
	SDL_Surface *tmp;
	tmp = IMG_Load(file);
	name = SDL_DisplayFormat(tmp);
	SDL_SetColorKey(name, SDL_SRCCOLORKEY, SDL_MapRGB(name->format, 255,0,234));
	SDL_FreeSurface(tmp);
	if (name){
		printf("\tPicture \"%s\" loaded successfully...\n", file);
		return name;
	}
	else{
		printf("\n\n\tError loading picture (%s) - (%s)!\n", file, SDL_GetError());
		exit(1);
	}
}

void DrawGfx(SDL_Surface *name, SDL_Surface *surface, SDL_Rect rect){
	SDL_SetClipRect(name,&rect);
	SDL_BlitSurface(name,NULL,surface,&rect);
}
