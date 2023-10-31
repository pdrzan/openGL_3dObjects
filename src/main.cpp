#include <GL/freeglut.h> 
#include <math.h>

void init() {
   // Set "clearing" or background color
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Black and opaque
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 1000; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   // Draw a Red 1x1 Square centered at origin
//    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
//    glVertex3f(-0.5f, -0.5f, 0.5f);    // x, y
//    glVertex3f( 0.5f, -0.5f, 0.4f);
//    glVertex3f( 0.5f,  0.5f, 0.3f);
//    glVertex3f(-0.5f,  0.5f, 0.2f);
//    glEnd();

   drawFilledCircle(0.0, 0.0, 0.1);
 
   glFlush();  // Render now
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
}

int main(int argc, char** argv) {
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