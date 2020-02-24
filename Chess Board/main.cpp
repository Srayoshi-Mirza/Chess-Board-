#include<windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
float _angle = 0;
float i;
int k=0,xc=0,yc=0,M_PI=0;
GLuint _displayListId_blackArea; //The OpenGL id of the display list
GLuint _displayListId_whiteArea; //The OpenGL id of the display list
double rotate_y=0;
double rotate_x=0;
void specialKeys();



void handleKeypress(unsigned char key,int x,int y)
{
switch(key)
{
case 27:
exit(0);
}
}

void handleResize(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,(double)w/(double)h,1.0,200);
gluLookAt(0.0f,5.5f, 15.0f,
0.0f,0.0f,0.0f,
0.0f,1.0f,0.0f);
}

void draw_BlackArea()
{
// glPushMatrix();
//glTranslatef(1.5f,0.0f,0.0f);
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glTranslatef(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.3f,0.0f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(1.5f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(1.5f,0.3f,0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(1.50f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(0.0f,0.0f,-1.5f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.3f,0.0f);
glVertex3f(1.50f,0.3f,0.0f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();
//    glPopMatrix();

}
void draw_whiteArea()
{
// glPushMatrix();
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glTranslatef(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.3f,0.0f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(1.5f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(1.5f,0.3f,0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(1.50f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(0.0f,0.0f,-1.5f);
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(0.0f,0.3f,0.0f);
glVertex3f(1.50f,0.3f,0.0f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();
// glPopMatrix();

}

void initRendering()
{

glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glClearColor(0.0f,0.0f,0.2f,1.0f);
//Set up a display list for drawing a cube
_displayListId_blackArea = glGenLists(1); //Make room for the display list
glNewList(_displayListId_blackArea, GL_COMPILE); //Begin the display list
draw_BlackArea(); //Add commands for drawing a black area to the display list
glEndList(); //End the display list

//Set up a display list for drawing a cube
_displayListId_whiteArea = glGenLists(2); //Make room for the display list
glNewList(_displayListId_whiteArea, GL_COMPILE); //Begin the display list
draw_whiteArea(); //Add commands for drawing a black to the display list
glEndList(); //End the display list
}

/*void drawChessPieces(void)
{

    glClear (GL_COLOR_BUFFER_BIT);

    DrawArc(xc+6, yc-3,1.3,M_PI/2,M_PI/2,25);
    DrawArc(xc+6.7, yc-3,1.3,M_PI/2,-M_PI/2,25);
    DrawArc(xc+6, yc-0.9,0.8,M_PI/2,M_PI,25);
    DrawArc(xc+6.7, yc-0.9,0.8,M_PI/2,-M_PI,25);
    DrawArc(xc+6.35, yc+0.25,0.5,(7*M_PI)/4,(3*M_PI)/2,25);
    glBegin(GL_LINE_LOOP);
        glVertex2d(xc+4.7,yc-3);
        glVertex2d(xc+8,yc-3);
    glEnd();

    glFlush ();
}*/

void drawScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
glTranslatef(-4*1.5, 0.0, 4*1.5);

glRotatef( rotate_x, 1.0, 0.0, 0.0 );
glRotatef( rotate_y, 0.0, 1.0, 0.0 );


for(float j=0.0;j>(-8*1.5);j-=1.5)
{
k++;
for(i=0.0;i<(4*3.0);i+=3.0)
{
if(k%2==0)
{
glPushMatrix();
glTranslatef(i,0.0,j);
glCallList(_displayListId_blackArea);
glPopMatrix();

}
else
{
glPushMatrix();
glTranslatef(i+1.5,0.0,j);
glCallList(_displayListId_blackArea);
glPopMatrix();

}
}
}
for(float j=0.0;j>(-8*1.5);j-=1.5)
{
k++;
for(i=0.0;i<(4*3.0);i+=3.0)
{
if(k%2!=0)
{
glPushMatrix();
glTranslatef(i,0.0,j);
glCallList(_displayListId_whiteArea);
glPopMatrix();

}
else
{
glPushMatrix();
glTranslatef(i+1.5,0.0,j);
glCallList(_displayListId_whiteArea);
glPopMatrix();

}
}
}
glutSwapBuffers();

//drawChessPieces();

}

void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
  {
      _angle += 1.0f;
    if (_angle > 360)
        {
    _angle -= 360;
        }
  }

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
  {
      _angle -= 1.0f;
    if (_angle > 0)
        {
    _angle -= 360;
        }
  }


  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Request display update
  glutPostRedisplay();

}
/*void update(int value) {
_angle += 1.0f;
if (_angle > 360) {
_angle -= 360;
}
glutPostRedisplay();
glutTimerFunc(25, update, 0);
}*/
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(800,800);

glutCreateWindow("Chess Board");
initRendering();
//glutFullScreen();


glutDisplayFunc(drawScene);
glutSpecialFunc(specialKeys);
glutKeyboardFunc(handleKeypress);
glutReshapeFunc(handleResize);
//glutTimerFunc(25, update, 0);

glutMainLoop();

return 0;
}
