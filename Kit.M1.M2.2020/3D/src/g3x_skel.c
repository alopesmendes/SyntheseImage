#include <g3x.h>

/*variables globales*/
float orange[4], gris[4]; /*couleur GL = RGBA*/
float ambi, diff, spec, shine, alpha;


/*1 seule fois*/
void init() {
	/*malloc seulement ici*/
	orange[0]=0.8;
	orange[1]=0.6;
	orange[2]=0.2;
	orange[3]=1.0;
	ambi = 0.1;
	diff = 0.7;
	spec = 0.3;
	shine = 0.99;
	alpha = 1.0;
}

/*pasée à atExit()*/
void quit() {
	/*free seulement ici*/
}

void pied() {
	glPushMatrix();
	glTranslated(0, 0, -0.6);
	glScaled(0.2, 0.2, 1);
	glutSolidCube(1.0);
	glPopMatrix();
}

void piedUp() {
	glPushMatrix();
	glTranslated(0, 0, 0.6);
	glScaled(0.2, 0.2, 1);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawvec (double x1, double y1, double z1, double x2, double y2, double z2) {
	glDisable(GL_LIGHTING);
		gl_Color3f(1.0, 0, 0);
		glBegin(GL_LINES);
			glVertex3d(x1, y1, z1);
			glVertex3d(x2, y2, z2);
		glEnd();
	glEnable(GL_LIGHTING);
}

void draw() {
	/*que du dessin*/
	/*glutSolidSphere(1, 20, 20);*/
	/*
	g3x_Material(orange, ambi, diff, spec, shine, alpha);
	glPushMatrix();
	glTranslated(-1.0, -1.0, -1.0);
	glRotated(30.0, 0.0, 1.0, 0.0);
	glScaled(2.0, 2.0, 0.5);
	glutSolidSphere(1.0, 40, 40); 
	glPopMatrix();*/
	glPushMatrix();
		glPushMatrix();
			glScaled(3, 2, 0.2);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslated(1.4, 0.9, 0);
			pied();
		glPopMatrix();
		glPushMatrix();
			glTranslated(1.4, -0.9, 0);
			pied();
		glPopMatrix();
		glPushMatrix();
			glTranslated(-1.4, 0.9, 0);
			pied();
		glPopMatrix();
		glPushMatrix();
			glTranslated(-1.4, -0.9, 0);
			pied();
		glPopMatrix();

		glPushMatrix();
			glTranslated(1.4, 0.9, 0);
			piedUp();
		glPopMatrix();
		glPushMatrix();
			glTranslated(1.4, -0.9, 0);
			piedUp();
		glPopMatrix();
		glPushMatrix();
			glTranslated(-1.4, 0.9, 0);
			piedUp();
		glPopMatrix();
		glPushMatrix();
			glTranslated(-1.4, -0.9, 0);
			piedUp();
		glPopMatrix();
	glPopMatrix();

}

/*variables globales*/
void anim() {
	/*
	 * calcul
	 * PAS de dessin
	*/
}

int main(int argc, char const *argv[]) {
	g3x_InitWindow("toto", 800, 600);
	g3x_SetInitFunction(init);
	g3x_SetExitFunction(quit);
	g3x_SetDrawFunction(draw);
	/*g3x_SetAnimFunction(anim);*/

	return g3x_MainStart();
}