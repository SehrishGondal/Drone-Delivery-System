#include <GL/glut.h>  // open to use window

float carx = 0.0f; // here car x is global variable here speed still 0

void specialkeys (int key, int x, int y) // function used to press arrow keys

{ 
  switch (key) {
  	
  case GLUT_KEY_LEFT:  // move left
  carx -= 0.1f;
  break;
  case GLUT_KEY_RIGHT: // move right
  carx += 0.1f;
  break;
}
  glutPostRedisplay(); // used to refresh the screen so that we see the movement on screen
}
   
   void drawCar()  // function to draw a car
   {
   	glColor3f(1.0f, 0.0f, 0.0f); // show colors
   	//         R      G     B
   	glBegin(GL_QUADS); // points to draw a rectangle 
   	
   	glVertex2f(carx -0.2f, -0.2f);
   	glVertex2f(carx +0.2f, -0.2f); // measurement of rectangle
   	glVertex2f(carx +0.2f,  0.0f);
   	glVertex2f(carx -0.2f,  0.0f);
   	
   	glEnd ();  // end of drawing shape
   	// for adding wheels
   	glColor3f(0.0f, 0.0f, 0.0f);
   	glBegin(GL_QUADS);
   	glVertex2f(carx -0.15f, -0.25f);
   	glVertex2f(carx -0.05f, -0.25f); // 1st wheel
   	glVertex2f(carx -0.05f, -0.2f);
   	glVertex2f(carx -0.15f, -0.2f);
   	
   	glEnd (); 
   	
   	glBegin(GL_QUADS);
   	glVertex2f(carx +0.15f, -0.25f);
   	glVertex2f(carx +0.05f, -0.25f); // 2nd wheel
   	glVertex2f(carx +0.05f, -0.2f);
   	glVertex2f(carx +0.15f, -0.2f);
   	
   	glEnd (); 
   }
   
   void display()
   {
   	glClear(GL_COLOR_BUFFER_BIT); // clear previous screen
   	glLoadIdentity(); // reset coordinate system (x axis and y axis)
   	drawCar();
   	glFlush();
   }
   
   void init()
   {
   	glClearColor(0.8f, 0.8f, 1.0f, 1.0f); // for background color skyblue
   	glMatrixMode(GL_PROJECTION);  // for dimension 2D/3D
   	
   }
int main(int argc, char** argv) {
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowSize(100,100);
	glutCreateWindow("My Open GL Window");
	init ();
	glutDisplayFunc(display);
	glutSpecialFunc(specialkeys);
	glutMainLoop();
	return 0;
}















