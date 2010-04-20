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
#include "sprite.h"

/**
	Class functions for Class Sprite
**/

/* Constructor function */
Sprite::Sprite(SDL_Surface *new_image, int x, int y)
{
	SetImage(new_image);
	SetPos(x,y);
}

/* Set Image of sprite */
void Sprite::SetImage(SDL_Surface *new_image)
{
	image=new_image;
	sprImg=image;
}

/* Set position of Sprite */
void Sprite::SetPos(int x, int y)
{
	rect.x = x;
	rect.y = y;
}

/* Move Sprite to "move_x" and "move_y" */
void Sprite::Move(int move_x, int move_y)
{
	rect.x += move_x;
	rect.y +=move_y;
}

/* Get edges of Sprite's rect */
SDL_Rect *Sprite::GetRect(void)
{
	return &rect;
}

/* Draw the Sprite on screen */
void Sprite::Draw(SDL_Surface *target)
{
	SDL_BlitSurface(image,NULL,target,&rect);
}

/* Return current image of Sprite */
SDL_Surface* Sprite::GetImage()
{
	return image;
}
/**
	End class functions
**/

/*************************************************
**************************************************
**** REGULAR FUNCTIONS FOR SPRITES *****
**************************************************
*************************************************/

/*
	Collision check for Sprites
	Only the middle of a sprite is a point of collision
*/
int spr_collision(Sprite *S1, Sprite *S2)
{
	if ( (S1->GetRect()->x+(S1->GetRect()->w/2)) > S2->GetRect()->x)
	{
		if ( (S1->GetRect()->x+(S1->GetRect()->w/2)) < S2->GetRect()->x+48)
		{
			if ( (S1->GetRect()->y+(S1->GetRect()->w/2)) > S2->GetRect()->y)
			{
				if ((S1->GetRect()->y+(S1->GetRect()->w/2)) < S2->GetRect()->y+44)
				{
					return 1;
				}
			}
		}
	}
	else
		return 0;
}
