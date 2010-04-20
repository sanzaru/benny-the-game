#ifndef __TIMER_H__
#define __TIMER_H__

#include "general.h"

/* Timer class */
class Timer{
	public:
		struct time{
			unsigned int sec;
		}tm;

		Timer();
		int retSec();
	protected:
};

/* Function prototypes */
SDL_Surface* DrawTime(TTF_Font *font, SDL_Rect rect, int sec);
#endif
