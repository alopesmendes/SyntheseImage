#include <g3x.h>

G3Xpoint *lightpos;
Point A;
vecteur u;

void draw_light() {
	glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();
			glTranslated((*lightpos)[0], (*lightpos)[1], (*lightpos)[2]);
			glutSolidSphere(0.05, 10, 10);
		glPopMatrix();
	glEnable(GL_LIGHTING);
}

void init() {
	/*lightpos = &(g3x_GetLight()->pos);*/
	g3x_SetLightCartesian((G3Xpoint) {-2, -2, 2});
	lightpos = &(g3x_GetLight()->pos);
	/*A = (Point) {(*lightpos)[0], (*lightpos)[1], (*lightpos)[2]};
	u = (vecteur) {-A.x, -A.y, -A.z};

	Point I;
	vecteur N;
	if (Ray_inter_S0(A, u, &I, &N)) {
		draw_segment(A, I, (Couleur){1., 1., 1.});
		draw_vecteur(I, (Couleur){1, 0, 0}, N, (Couleur){1, 1, 0});
	} else
		draw_vecteur(A, (Couleur){1, 1, 1}, u, (Couleur){0, 0, 0});*/


}

void draw() {
	draw_light();
	g3x_Material((float[4]){0.8, 0.6, 0.2, 1.0}, 0.1, 0.5, 0.4, 0.9, 1.);
	glPushMatrix();
		glutSolidSphere(1., 40, 40);
	glPopMatrix();
}


/*pasée à atExit()*/
void quit() {
	/*free seulement ici*/
}

int main(int argc, char const *argv[]) {
	g3x_InitWindow("toto", 800, 600);
	g3x_SetInitFunction(init);
	g3x_SetExitFunction(quit);
	g3x_SetDrawFunction(draw);
	/*g3x_SetAnimFunction(anim);*/

	return g3x_MainStart();
}