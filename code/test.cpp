/*
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    // clear the matrix
    glLoadIdentity();

    // viewing transformation
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // modeling transformation
    glScalef(1.0, 2.0, 1.0);

    glutWireCube(1.0);
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
*/

#include <GL/glfw.h>

float cx=0;
float cy=0;

void GLFWCALL callBackResize(int width, int height)
{
if (height==0)
height=1;

glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void GLFWCALL callBackKey(int key, int state)
{
if (state == GLFW_PRESS && key == GLFW_KEY_LEFT)
cx-=0.1;
if (state == GLFW_PRESS && key == GLFW_KEY_RIGHT)
cx+=0.1;
if (state == GLFW_PRESS && key == GLFW_KEY_UP)
cy+=0.1;
if (state == GLFW_PRESS && key == GLFW_KEY_DOWN)
cy-=0.1;
}

int main()
{
int running = GL_TRUE;
glfwInit();
glfwSetWindowTitle("Engine2D V1.0 (C)Soulfreezer");

if( !glfwOpenWindow( 640, 480, 32,32,32,32,32,0, GLFW_FULLSCREEN))
{
glfwTerminate();
return 1;
}

glfwSetWindowSizeCallback( callBackResize );
glfwEnable( GLFW_KEY_REPEAT );
glfwSetKeyCallback( callBackKey);
glfwSwapInterval(0);

glShadeModel(GL_SMOOTH);
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClearDepth(1.0f);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

while(running)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(cx, cy,-6.0f);

glBegin(GL_TRIANGLES);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f(0.0f,1.0f,0.0f);
glVertex3f(-1.0f,-1.0f, 0.0f);
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(1.0f,-1.0f, 0.0f);
glEnd();
glfwSwapBuffers();

running = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
}

return 0;
}
