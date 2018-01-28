#include <GL/freeglut.h>
#include <time.h>
#include <

#define WIDTH 80
#define HEIGHT 45

int main (int argc, char ** argv){
    settings.init();
    food.spawn();
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);


}
