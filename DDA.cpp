#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
double x1, y1, x2, y2, dx, dy, m=0;
void display(void)
{
    /* clear all pixels */
   // glClear (GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */
    /*glColor3ub (255, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d (100, 100);
    glVertex2d (190,190);
    glVertex2d (280, 100);*/
    dx=(x2-x1);
    dy=(y2-y1);
    m = dy/dx;
    while(1)
    {
        if(x1 == x2 && y1 == y2)
        {
            break;
        }
        if(m>1)
        {
            x1 = x1+(1/m);
            y1 = y1 +1;

        }
        else if(m< -1)
        {
            x1 = x1-(1/m);
            y1 = y1 -1;
        }
        else if(m>= -1 && m<=0)
        {
            x1 = x1-1;
            y1 = y1 - m;

        }
        else if(m> 0 && m <= 1)
        {
            x1 = x1+1;
            y1 = y1 + m;
        }


        glColor3ub (255, 0, 0);
        glBegin(GL_POINTS);
        glVertex2d (x1, y1);
        glEnd();
    }

    /* don't wait!
    * start processing buffered OpenGL routines
    */
    glFlush ();
}
void init (void)
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 20, -10, 20);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
    printf("Enter the end point");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
