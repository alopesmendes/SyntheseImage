
#define _DIM2_
#include <g3x.h>

G3Xcolor col[] = {{1.0,0.7,0.2},{0.2,1.0,0.7}};

uchar *map=NULL,*mapend=NULL,*m;
uchar *aux=NULL,*auxend=NULL,*a;
uint   width,height,length,layer;

void Init(void)
{
	/* on récupère le pixmap et ses tailles */
	g3x_GetPixmap(&map,&width,&height,&layer);
	length=layer*width*height;
	mapend=map+length;
	/* on en crée un second de même taille */
	if (!(aux = (uchar*)calloc(length,sizeof(uchar)))) exit(1);

	auxend=aux+length;

	m=map,a=auxend;
	while (m!=mapend) { a-=3; GXcopy(a,m); m+=3;}
	g3x_StaticWrite("hello",10,10,NULL);
}

void Dessin(void)
{
	static i;
	static char msg[16];
	/* arrêt/relance de la boucle : touche <espace> */
	if (!g3x_Running()) return;	
	m=map; a=aux;
	while (m<mapend) { GXcopy(m,a); a+=3; m+=3; }

	sprintf(msg,"frame %3d",i++);
	g3x_Write(msg,200,10,NULL);
	/*g3x_Show();*/
	m=map; a=auxend;
	while (m!=mapend) { a-=3; GXcopy(a,m); m+=3;}
}	

void Liberation(void)
{
	free(aux);
}


int main(void)
{
	/* juste histoire d'avoir une image dans le pixmap... */
	g3x_LoadImage("teapot.jpg");

	/* démarrage sur une fenêtre vide */
	/*! g3x_InitWindow("demo2D",512,512); !*/
	
  g3x_SetDrawFunction(Dessin);	
  g3x_SetExitFunction(Liberation);
	
	Init();
	
	/* c'est glutMainLoop(), en gros */
  g3x_MainStart();
  return 0;
}
