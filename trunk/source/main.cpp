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

#include "main.h"
#include "fonts.h"
#include "gui.h"
#include "sprite.h"
#include "timer.h"
#include "gfxFunctions.h"
#include "sound.h"

//Global Variables
bool done=false,menu_on,opt_on;

//Function prototypes
bool optMenu();
int theMenu();
int Quit(int sender);
void startRecord();




/*
	Quit Sequence

	1 = Main Menu Screen -- 2 = Options Menu Screen -- 3  = Game Exit

*/
int Quit(int sender){
	if (sender == 1){
		if( start_button )
			SDL_FreeSurface(start_button);
		if( start_button02 )
			SDL_FreeSurface(start_button02);
		if( opt_button )
			SDL_FreeSurface(opt_button);
		if( opt_button02 )
			SDL_FreeSurface(opt_button02);
		if( quit_button )
			SDL_FreeSurface(quit_button);
		if( quit_button02 )
		SDL_FreeSurface(quit_button02);
		if( gui_backgr )
			SDL_FreeSurface(gui_backgr);
		if( gui_screen )
			SDL_FreeSurface(gui_screen);
		menu_on=true;
// 		//Print Frames & Time
// 			system("clear");
// 			printf("\n\tFrames: %0.f\n\n", frame);
// 			printf("\n\tTime: %d sec.\n\n", sec);
// 			printf("\n\tFPS: %0.f\n\n", frame/(SDL_GetTicks()/1000));
// 			printf("\n\t==================\n");
// 			printf("\n\t%s's Score: %d\n",usrName, (apple_count));
// 			printf("\n\t==================\n\n");
		exit(0);
	}
	/*else if (sender == 2){
		SDL_FreeSurface(radio_button);
		SDL_FreeSurface(radio_cross);
		SDL_FreeSurface(quit_button);
		//SDL_FreeSurface(gui_backgr);
		SDL_FreeSurface(opt_menu);
		opt_on=true;
		theMenu();
	}*/
	else if (sender == 3){
		
		if( theBack )
			SDL_FreeSurface(theBack);
		for (int i=0; i < 4;i++){
			if( benny[i] )
				SDL_FreeSurface(benny[i]);
		}
		if( theBenny )
			delete theBenny;
		if( enemy ){
			SDL_FreeSurface(enemy);
			for(int i=0; i<ENEMY_COUNT;i++)
				delete Enemy[i];
		}

		if( my_timer )
			delete my_timer;
		if( apple_timer )
			delete apple_timer;
		if( Apple )
			delete Apple;

		//FreeSounds
		if( start )
			Mix_FreeChunk(start);
		if( snd_ouch )
			Mix_FreeChunk(snd_ouch);
		if( snd_girls )
			Mix_FreeChunk(snd_girls);
		if( snd_win )
			Mix_FreeChunk(snd_win);
		if( snd_pop )
			Mix_FreeChunk(snd_pop);
		if( snd_yeah )
			Mix_FreeChunk(snd_yeah);
		if( snd_byebye )
			Mix_FreeChunk(snd_byebye);
		if( music )
			Mix_FreeMusic(music);

		Mix_CloseAudio();
		if( appl_count )
			SDL_FreeSurface(appl_count);
		if( sur_apple )
			SDL_FreeSurface(sur_apple);
		if( main_screen )
			SDL_FreeSurface(main_screen);

		//Print Frames & Time
		system("clear");
		//printf("\n\tFrames: %0.f\n\n", frame);
		printf("\n\t===================\n");
		printf("\n\t===== RESULTS =====\n");
		printf("\n\t===================\n\n");
		printf("\n\tTime: %d sec.\n\n", sec);
		printf("\n\tFPS: %0.f\n\n", frame/sec);
		printf("\n\t===================\n");
		printf("\n\t%s's Score: %d\n",usrName, (apple_count));
		printf("\n\t===================\n\n");
		exit(0);
	}
}

/*
	Start Recording
*/
void startRecord(){
	FILE *recFile;
	int	lastX = theBenny->GetRect()->x,
		lastY = theBenny->GetRect()->y,
		newX = 0,
		newY = 0;
	
	recFile  = fopen("record", "w");
	fprintf(recFile,"%d%d\n", lastX, lastY);
	lastX = theBenny->GetRect()->x;
	lastY = theBenny->GetRect()->y;


	if (lastX != newX)
		fprintf(recFile,"%d%d\n", newX, newY);
		newX = lastX;
		newY = lastY;
	
	newX = theBenny->GetRect()->x;
	newY = theBenny->GetRect()->y;
	
	if (done)
		fclose(recFile);
}




/*
	LOAD MENU
*/
int theMenu(){
	SDL_Event event;
	keys=SDL_GetKeyState(NULL);

	rect_btn01.x=200;
	rect_btn01.y=100;
	rect_btn02.x=200;
	rect_btn02.y=200;
	rect_btn03.x=200;
	rect_btn03.y=300;

	SDL_ShowCursor(1);
	//Loading GUI Surface
	gui_screen=LoadSurface(gui_screen,fullscreen,SCRHEIGHT,SCRWIDTH);
	gui_backgr=IMG_Load("gfx/ocean.png");
	SDL_BlitSurface(gui_backgr,NULL,gui_screen,NULL);
	//Loading Buttons
	start_button=LoadBtn(start_button,"gfx/btnStart.png",rect_btn01);
	start_button02=LoadBtn(start_button02,"gfx/btnStart02.png",rect_btn01);
	opt_button=LoadBtn(opt_button,"gfx/btnOpt.png",rect_btn02);
	opt_button02=LoadBtn(opt_button02,"gfx/btnOpt02.png",rect_btn02);
	quit_button = LoadBtn(quit_button, "gfx/btnQuit.png", rect_btn03);
	quit_button02 = LoadBtn(quit_button02,"gfx/btnQuit02.png",rect_btn03);
	//DrawButton
	DrawButton(start_button, gui_screen, rect_btn01);
	DrawButton(opt_button, gui_screen, rect_btn02);
	DrawButton(quit_button, gui_screen, rect_btn03);
	//Set Rects
	rect_btn01.w=start_button->w;
	rect_btn01.h=start_button->h;
	rect_btn02.w=opt_button->w;
	rect_btn02.h=opt_button->h;
	rect_btn03.w=quit_button->w;
	rect_btn03.h=quit_button->h;
	//Main Loop
	while (!menu_on){
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT:
					
					break;
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(&mouseX,&mouseY);
					//Handle Start Button
					if (mouseX<=(rect_btn01.x+rect_btn01.w) && mouseY<(rect_btn01.y+rect_btn01.h) && mouseX>rect_btn01.x && mouseY>rect_btn01.y){
						DrawButton(start_button02,gui_screen,rect_btn01);
					}
					else{
						DrawButton(start_button,gui_screen,rect_btn01);
					}
					//Handle Options Button
					if (mouseX<=(rect_btn02.x+rect_btn02.w) && mouseY<(rect_btn02.y+rect_btn02.h) && mouseX>rect_btn02.x && mouseY>rect_btn02.y){
						DrawButton(opt_button02,gui_screen,rect_btn02);
					}
					else{
						DrawButton(opt_button,gui_screen,rect_btn02);
					}
					//Handle Quit Button
					if (mouseX<=(rect_btn03.x+rect_btn03.w) && mouseY<(rect_btn03.y+rect_btn03.h) && mouseX>rect_btn03.x && mouseY>rect_btn03.y){
						DrawButton(quit_button02,gui_screen,rect_btn03);
					}
					else{
						DrawButton(quit_button,gui_screen,rect_btn03);
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
						//When Click Start Button
						if (mouseX<=(rect_btn01.x+rect_btn01.w) && mouseY<(rect_btn01.y+rect_btn01.h) && mouseX>rect_btn01.x && mouseY>rect_btn01.y){
							SDL_FreeSurface(start_button);
							SDL_FreeSurface(start_button02);
							SDL_FreeSurface(opt_button);
							SDL_FreeSurface(opt_button02);
							SDL_FreeSurface(quit_button);
							SDL_FreeSurface(quit_button02);
							SDL_FreeSurface(gui_backgr);
							SDL_FreeSurface(gui_screen);
							load_game();
						}
						//When Click Options Button
						if (mouseX<=(rect_btn02.x+rect_btn02.w) && mouseY<(rect_btn02.y+rect_btn02.h) && mouseX>rect_btn02.x && mouseY>rect_btn02.y){
							/*SDL_FreeSurface(start_button);
							SDL_FreeSurface(start_button02);
							SDL_FreeSurface(opt_button);
							SDL_FreeSurface(opt_button02);
							SDL_FreeSurface(quit_button);
							SDL_FreeSurface(quit_button02);
							SDL_FreeSurface(gui_backgr);
							SDL_FreeSurface(gui_screen);
							optMenu();*/
						}
						//When Click Quit Button
						if (mouseX<=(rect_btn03.x+rect_btn03.w) &&mouseY<(rect_btn03.y+rect_btn03.h)&& mouseX>rect_btn03.x && mouseY>rect_btn03.y){
							Quit(1);
							break;
						}
			}
		}
		if (keys[SDLK_ESCAPE]){
			Quit(1);
		}
		if (keys[SDLK_s]){
			SDL_FreeSurface(start_button);
			SDL_FreeSurface(start_button02);
			SDL_FreeSurface(opt_button);
			SDL_FreeSurface(opt_button02);
			SDL_FreeSurface(quit_button);
			SDL_FreeSurface(quit_button02);
			SDL_FreeSurface(gui_backgr);
			SDL_FreeSurface(gui_screen);
			load_game();
		}
		if(keys[SDLK_f]){
			SDL_WM_ToggleFullScreen(gui_screen);
			if (fullscreen==true){
				fullscreen=false;
			}
			else{
				fullscreen=true;
			}
		}
		SDL_UpdateRect(gui_screen,0,0,0,0);
	}
}




/*
	OPTIONS MENU
*/
bool optMenu(){
	SDL_Event event;
	keys=SDL_GetKeyState(NULL);

	rect_btn01.x=200;
	rect_btn01.y=100;
	rect_btn02.x=0;
	rect_btn02.y=0;
	rect_btn03.x=200;
	rect_btn03.y=300;

	SDL_ShowCursor(1);
	//LOading GUI Surface
	opt_menu=LoadSurface(opt_menu,fullscreen,SCRHEIGHT,SCRWIDTH);
	//gui_backgr=SDL_LoadBMP("gfx/ocean.bmp");
	//SDL_BlitSurface(gui_backgr,NULL,gui_screen,NULL);
	//Loading Buttons
	radio_button=LoadBtn(radio_button,"gfx/btnRadio.png",rect_btn01);
	SDL_SetColorKey(radio_button, SDL_SRCCOLORKEY, SDL_MapRGB(radio_button->format, 255,0,234));
	radio_cross=LoadBtn(radio_cross,"gfx/btnCross.png",rect_btn02);
	SDL_SetColorKey(radio_cross, SDL_SRCCOLORKEY, SDL_MapRGB(radio_cross->format, 255,0,234));
	quit_button = LoadBtn(quit_button,"gfx/btnQuit.png",rect_btn03);
	quit_button02 = LoadBtn(quit_button02,"gfx/btnQuit02.png",rect_btn03);
	//DrawButton
	DrawButton(radio_button, opt_menu, rect_btn01);
	DrawButton(radio_cross, opt_menu, rect_btn02);
	DrawButton(quit_button, opt_menu, rect_btn03);
	//Set Rects
	rect_btn01.w=radio_button->w;
	rect_btn01.h=radio_button->h;
	rect_btn02.w=radio_cross->w;
	rect_btn02.h=radio_cross->h;
	rect_btn03.w=quit_button->w;
	rect_btn03.h=quit_button->h;
	//Main Loop
	while (opt_on){
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT:
					Quit(2);
					break;
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(&mouseX,&mouseY);
					//Handle Start Button
					if (mouseX<=(rect_btn01.x+rect_btn01.w) && mouseY<(rect_btn01.y+rect_btn01.h) && mouseX>rect_btn01.x && mouseY>rect_btn01.y){
						DrawButton(start_button02,gui_screen,rect_btn01);
					}
					else{
						DrawButton(start_button,gui_screen,rect_btn01);
					}
					//Handle Options Button
					if (mouseX<=(rect_btn02.x+rect_btn02.w) && mouseY<(rect_btn02.y+rect_btn02.h) && mouseX>rect_btn02.x && mouseY>rect_btn02.y){
						DrawButton(radio_cross,gui_screen,rect_btn02);
					}
					else{
						DrawButton(opt_button,gui_screen,rect_btn02);
					}
					//Handle Quit Button
					if (mouseX<=(rect_btn03.x+rect_btn03.w) && mouseY<(rect_btn03.y+rect_btn03.h) && mouseX>rect_btn03.x && mouseY>rect_btn03.y){
						DrawButton(quit_button02,gui_screen,rect_btn03);
					}
					else{
						DrawButton(quit_button,gui_screen,rect_btn03);
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
						//When Click Start Button
						if (mouseX<=(rect_btn01.x+rect_btn01.w) && mouseY<(rect_btn01.y+rect_btn01.h) && mouseX>rect_btn01.x && mouseY>rect_btn01.y){
							SDL_FreeSurface(radio_button);
							SDL_FreeSurface(radio_cross);
							SDL_FreeSurface(quit_button);
							//SDL_FreeSurface(gui_backgr);
							SDL_FreeSurface(opt_menu);
							load_game();
						}
						//When Click Options Button
						if (mouseX<=(rect_btn02.x+rect_btn02.w) && mouseY<(rect_btn02.y+rect_btn02.h) && mouseX>rect_btn02.x && mouseY>rect_btn02.y){
							opt_on=true;
							SDL_FreeSurface(radio_button);
							SDL_FreeSurface(radio_cross);
							SDL_FreeSurface(quit_button);
							//SDL_FreeSurface(gui_backgr);
							SDL_FreeSurface(opt_menu);
							//optMenu();
							load_game();
						}
						//When Click Quit Button
						if (mouseX<=(rect_btn03.x+rect_btn03.w) &&mouseY<(rect_btn03.y+rect_btn03.h)&& mouseX>rect_btn03.x && mouseY>rect_btn03.y){
							Quit(2);
							break;
						}
			}
		}
		if (keys[SDLK_ESCAPE]){
			Quit(2);
		}
		if (keys[SDLK_s]){
			SDL_FreeSurface(start_button);
			SDL_FreeSurface(start_button02);
			SDL_FreeSurface(opt_button);
			SDL_FreeSurface(opt_button02);
			SDL_FreeSurface(quit_button);
			SDL_FreeSurface(quit_button02);
			SDL_FreeSurface(gui_backgr);
			SDL_FreeSurface(gui_screen);
			load_game();
		}
		if(keys[SDLK_f]){
			SDL_WM_ToggleFullScreen(gui_screen);
			if (fullscreen==true){
				fullscreen=false;
			}
			else{
				fullscreen=true;
			}
		}
		SDL_UpdateRect(gui_screen,0,0,0,0);
	}
}




/*
	Load general things for the game
*/
void load_game(void)
{
	//Load Surface
	main_screen=LoadSurface(main_screen,fullscreen,SCRHEIGHT,SCRWIDTH);
	if (main_screen != NULL){
		printf("\tMain Screen loaded successfully...\n\n");
	}
	else{
		printf("\tError loading Main Screen...\n\n");
		exit(1);
	}
	//LOAD BACKGROUND
	theBack = LoadGfx(theBack, back_pic);
	DrawGfx(theBack, main_screen, rect_main);

	//LOAD TEXT
	scoreFont=LoadText("fonts/Agent Orange.ttf");
	if (scoreFont){
		printf("\tscores loaded successfully...\n\n");
	}
	else{
		printf("\tscores cannot be loaded...\n\n");
	}
	fpsFont=LoadText("fonts/Agent Orange.ttf");
	if (fpsFont){
		printf("\tFPS-Font loaded successfully...\n\n");
	}
	else{
		printf("\tFPS-Font cannot be loaded...\n\n");
	}
	
	//Load Benny
	benny[0]=LoadGfx(benny[0], "gfx/benny0.png");
	benny[1]=LoadGfx(benny[1], "gfx/benny1.png");
	benny[2]=LoadGfx(benny[2], "gfx/benny2.png");
	benny[3]=LoadGfx(benny[3], "gfx/benny3.png");
	for (int i=0;i<3;i++){
		if (benny[i]!=NULL){
			printf("\n\tPicture of Benny[%d] loaded successfully...\n", i);
		}
	}
	theBenny = new Sprite(benny[0],200,200);

	//Load Enemy
	enemy=LoadGfx(enemy,"gfx/enemy.png");
	if (enemy){
		printf("\n\tPicture of Enemy successfully loaded...\n");
	}
	for(int i=0; i<ENEMY_COUNT; i++)
	{
		Enemy[i] = new Sprite(enemy, (rand()%640)-30, (rand()%480)-30);
		if( Enemy[i] )
			printf("\n\tEnemy %d successfully loaded...\n", i);
	}
	
	/*Load Apple Menu
	m_appleX=5;
	m_appleY=25;

	for (int i=0;i<(apple_count);i++){
		apple_menu[i]=LoadGfx( apple_menu[i],"gfx/apfel.png");
		Menu_Apple[i]= new Sprite(apple_menu[i],m_appleX,m_appleY);
		m_appleX+=apple_menu[i]->w+5;
		printf("\tApple #%d loaded successfully...\n", i);
	}
	printf("\n");*/
	
	/*
		Varify init Sounds & Music
	 */
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
	{
		printf("\n\tSound cannot be initialized! (%s)\n", SDL_GetError());
		exit(-1);
	}
	else
		printf("\n\tSound initalized...\n");
	
	//Load Sounds
	snd_byebye=Mix_LoadWAV("snd/byebyebaby.wav");
	if(snd_byebye)
		printf("\n\tSound byebye loaded...\n");
	else
		printf("\n\tSound byebye cannot be loaded! (%s)\n", SDL_GetError());

	snd_girls=Mix_LoadWAV("snd/girls.wav");
	if(snd_girls)
		printf("\n\tSound girls loaded...\n");
	else
		printf("\n\tSound girls cannot be loaded! (%s)\n", SDL_GetError());
	
	snd_yeah=Mix_LoadWAV("snd/yeah.wav");
	if(snd_yeah)
		printf("\n\tSound yeah loaded...\n");
	else
		printf("\n\tSound yeah cannot be loaded!\n (%s)", SDL_GetError());

	snd_pop=Mix_LoadWAV("snd/pop.wav");
	if(snd_pop)
		printf("\n\tSound Pop loaded...\n");
	else
		printf("\n\tSound Pop cannot be loaded! (%s)\n", SDL_GetError());

	snd_ouch=Mix_LoadWAV(file);
	if(snd_ouch)
		printf("\n\tSound ouch loaded...\n");
	else
		printf("\n\tSound %s cannot be loaded (%s)!\n",file,SDL_GetError());

	start=Mix_LoadWAV("snd/start.wav");
	if(start)
		printf("\n\tSound start loaded...\n\n");
	else
		printf("\n\tSound start cannot be loaded (%s)!\n", file, SDL_GetError());

	//Load Music
	music=Mix_LoadMUS(f_music);
	if(music){
		printf("\n\tMusic %s successfully loaded...\n", f_music);
	}
	else{
		printf("\n\tMusic %s cannot be loaded (%s)!\n", f_music,SDL_GetError());
	}
	if(Mix_PlayingMusic() == 0){
		Mix_PlayMusic(music,0);
	}
	else{
		Mix_FreeMusic(music);
	}
	
	/*
		Load Apple
	*/
	sur_apple = LoadGfx(sur_apple, "gfx/apfel.png");
	if(sur_apple){
		printf("\n\tPicture of Apple loaded successfully...\n");
	}
	else{
		printf("\n\tPicture of Apple cannot be loaded...(%s)\n", SDL_GetError());
	}
	Apple = new Sprite(sur_apple,(rand()%640)-30, (rand()%480)-30);
	if (Apple){
		printf("\n\tApple loaded successfully...\n");
	}
	else{
		printf("\n\tApple cannot be loaded...(%s)\n", SDL_GetError());
	}

	/*
		Load HP-Package
	*/
	sur_hpPkg = LoadGfx(sur_hpPkg,"gfx/healthpk.png");
	if(sur_hpPkg)
		printf("\n\tPicture of HP-Package loaded successfully!\n");
	else
		printf("\n\tError loading HP-Package picture! (%s)\n", SDL_GetError());
	hpPkg = new Sprite(sur_hpPkg,(rand()%640)-30,(rand()%480)-30);
	if (hpPkg)
		printf("\n\tHealth Package loaded successfully!\n");
	else
		printf("\n\tHealth Package could not be loaded! (%s)\n", SDL_GetError());
	hpPkg_timer = new Timer();
	if (hpPkg_timer)
		printf("\n\tHP-Package Timer loaded...\n");
	else
		printf("\n\tHP-Package Timer could not be loaded... (%s)\n", SDL_GetError());

	/* Init Timer */
	my_timer = new Timer();
	if (my_timer){
		printf("\n\tTimer init successfull!\n");
	}
	else{
		printf("\n\tTimer cannot be initialized... (%s)\n", SDL_GetError());
	}

	/* Init Health */
	if (gotCaught !=100){
		gotCaught=100;
	}

	/* Init Scores */
		apple_count=0;

	/* When everything is loaded start the game */
	start_game();
}



/*
	Start the Game
*/
int start_game(void){
	SDL_Event event;
	SDL_Rect rect_enemy, rect_enemy01;
	int enemyX, enemyY;
	int m_appleX, m_appleY;
	keys=SDL_GetKeyState(NULL);
	int lastSec;
	//FPSmanager		fpsManager;

	// Set random Seed, so that the random numbers are not always the same
	srand(65245);

	//Hide MouseCursor
	SDL_ShowCursor(0);
	
	
	/*
		Play start sound
	*/
	if( (channel = Mix_PlayChannel(-1,start,0)) != 0)
	{
		fprintf(stderr,"\n\tERROR Playing start sound --> %s\n", SDL_GetError());
		Quit(3);
	}

	/*********************
	***** Main Loop ******
	*********************/
	while(!done){
		srand(theBenny->GetRect()->x);
		//printf("\n\n\tLETS GO!!!\n\n");
		while(SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT:
					Quit(3);
					break;
			}
		}
		frame++;
		sec = my_timer->retSec();

		//Movement Enemy
			//LEFT
		for(int i=0; i<lvl;++i)
		{
			if (Enemy[i]->GetRect()->x > (theBenny->GetRect()->x) && Enemy[i]->GetRect()-> x>3){
				Enemy[i]->Move(-ENEMYSPEED-i,0);
			}
				//RIGHT
			if (Enemy[i]->GetRect()->x < theBenny->GetRect()->x && Enemy[i]->GetRect()->x < (main_screen->w-Enemy[i]->GetRect()->w)-3){
				Enemy[i]->Move(ENEMYSPEED+i,0);
			}
				//UP
			if (Enemy[i]->GetRect()->y > theBenny->GetRect()->y/*+theBenny->GetRect()->h*/ && Enemy[i]->GetRect()->y > (-Enemy[i]->GetRect()->h+4)){
				Enemy[i]->Move(0,-ENEMYSPEED-i);
			}
				//Down
			if (Enemy[i]->GetRect()->y < theBenny->GetRect()->y){
				Enemy[i]->Move(0,ENEMYSPEED+i);
			}
		}
				
		//Movement Benny
			//Up
		if (keys[SDLK_UP]){
			if (theBenny->GetRect()->y > 4){
				if (theBenny->sprImg != benny[0]){
					theBenny->SetImage(benny[0]);
				}
				theBenny->Move(0,-BENNYSPEED);
			}
		}
			//Right
		if (keys[SDLK_RIGHT]){
			if (theBenny->GetRect()->x < (main_screen->w-theBenny->GetRect()->w)-3){
				if (theBenny->sprImg != benny[1]){
					theBenny->SetImage(benny[1]);
				}
				theBenny->Move(BENNYSPEED,0);
			}
		}
			//Down
		if (keys[SDLK_DOWN]){
			if (theBenny->GetRect()->y < (main_screen->h-theBenny->GetRect()->h-3)){
				if (theBenny->sprImg != benny[2]){
					theBenny->SetImage(benny[2]);
				}
				theBenny->Move(0,BENNYSPEED);
			}
		}
			//Left
		if(keys[SDLK_LEFT]){
			if (theBenny->GetRect()->x > 4 ){
				if (theBenny->sprImg != benny[3]){
					theBenny->SetImage(benny[3]);
				}
				theBenny->Move(-BENNYSPEED,0);
			}
		}

		/*
			COLLISION -> BENNY / ENEMY
		*/
		if (gotCaught > 0 ){
			for(int i=0; i<lvl;i++)
			{
				if( spr_collision(theBenny, Enemy[i]) == 1)
				{
					theBenny->SetPos( rand()%620, rand()%440 );
					gotCaught -= 20;
					if(lvl<5)
						lvl++;

					channel = Mix_PlayChannel(-1, snd_ouch,0);
				}
			}
		}
		else{
			Mix_HaltMusic();
			channel = Mix_PlayChannel(-1, snd_byebye, 0);
			SDL_Delay(9000);
			Quit(3);
		}

		/*
			COLLISION -> BENNY / APPLE
		*/
		if( spr_collision(theBenny, Apple) == 1)
		{
			apple_count+=20;
			channel = Mix_PlayChannel(0,snd_pop,0);
			Apple->SetPos( (rand()%640)-30, (rand()%480)-30);
			ch_pos += 4;
		}

// 		/*
// 			Collision Benny -> HP-Package (+20HP)
// 		*/
// 		if ( (theBenny->GetRect()->x+(theBenny->GetRect()->w/2)) > hpPkg->GetRect()->x){
// 			if ( (theBenny->GetRect()->x+(theBenny->GetRect()->w/2)) < hpPkg->GetRect()->x+hpPkg->GetRect()->w){
// 				if ( (theBenny->GetRect()->y+(theBenny->GetRect()->w/2)) > hpPkg->GetRect()->y){
// 					if ((theBenny->GetRect()->y+(theBenny->GetRect()->w/2)) < hpPkg->GetRect()->y+hpPkg->GetRect()->h){
// 						if (gotCaught < 100){
// 							gotCaught+=5;
// 							Mix_PlayChannel(0,snd_yeah,0);
// 						}
// 						hpPkg->SetPos((rand()%640)-30,(rand()%480)-30);
// 					}
// 				}
// 			}
// 		}

		//Exit Key
		if (keys[SDLK_ESCAPE]){
			Quit(3);
		}
		//Toggle Fullscreen Key
		if (keys[SDLK_f]){
			SDL_WM_ToggleFullScreen(main_screen);
			if (fullscreen==true){
				fullscreen=false;
			}
			else{
				fullscreen=true;
			}
		}
		//Set Sound on/off
// 		if (keys[SDLK_F2]){
// 			if (Mix_PlayMusic(music,0) > 0)
// 				Mix_CloseAudio();
// 			else
// 				//Mix_PlayMusic(music,0);
// 				Mix_FreeMusic(music);
// 		}
		/*Record Key
		FILE *recFile;

		if (keys[SDLK_r]){
			startRecord();
	}*/		
		//Update Screen
		DrawGfx(theBack, main_screen, rect_main);
		/*Draw Apple Menu
		for (int i=0;i<apple_count;i++){
			Menu_Apple[i]->Draw(main_screen);
		}*/
		//Draw Sprites
		theBenny->Draw(main_screen);
		for(int i=0; i<lvl; ++i)
			Enemy[i]->Draw(main_screen);
// 		hpPkg->Draw(main_screen);
// 		if (hpPkg_timer->retSec() >= (rand()%4)+6){
// 			hpPkg->SetPos((rand()%640)-30,(rand()%480)-30);
// 			hpPkg_timer->reset();
// 		}

		/*
			Free the Fonts
		*/
		if( sur_time )
			SDL_FreeSurface(sur_time);
		if( frames )
			SDL_FreeSurface(frames);
		if( caught )
			SDL_FreeSurface(caught);
		if( appl_count )
			SDL_FreeSurface(appl_count);
		if( theFPS )
			SDL_FreeSurface(theFPS);

		//Draw Text
		sur_time=DrawTime(scoreFont,rect_time, my_timer->retSec());
		caught=DrawFloat(scoreFont,rect_caught,gotCaught,"Health: ","");
		rect_caught.x=rect_time.x+rect_time.w+40;
		appl_count=DrawInt(scoreFont,rect_count,apple_count,"Score ", "");
		rect_count.y= rect_time.y+rect_time.h+10;
		theFPS = DrawFloat(scoreFont,rect_fps,(frame/sec),"FPS : ", "");
		rect_fps.x = rect_caught.x;
		rect_fps.y = rect_count.y;
		SDL_SetClipRect(sur_time,&rect_time);
		SDL_BlitSurface(sur_time,NULL,main_screen,&rect_time);
		SDL_BlitSurface(frames,NULL,main_screen,&rect_frames);
		SDL_BlitSurface(caught,NULL,main_screen,&rect_caught);
		SDL_BlitSurface(appl_count,NULL,main_screen,&rect_count);
		SDL_BlitSurface(theFPS,NULL,main_screen,&rect_fps);
		Apple->Draw(main_screen);
		if (my_timer->retSec() == ch_pos ){
			Apple->SetPos( (random()%640)-30, (random()%480)-30);
			ch_pos += 4;
			printf("\n\t%d\n", ch_pos);
		}
		//Update Screenl
		if(SDL_Flip(main_screen) < 0){
			fprintf(stderr,"\n\tError on SDL_Flip() using SDL_UpdateRect() --> %s\n", SDL_GetError());
			SDL_UpdateRect(main_screen,0,0,0,0);
		}
		//SDL_UpdateRect(main_screen,0,0,0,0);
 		SDL_Delay(40);
	}
	return 0;
}



void usage(char *arg)
{
	printf("\nusage %s <options>\n\nTry %s -h for help!\n\n", arg, arg);
	exit(1);
}
void help(char *arg)
{
	printf("\nusage %s <options>\n\nOptions:\n\t-f\tFullscreen\n\t-nf\tNo fullscreen\n\t-h\tShow this screen\n\t-v\tShow version\n\n", arg);
	exit(0);
}



int main(int argc, char *argv[])
{

	fullscreen=false;

	if(argc<2)
		usage(argv[0]);

	if( strcmp(argv[1],"-h") == 0)
	{
		help(argv[0]);
	}
	else if (strcmp(argv[1],"-f") == 0 )
	{
		fullscreen=true;
	}
	else if( strcmp(argv[1],"-nf") == 0){
		fullscreen = false;
	}
	else if(strcmp(argv[1],"-v") == 0)
	{
		printf("\n\"Benny SDL\"\nVersion: %s\n\n", VERSION);
		exit(0);
	}
	else
		usage(argv[0]);

	/**
		little debug
	**/
	if( (argc >= 3) )
		ENEMYSPEED = atoi(argv[2]);
	else
		ENEMYSPEED = 5;

	usrName = getenv("USER");
	
	initGame();
	theMenu();
}
