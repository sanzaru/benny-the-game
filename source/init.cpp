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

void initGame()
{
	/*Initialze SDL with video and audio */
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("Error loading SDL: %d", SDL_GetError());
		exit(1);
	}
	else
	{
		printf("\tSDL initialized...\n\n");
	}

	/* Initialize SDL Fonts */
	TTF_Init();
	if (!TTF_WasInit())
	{
		printf("\n\tTTF cannot be loaded...\n");
		exit(EXIT_FAILURE);
	}
	else if (TTF_WasInit())
	{
		printf("\tTTF Initialized...\n\n");
	}

	/* Quit SDL at exit */
	atexit(SDL_Quit);

	/* Set Window caption and icon */
	SDL_WM_SetCaption("BennySDL", "");
	SDL_WM_SetIcon(SDL_LoadBMP("gfx/icon.bmp"),NULL);
}
