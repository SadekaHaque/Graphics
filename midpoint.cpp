#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int X1, Y1, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+X1, y+Y1);
	glEnd();
}


void myInit (void)
{
	glClearColor(0, 0, 0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float p = 1 - r;
	plot(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x++;
			p += 2*x+1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		int mid = 150;
		plot(mid+x, mid+y);
		plot(mid+x, mid-y);
		plot(mid-x, mid+y);
		plot(mid-x, mid-y);
		plot(mid+y, mid+x);
		plot(mid-y, mid+x);
		plot(mid+y, mid-x);
		plot(mid-y, mid-x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{
	printf("Enter X :");
    scanf("%d", &X1);
    printf("Enter Y :");
    scanf("%d", &Y1);
    printf("radius :");
    scanf("%d", &r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}

