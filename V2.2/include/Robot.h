#ifndef ROBOT_H
#define ROBOT_H
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

class Robot
{
    public:
        Robot();
        Robot(float x, float y, float z);
        void corp();
        void brasGauche();
        void brasDroit();
        void Draw();

        void RotationAvBrasGauche();
        void RotationAvBrasDroit();
        void RotationAvJambeGauche();
        void RotationAvJambeDroit();

        double angleEpauleGauche1;
        double angleEpauleGauche2;
        double angleCoudeGauche;

        double angleEpauleDroite1;
        double angleEpauleDroite2;
        double angleCoudeDroite;

        double angleRotationBrasDroit;

        double angleRotationBrasGauche;
        double angleRotationJambeGauche;
        double angleRotationJambeDroit;


        double angleAvBrasGauche;
        double angleAvBrasDroit;
        double angleAvJambeGauche;
        double angleAvJambeDroit;

        float posx;
        float posy;
        float posz;

        float x;
        float y;
        float z;

        GLuint texture;

    protected:

    private:
};

#endif // ROBOT_H
