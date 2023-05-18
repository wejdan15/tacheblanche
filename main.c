#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "sauv.h"
#include"pres.h"
int main()
{	
		int continuer=1,done=1;
	SDL_Surface *screen;
Boutton b,b1;
//SDL_Surface *botton1=NULL;
//SDL_Surface *botton2=NULL;
//SDL_Rect positionbotton1;
//SDL_Rect positionbotton2;
b.Img[0]=IMG_Load("botton1.png");
b.Img[1]=IMG_Load("charge1.png");
b.Pos.x=600;
b.Pos.y=0;
//positionbotton1.x=600;
//positionbotton1.y=0;
b1.Img[0]=IMG_Load("botton2.png");
b1.Img[1]=IMG_Load("sauv2.png");
b1.Pos.x=600;
b1.Pos.y=200;
//positionbotton2.x=600;
//positionbotton2.y=200;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
 Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

        b.son= Mix_LoadWAV("clic.wav");
	screen=SDL_SetVideoMode(1500,430,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
	
	
	


	background back;
	personne p;
	
	initialiser_background(&back);
	

	initialiserperso(&p);
	
	SDL_Event event;
	
	while (continuer)
	{	

	SDL_PollEvent(&event);
	switch(event.type)
        {

        case SDL_QUIT:
            continuer=0;
            break;
	
	   case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (event.button.x > 600 && event.button.x < 1110 && event.button.y > 0 && event.button.y < 190)
                    {
					    
			 charger(&p,"test.txt");
                    }
                    else if (event.button.x > 600 && event.button.x < 1110 && event.button.y > 200 && event.button.y < 390)
                    {
	  sauvegarder(p,"test.txt");
                   
                    }
                    
                }
                break;


            case SDL_MOUSEMOTION:
                if (event.motion.x > 600 && event.motion.x < 1110 && event.motion.y > 0 && event.motion.y < 190)
                {
                    Mix_PlayChannel(-1,  b.son, 0);
                    SDL_BlitSurface(b.Img[1],NULL,screen,&b.Pos);
                    SDL_Flip(screen);
                }
                else if (event.motion.x > 600 && event.motion.x < 1110 && event.motion.y > 200 && event.motion.y < 390)
                {
                    Mix_PlayChannel(-1,  b.son, 0);
                   SDL_BlitSurface(b1.Img[1],NULL,screen,&b1.Pos);

                    SDL_Flip(screen);
                }
               
                break;
   
	}



		deplacer_perso(&p,event);
		afficher_background(screen,back);
		
SDL_BlitSurface(b.Img[0],NULL,screen,&b.Pos);
SDL_BlitSurface(b1.Img[0],NULL,screen,&b1.Pos);
		afficher_perso(screen,p);
		SDL_Flip(screen);

	}


	free_perso(p);
	SDL_Quit();
 Mix_FreeChunk(b.son);
    Mix_CloseAudio();

	return 1;
}
