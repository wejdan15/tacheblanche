#ifndef SAUV_H_INCLUDED
#define SAUV_H_INCLUDED
#include "pres.h"
struct Boutton
{
    SDL_Surface* Img[2];
    SDL_Rect Pos;
       Mix_Chunk *son;
};
typedef struct Boutton Boutton;


void sauvegarder (personne p, char * nomfichier);
int charger (personne *p,  char * nomfichier);

#endif
