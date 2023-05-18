#include "sauv.h"

void sauvegarder (personne p,  char * nomfichier)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d\n", p.pos_perso.x, p.pos_perso.y);
	fclose(f);
}

int charger (personne *p,char * nomfichier)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	
	
		fscanf(f,"%hd %hd\n",&p->pos_perso.x,&p->pos_perso.y);
	
	}
	fclose(f);
}

