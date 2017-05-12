
/*********************************************************/
/*        TP1: primitives 2D et transformations          */
/*********************************************************/
/*													     */
/*       ESGI: Algorithmiques pour l'infographies		 */
/*													     */
/*********************************************************/
/*													     */
/*  Objectif: afficher des formes 2D et les transformer  */
/*													     */
/*********************************************************/



#include<windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14
#define TRUE 1
#define FALSE 0

double horizon= 0.0;//� ajouter
double vertical=0.0;//� ajouter
double x = 0.0;
double y = 0.0;
double z = 0.0;
double R = 5.0;//� ajouter
double alpha = 0.0;//� ajouter
double phi = 0.0;//� ajouter
int mouse_X, mouse_Y;//� ajouter
int x_pre,y_pre;//� ajouter
int x_var = 0;//� ajouter
int y_var = 0;//� ajouter
int free_camera = FALSE;//� ajouter
float angle = 0.0;
float angle2 = 0.0;

double angleRotationBrasGauche = 0.05;
double angleRotationBrasDroit = 0.05;

double angleRotationJambeGauche = 0.04;
double angleRotationJambeDroit = 0.04;

double angleAvBrasGauche = 46.0;
double angleAvBrasDroit = 279.0;

double angleAvJambeGauche = 46.0;
double angleAvJambeDroit = 279.0;

/* prototypes de fonctions */
void initRendering();                           // Initialisation du rendu
void display();                             // mod�lisation
void reshape(int w,int h);                      // visualisation
void update(int value);                         // mise � jour: appelle Timer pour l'animation de la sc�ne
void keyboard(int key, int x, int y); // fonction clavier //� ajouter
void navigate();

void vMouse(int mouse_X, int mouse_Y);//� ajouter

/*void vPassive(int x, int y)
{

	int x_var = x_pre - x;
	int y_var = y_pre - y;
    printf("x%d y%d xpre %d ypre%d xvar%d yvar%d\n",x,y,x_pre,y_pre,x_var,y_var);
    if(x_var > 0)
                alpha -= 0.1;
    if(x_var < 0)
        alpha += 0.1;

	x_pre = x;
	y_pre = y;

}*/


/* Programme principal */
int main(int argc,       // argc: nombre d'arguments, argc vaut au moins 1
		  char **argv){  // argv: tableau de chaines de caract�res, argv[0] contient le nom du programme lanc� (plus un �ventuel chemin)


	/* Initialisation de glut et creation de la fenetre */
    glutInit(&argc, argv);                       // Initialisation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // mode d'affichage RGB, et test prafondeur
    glutInitWindowSize(500, 500);                // dimension fen�tre
	glutInitWindowPosition (100, 100);           // position coin haut gauche
	glutCreateWindow("TP1: formes 2D et transformation");  // nom

	/* Initialisation d'OpenGL */
	initRendering();

	/* Enregistrement des fonctions de rappel
     => initialisation des fonctions callback appel�es par glut */
    glutDisplayFunc(display);
    glutTimerFunc (1,update, 0);
    glutPostRedisplay();
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);//� ajouter
	glutMotionFunc(vMouse);//� ajouter

	/* rq: le callback de fonction (fonction de rappel) est une fonction qui est pass�e en argument � une
	autre fonction. Ici, le main fait usage des deux fonctions de rappel (qui fonctionnent en m�me temps)
	alors qu'il ne les conna�t pas par avance.*/
    glutTimerFunc (20,update, 0);//� ajouter

	/* Entr�e dans la boucle principale de glut, traitement des �v�nements */
    glutMainLoop();         // lancement de la boucle de r�ception des �v�nements
    return 0;               // pour finir
}


/* Initialisation d'OpenGL pour le rendu de la sc�ne */
void initRendering() {

    /* Active le z-buffer */
    glEnable(GL_DEPTH_TEST);

	/* Activation des couleurs */
	glEnable(GL_COLOR_MATERIAL);

	/* d�finit la couleur d'effacement et la couleur de fond */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  d�finit la taille d'un pixel*/
	glPointSize(2.0);

}

/* Cr�ation de la sc�ne */
void display(){
    navigate();
    glutPostRedisplay();
	/* Efface les tampons de couleur et de profondeur de l'image avec la couleur de fond.
	rq: buffer: m�moire tampon, c'est donc une surface en memoire utilis�e pour stocker une image*/
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	/* la mat de visualisation-mod�lisation est modifiable par d�faut */
	glMatrixMode(GL_MODELVIEW);

	/* on charge l'identit� dans la matrice de mod�lisation-visualisation*/
	glLoadIdentity();

    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};   // Color (0.2, 0.2, 0.2)

    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};    // Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};      // Positioned at (4, 0, 8)

    GLfloat lightColor2[] = {0.0f, 1.0f, 0.0f, 1.0f};    // Color (0.0, 1.0, 0.0)
	GLfloat lightPos2[] = {-10.0f, 0.0f, 0.0f, 1.0f};     // Coming from the direction (-3, 0, 0)

	/* Permet de cr�er un point de vue. D�finit une matrice de mod�lisation-visualisation et la multiplie
	� droite de lma matrice active, ici l'identit�*/
	if ( free_camera == TRUE)//� ajouter
    {
        gluLookAt(x, y, z,      // position cam�ra
              horizon, vertical, 0.0,      // point de mire
              0.0, 1.0, 0.0);     // vecteur d'orientation cam�ra
    }
    else if ( free_camera == FALSE )//� ajouter
    {
        gluLookAt(0.0, 0.0, 12.0,      // position cam�ra
              0.0, 0.0, 0.0,      // point de mire
              0.0, 1.0, 0.0);     // vecteur d'orientation cam�ra
    }

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);        // lumi�re diffuse
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);         // position

    glPushMatrix();
        glRotatef(angle2, 0.0f, 1.0f, 0.0f);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);        // lumi�re diffuse
        glLightfv(GL_LIGHT2, GL_LINEAR_ATTENUATION, lightPos2);
        glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);         // position
    glPopMatrix();


    ////////////////////////////robot

    /* A vous de jouer */
    glPushMatrix();
        glRotatef(90, 1.0, 0.0, 0.0);
        glScalef(1.0, 1.0, 4.0);
        //glColor3f(1.0, 0.0, 0.0);
        gluCylinder(gluNewQuadric(), 1.0, 1.0, 1.0, 54, 54);
        glRotatef(-90, 1.0, 0.0, 0.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.8, 0.0);
        //glColor3f(0.0, 0.0, 1.0);
        gluSphere(gluNewQuadric(), 1.25, 54, 54);
        glTranslatef(0.0, -0.8, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.0, -2.0, 0.0);
        // Avant Bras Gauche
        glPushMatrix();
            glTranslatef(1.0, 0.0, 0.0);
            glRotatef(angleAvBrasGauche,0.0f,0.0f,1.0f);
            //glColor3f(1.0,0.0,0.0);
            glRotatef(45.0f,0.0f,0.0f,1.0f);
            glPushMatrix();
                glTranslatef(1.0, 0.0, 0.0);
                glScalef(2.0,1.0,1.0);
                glutSolidCube(1.0);
                glTranslatef(-1.0, 0.0, 0.0);
            glPopMatrix();
            glTranslatef(-1.0, 0.0, 0.0);
        glPopMatrix();
        // Coude Gauche
        //glColor3f(0.0,0.0,1.0);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glScalef(1.0,1.0,1.0);
            glutSolidSphere(0.54, 36.0, 36.0);
        glPopMatrix();
        // Bras Gauche
        //glColor3f(1.0,0.0,0.0);
        glRotatef(45.0f,0.0f,0.0f,1.0f);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glScalef(2.0,1.0,1.0);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0, -2.0, 0.0);
        // Avant Bras Droit
        glPushMatrix();
            glTranslatef(6.0, 0.0, 0.0);
            glRotatef(angleAvBrasDroit,0.0f,0.0f,1.0f);
            //glColor3f(1.0,0.0,0.0);
            glRotatef(-225.0f,0.0f,0.0f,1.0f);
            glPushMatrix();
                glTranslatef(1.0, 0.0, 0.0);
                glScalef(2.0,1.0,1.0);
                glutSolidCube(1.0);
                glTranslatef(5.0, 0.0, 0.0);
            glPopMatrix();
            glTranslatef(5.0, 0.0, 0.0);
        glPopMatrix();
        // Coude Droit
        //glColor3f(0.0,0.0,1.0);
        glTranslatef(6.0,0.0,0.0);
        glPushMatrix();
            glScalef(1.0,1.0,1.0);
            glutSolidSphere(0.54, 36.0, 36.0);
        glPopMatrix();
        // Bras Droit
        //glColor3f(1.0,0.0,0.0);
        glRotatef(-225.0f,0.0f,0.0f,1.0f);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glScalef(2.0,1.0,1.0);
            glutSolidCube(1.0);
        glPopMatrix();
        glRotatef(225.0f,0.0f,0.0f,1.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.45, -5.0, 2.5);
        glScalef(0.8, 1.0, 1.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
            glPushMatrix();
            // Avant Jambe Droite
                glTranslatef(1.0, 0.0, 0.0);
                glRotatef(angleAvJambeGauche,0.0f,0.0f,1.0f);
                //glColor3f(1.0,0.0,0.0);
                glPushMatrix();
                    glTranslatef(1.0, 0.0, 0.0);
                    glScalef(2.0,1.0,1.0);
                    glutSolidCube(1.0);
                    glTranslatef(-1.0, 0.0, 0.0);
                glPopMatrix();
                glTranslatef(-1.0, 0.0, 0.0);
            glPopMatrix();
            // Rotule Droite
            //glColor3f(0.0,0.0,1.0);
            glTranslatef(1.0,0.0,0.0);
            glPushMatrix();
                glScalef(1.0,1.0,1.0);
                glutSolidSphere(0.54, 36.0, 36.0);
            glPopMatrix();
            // Jambe Droite
            //glColor3f(1.0,0.0,0.0);
            glRotatef(45.0f,0.0f,0.0f,1.0f);
            glTranslatef(1.0,0.0,0.0);
            glPushMatrix();
                glScalef(2.0,1.0,1.0);
                glutSolidCube(1.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.45, -5.0, 2.5);
        glScalef(0.8, 1.0, 1.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
            glPushMatrix();
            // Avant Jambe Gauche
                glTranslatef(1.0, 0.0, 0.0);
                glRotatef(angleAvJambeDroit,0.0f,0.0f,1.0f);
                //glColor3f(1.0,0.0,0.0);
                glPushMatrix();
                    glTranslatef(1.0, 0.0, 0.0);
                    glScalef(2.0,1.0,1.0);
                    glutSolidCube(1.0);
                    glTranslatef(-1.0, 0.0, 0.0);
                glPopMatrix();
                glTranslatef(-1.0, 0.0, 0.0);
            glPopMatrix();
            // Rotule Gauche
            //glColor3f(0.0,0.0,1.0);
            glTranslatef(1.0,0.0,0.0);
            glPushMatrix();
                glScalef(1.0,1.0,1.0);
                glutSolidSphere(0.54, 36.0, 36.0);
            glPopMatrix();
            // Jambe Gauche
            //glColor3f(1.0,0.0,0.0);
            glRotatef(45.0f,0.0f,0.0f,1.0f);
            glTranslatef(1.0,0.0,0.0);
            glPushMatrix();
                glScalef(2.0,1.0,1.0);
                glutSolidCube(1.0);
            glPopMatrix();
    glPopMatrix();

    //////////////////////////////////////////robot

    glPushMatrix();
        glRotatef(angle2, 0.0f, 1.0f, 0.0f);
        glTranslatef(-10.0f, 0.0f, 0.0f);
        glutWireCube(0.9f);
    glPopMatrix();

	/* On swap (�change) eles buffers, c�d, on fait passer l'image calcul�e et dessin�e
	dans le back buffer au buffer qui va l'afficher: le front buffer (en g�n�ral), c'est le bouble buffering
	Cela �vite une image anim�e sacad�e, si elle �tait directement trac�e dans le front buffer*/
	glutSwapBuffers();

	/* On force l'affichage */
	glFlush(); // nettoie les fen�tres pr�c�dentes
}

/*  Mise en forme de la sc�ne pour l'affichage */
void reshape(int w,  // w: largeur fen�tre
			 int h)  // h: hauteur fen�tre
{
	/* Viewport: cadrage. Sp�cifie la r�gion (position et taille en px) que l'image observ�e de la sc�ne occupe
	� l'�cran => r�duction et agrandissement de l'image possible*/
	glViewport(0, 0,(GLsizei) w, (GLsizei) h);

	/* Sp�cifie que la matrice de projection va �tre modifi�e  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();             // matrice courante: l'identit�
	//glOrtho(-2.0, 2.0, -2.0, 2.0, 1.5, 20.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);

	/* Perspective avec point de fuite */
	gluPerspective(60.0,                       // angle d'ouverture vertical cam�ra
				   (GLfloat) w / (GLfloat) h,  // ratio largeur-hauteur
				   1.0,						   // plan proche z=1
				   200.0);                     // plan �loign� z=200


}

/* Fonction de gestion du clavier */
void keyboard(int key,       // Touche qui a �t� press�e //� ajouter
                    int x, int y) {    // Coordonn�es courante de la souris

		switch (key){

			case GLUT_KEY_UP:   /* affichage du carr� plein*/
				R -= 0.1;
				glutPostRedisplay();
				break;

			case GLUT_KEY_LEFT:   /* affichage en mode fil de fer*/
				horizon += 0.1;

				glutPostRedisplay();
				break;

			case GLUT_KEY_DOWN:   /* affichage en mode sommets seuls*/
				R += 0.1;

				glutPostRedisplay();
				break;

            case GLUT_KEY_RIGHT:   /* affichage en mode sommets seuls*/
				horizon -= 0.1;

				glutPostRedisplay();
				break;

            case GLUT_KEY_PAGE_UP:
                vertical += 0.1;

                glutPostRedisplay();
                break;

            case GLUT_KEY_PAGE_DOWN:
                vertical -= 0.1;

                glutPostRedisplay();
                break;
            case GLUT_KEY_F1:
                free_camera = TRUE;

                glutPostRedisplay();
                break;
            case GLUT_KEY_F2:
                free_camera = FALSE;

                glutPostRedisplay();
                break;

            case GLUT_KEY_F3:   /* activation lumi�re n�2*/
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				glDisable(GL_LIGHT2);
				glutPostRedisplay();
				break;

            case GLUT_KEY_F4:   /* activation lumi�re n�2*/
				glEnable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHT1);
				glEnable(GL_LIGHT2);
				glutPostRedisplay();
				break;

			case GLUT_KEY_END:   /* Quitter le programme */
				exit(0);
		}
}

void navigate()//� ajouter
{
    if(phi < -PI)
        phi = PI;
    if(phi > PI)
        phi = -PI;
    if(alpha < -1.5)
        alpha = -1.5;
    if(alpha > 1.5)
        alpha = 1.5;


    x = R * cos(alpha) * sin(phi);
    y = R * sin(alpha);
    z = R * cos(alpha) * cos(phi);
}

void RotationAvBrasGauche(){
    if(angleAvBrasGauche > 181){
        angleRotationBrasGauche = -0.05;
        angleAvBrasGauche = 180;
    }
    if(angleAvBrasGauche < 45){
        angleRotationBrasGauche = 0.05;
        angleAvBrasGauche = 46;
    }
    angleAvBrasGauche += angleRotationBrasGauche;
}

void RotationAvBrasDroit(){
    if(angleAvBrasDroit < 180){
        angleRotationBrasDroit = 0.05;
        angleAvBrasDroit = 181;
    }
    if(angleAvBrasDroit > 315){
        angleRotationBrasDroit = -0.05;
        angleAvBrasDroit = 314;
    }
    angleAvBrasDroit += angleRotationBrasDroit;
}

void RotationAvJambeGauche(){
    if(angleAvJambeGauche > 1){
        angleRotationJambeGauche = -0.05;
        angleAvJambeGauche = 0;
    }
    if(angleAvJambeGauche < -60){
        angleRotationJambeGauche = 0.05;
        angleAvJambeGauche = -59;
    }
    angleAvJambeGauche += angleRotationJambeGauche;
}

void RotationAvJambeDroit(){
    if(angleAvJambeDroit > 1){
        angleRotationJambeDroit = -0.05;
        angleAvJambeDroit = 0;
    }
    if(angleAvJambeDroit < -60){
        angleRotationJambeDroit = 0.05;
        angleAvJambeDroit = -59;
    }
    angleAvJambeDroit += angleRotationJambeDroit;
}

void update(int value)
{
    RotationAvBrasGauche();
    RotationAvBrasDroit();

    RotationAvJambeGauche();
    RotationAvJambeDroit();

	angle2 += 0.1;
	if (angle2 > 360){
		angle2 -= 360;
	}

    glutPostRedisplay();
    glutTimerFunc(1,update, 0);
}

void vMouse(int mouse_X, int mouse_Y)//� ajouter
{
    printf("Souris a: %d %d \n",mouse_X,mouse_Y);
    x_var = x_pre - mouse_X;
	y_var = y_pre - mouse_Y;

    if(y_var > 0)
        alpha -= 0.1;
    if(y_var < 0)
        alpha += 0.1;
    if(x_var > 0)
        phi -= 0.1;
    if(x_var < 0)
        phi += 0.1;
    glutPostRedisplay();
    x_pre = mouse_X;
    y_pre = mouse_Y;

}
