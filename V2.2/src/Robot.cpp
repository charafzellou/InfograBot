#include "Robot.h"

Robot::Robot()
{
    posx = 0.0f;
    posy = 0.0f;
    posz = 5.0f;

    x = 1.0f;
    y = 1.0f;
    z = 1.0f;


    angleEpauleGauche1 = -45.0;
    angleEpauleGauche2 = -45.0;
    angleCoudeGauche = 45.0;

    angleEpauleDroite1 = -135.0;
    angleEpauleDroite2 = -45.0;
    angleCoudeDroite = -45.0;

}

Robot::Robot(float x, float y, float z)
{
    posx = 0.0f;
    posy = 0.0f;
    posz = 0.0f;

    this->x = x;
    this->y = y;
    this->z = z;
    angleEpauleGauche1 = -45.0;
    angleEpauleGauche2 = -45.0;
    angleCoudeGauche = 45.0;

    angleEpauleDroite1 = -135.0;
    angleEpauleDroite2 = -45.0;
    angleCoudeDroite = -45.0;
}

void Robot::corp()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    //partie haute
        glPushMatrix();
            glTranslatef(0.0, -0.2, -1.0);
            glRotatef(-10,1,0,0);
            glPushMatrix();
                glBindTexture(GL_TEXTURE_2D, texture);
                gluCylinder(params, 0.9, 1.0, 1.0, 54, 54);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -0.6, -2.0);
            glRotatef(-20,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.8, 0.9, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -1.1, -2.8);
            glRotatef(-30,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.7, 0.8, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -1.7, -3.5);
            glRotatef(-40,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.6, 0.7, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -2.3, -4.0);
            glRotatef(-50,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.5, 0.6, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -3.2, -4.5);
            glRotatef(-60,1,0,0);
            //glTranslatef(0.0, 0.0, -0.2);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.1, 0.5, 1.0, 54, 54);
        glPopMatrix();

            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 1.0, 1.0, 1.0, 54, 54);//cylindre central
        //partie basse
        glPushMatrix();
            glTranslatef(0.0, 0.0, 1.0);
            glRotatef(10,1,0,0);
            glPushMatrix();
                glBindTexture(GL_TEXTURE_2D, texture);
                gluCylinder(params, 1.0, 0.9, 1.0, 54, 54);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -0.2, 2.0);
            glRotatef(20,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.9, 0.8, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -0.6, 3.0);
            glRotatef(30,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.8, 0.7, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -1.1, 3.8);
            glRotatef(40,1,0,0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.7, 0.6, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -1.7, 4.5);
            glRotatef(50,1,0,0);
            //glTranslatef(0.0, 0.0, -0.2);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.6, 0.5, 1.0, 54, 54);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, -2.3, 5.0);
            glRotatef(60,1,0,0);
            //glTranslatef(0.0, 0.0, -0.2);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.5, 0.1, 1.0, 54, 54);
        glPopMatrix();
}
void Robot::brasGauche()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    glPushMatrix();

        // Epaule
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glScalef(1.0,1.0,1.0);
            glBindTexture(GL_TEXTURE_2D, texture);
            glutSolidSphere(0.54, 36.0, 36.0);
        glPopMatrix();
        // Bras Gauche
        //glColor3f(1.0,0.0,0.0);
        glRotatef(angleEpauleGauche1,0.0f,0.0f,1.0f);
        glRotatef(angleEpauleGauche2,0.0f,1.0f,0.0f);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glRotatef(90,0,1,0);//ne pas toucher
            glTranslatef(0.0,0.0, -1.0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.5, 0.5, 2.0, 54, 54);
        glPopMatrix();
        // Coude Gauche
        //glColor3f(0.0,0.0,1.0);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glScalef(1.0,1.0,1.0);
            glBindTexture(GL_TEXTURE_2D, texture);
            glutSolidSphere(0.54, 36.0, 36.0);
        glPopMatrix();
        // Avant Bras Gauche
        glPushMatrix();
            //glRotatef(angleAvBrasGauche,0.0f,0.0f,1.0f);
            //glColor3f(1.0,0.0,0.0);
            glPushMatrix();
                glRotatef(angleCoudeGauche,1,0,0);
                glBindTexture(GL_TEXTURE_2D, texture);
                gluCylinder(params, 0.5, 0.5, 2.0, 54, 54);
                glTranslatef(-1.0, 0.0, 0.0);
            glPopMatrix();
            glTranslatef(-1.0, 0.0, 0.0);
        glPopMatrix();

    glPopMatrix();
}
void Robot::brasDroit()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    //glTranslatef(-1.0, 0.0, 0.0);
    //glRotatef(180, 0.0, 1.0, 0.0);
    glPushMatrix();
        // Epaule
        glTranslatef(-1.0,0.0,0.0);
        glPushMatrix();
            glScalef(1.0,1.0,1.0);
            glBindTexture(GL_TEXTURE_2D, texture);
            glutSolidSphere(0.54, 36.0, 36.0);
        glPopMatrix();
        // Bras DROIT
        //glColor3f(1.0,0.0,0.0);
        glRotatef(angleEpauleDroite1,0.0f,0.0f,1.0f);
        glRotatef(angleEpauleDroite2,0.0f,1.0f,0.0f);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glRotatef(90,0,1,0);//ne pas toucher
            glTranslatef(0.0,0.0, -1.0);
            glBindTexture(GL_TEXTURE_2D, texture);
            gluCylinder(params, 0.5, 0.5, 2.0, 54, 54);
        glPopMatrix();
        // Coude Droit
        //glColor3f(0.0,0.0,1.0);
        glTranslatef(1.0,0.0,0.0);
        glPushMatrix();
            glScalef(1.0,1.0,1.0);
            glBindTexture(GL_TEXTURE_2D, texture);
            glutSolidSphere(0.54, 36.0, 36.0);
        glPopMatrix();
        // Avant Bras Droit
        glPushMatrix();
            //glRotatef(angleAvBrasGauche,0.0f,0.0f,1.0f);
            //glColor3f(1.0,0.0,0.0);
            glPushMatrix();
                glRotatef(angleCoudeDroite,1,0,0);
                glBindTexture(GL_TEXTURE_2D, texture);
                gluCylinder(params, 0.5, 0.5, 2.0, 54, 54);
                glTranslatef(-1.0, 0.0, 0.0);
            glPopMatrix();
            glTranslatef(-1.0, 0.0, 0.0);
        glPopMatrix();
    glPopMatrix();
}
void Robot::Draw()
{
    glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
        glRotated(90,1,0,0);
        corp();
        brasGauche();
        brasDroit();
    glPopMatrix();

    /*glPushMatrix();
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
    */
}
void Robot::RotationAvBrasGauche()
{
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
void Robot::RotationAvBrasDroit()
{
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
void Robot::RotationAvJambeGauche()
{
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
void Robot::RotationAvJambeDroit()
{
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


