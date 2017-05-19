#ifndef ROBOT_H
#define ROBOT_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

class Robot
{
    public:
        Robot();
        Robot(float x, float y, float z);
        void Draw();

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
