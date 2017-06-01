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
        void Draw();

        void RotationAvBrasGauche();
        void RotationAvBrasDroit();
        void RotationAvJambeGauche();
        void RotationAvJambeDroit();

        double angleRotationBrasGauche;
        double angleRotationBrasDroit;

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

    protected:

    private:
};

#endif // ROBOT_H
