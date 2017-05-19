#include "Robot.h"

Robot::Robot()
{
    posx = 0.0f;
    posy = 0.0f;
    posz = 0.0f;

    x = 1.0f;
    y = 1.0f;
    z = 1.0f;
    angleRotationBrasGauche = 0.05;
    angleRotationBrasDroit = 0.05;

    angleRotationJambeGauche = 0.04;
    angleRotationJambeDroit = 0.04;

    angleAvBrasGauche = 46.0;
    angleAvBrasDroit = 279.0;

    angleAvJambeGauche = 46.0;
    angleAvJambeDroit = 279.0;

}

Robot::Robot(float x, float y, float z)
{
    posx = 0.0f;
    posy = 0.0f;
    posz = 0.0f;

    this->x = x;
    this->y = y;
    this->z = z;
    angleRotationBrasGauche = 0.05;
    angleRotationBrasDroit = 0.05;

    angleRotationJambeGauche = 0.04;
    angleRotationJambeDroit = 0.04;

    angleAvBrasGauche = 46.0;
    angleAvBrasDroit = 279.0;

    angleAvJambeGauche = 46.0;
    angleAvJambeDroit = 279.0;
}

void Robot::Draw()
{
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


