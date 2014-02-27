#include "View.h"
#include <GL/glut.h>
#include "../Log.h"
#include <math.h>
#include <vector>
#include "..\Model\Objects\Ants\Queen.h"
#include <sstream>

using namespace std;

View::View()
{

}

View::~View()
{

}

void View::DrawCircle(float x, float y, float r, int segments)
{
	glPushMatrix();
	glTranslatef(x, y, 0);
	glBegin(GL_LINE_LOOP);
	for (float i = 0; i < 2 * 3.14; i += 2 * 3.14 / segments)
		glVertex2f(r * sin(i), r * cos(i));
	glEnd();
	glPopMatrix();
}

void View::DrawAnt(BaseAnt * ant)
{
	if (typeid(*ant) == typeid(Queen))
		glColor4f(0.8, 0.7, 0.6, 1);
	else
		glColor4f(0, 0, 0, 1);
	float size = ant->Size() * ant->GetHealth();
	glPushMatrix();
	glTranslatef(ant->Position()->X(), ant->Position()->Y(), 0);
	glBegin(GL_QUADS);
	glVertex2f(-size, -size);
	glVertex2f(-size, size);
	glVertex2f(size, size);
	glVertex2f(size, -size);
	glEnd();
	glPopMatrix();
}

void View::DrawAthill(Anthill * anthill)
{
	glColor4f(0.3, 0.2, 0, 1);
	glLineWidth(4);
	DrawCircle(anthill->Position()->X(), anthill->Position()->Y(), anthill->Size(), 16);
}

void View::Update(int arg)
{
	glutPostRedisplay();
	glutTimerFunc(14, Update, 0);
}

void View::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawAthill(World::Instance().GetAnthill());
	vector<BaseAnt *> ants = World::Instance().GetAnthill()->GetAnts();
	for (vector<BaseAnt *>::iterator ant = ants.begin(); ant != ants.end(); ant++)
		DrawAnt(*ant._Ptr);
	glutSwapBuffers();
}

void View::Initialize(int argc, char * argv[], int width, int height)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Anthill");
	glutDisplayFunc(Draw);
	glutTimerFunc(14, Update, 0);

	glClearColor(0.0, 0.4, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_ALPHA);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void View::Start() 
{
	Log::Message("Start view");
	glutMainLoop();
}
