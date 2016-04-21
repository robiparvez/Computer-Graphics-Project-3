#include<GL/glut.h>
#include<stdio.h>

static int flag = 1;

float ball_x = -1.0f;
float ball_y = 0.0f;
float ball_z = 0.0f;


//RENDERING
void glutInitRendering()
{
	glEnable(GL_DEPTH_TEST);

}

//RESHAPING
void reshaped(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 0, 1, 200);
}


void Objects()
{
	glPushMatrix();
		glBegin(GL_QUADS);

			glColor3f(0, 1, 0);

			//BOX 1
			glVertex3f(0.0, -0, 0.0);
			glVertex3f(-0.2, -0, 0.0);
			glVertex3f(-0.2, 0.29, 0.0);
			glVertex3f(0.0, 0.29, 0.0);

		glEnd();
	glPopMatrix();

	//glPushMatrix();
	//	glBegin(GL_QUADS);


	//		glColor3f(0, 1, 0);

	//		//BOX 2
	//		glVertex3f(0.4, -0.3, 0.0);
	//		glVertex3f(0.6, -0.3, 0.0);
	//		glVertex3f(0.6, 0, 0.0);
	//		glVertex3f(0.4, 0, 0.0);

	//	glEnd();
	//glPopMatrix();


}


void Ball()
{
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(ball_x, ball_y, ball_z);
	glutSolidSphere(0.1, 23, 23);
	glPopMatrix();


}

//Continuous movement of Ball
void updateBall()
{
	//LOGIC 
	if (flag)
	{
		ball_x += 0.0005;

		if (ball_x > -0.25  && ball_y == 0 && ball_z == 0)
		{
		flag = 0;
		printf("Ball Collided....Try Again !\n\n");
		}


	}
}

//Keyboard Work
void mykey(unsigned char key, int x, int y)
{

	//w=up, a= left, d=right, s=down, q=exit

	if (key == 'q' || key == 'Q')
	{
		exit(0);
	}
	if (key == 'w' || key == 'W')
	{
		flag = 1;
		ball_x = 0.0;
		ball_y = 0.45;
		ball_z = 0.0f;
	}
	if (key == 's' || key == 'S')
	{
		ball_x = 0;
		ball_y = -0.3;
		ball_z = 0.0;
	}
	if (key == 'a' || key == 'A')
	{
		ball_x = -0.4;
		ball_y = 0.0;
		ball_z = 0.0;
	}

}



//MAIN DISPLAY FUNCTION
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//BackGround Color set korsi
	glClearColor(0, 0, 0, 0);
	
	Objects();
	Ball();
	updateBall();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(900, 500);
	glutCreateWindow("Ball");

	glutInitRendering();

	glutDisplayFunc(display);

	glutIdleFunc(display);

	//Keyboard er kaj somuho
	glutKeyboardFunc(mykey);

	//Reshaping the ball
	glutReshapeFunc(reshaped);
	glutMainLoop();
}