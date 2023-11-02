#include <GL/freeglut.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <iostream>

void init()
{
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void drawFilledSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius)
{
   int triangleAmount = 50; // # of triangles used to draw circle
   int j, i;
   // GLfloat radius = 0.8f; //radius
   GLfloat twicePi = 2.0f * M_PI;
   glBegin(GL_LINE_STRIP);
   for (j = 0; j <= triangleAmount; j++)
   {
      for (i = 0; i <= triangleAmount; i++)
      {
         glVertex3f(
             x + (radius * cos(i * twicePi / triangleAmount) * sin(j * M_PI / triangleAmount)),
             y + (radius * sin(i * twicePi / triangleAmount) * sin(j * M_PI / triangleAmount)),
             z + (radius * cos(j * M_PI / triangleAmount)));
      }
   }
   glEnd();
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
   glColor3f(1.0f, 0.0f, 0.0f);  // Red
   drawFilledSphere(0.0, 0.0, 0.0, 0.7);

   glFlush(); // Render now
}

void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
  // Compute aspect ratio of the new window
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);

   glutInitWindowSize(800, 800);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello");

   glutDisplayFunc(display);
   glutIdleFunc(display);
   glutReshapeFunc(reshape);

   init();
   glutMainLoop();
   return 0;
}