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
#ifndef __SOUND_H__
#define __SOUND_H__

#include "general.h"

#include "sound.cpp"

/* AudioVariables */
Mix_Chunk 	*start,
			*snd_ouch,
			*snd_pop,
			*snd_win,
			*snd_girls,
			*snd_yeah,
			*snd_byebye;

/* Music variable */
Mix_Music 	*music;

static int 		channel;
char 		*f_music="snd/limassol.ogg", /* Music file */
			*file="snd/ouch.wav";

/* Audio Options */
int audio_rate = 88200;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 8192;

/* Function prototypes */
Mix_Chunk* LoadSnd(char *snd);
#endif
