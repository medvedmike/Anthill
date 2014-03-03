#include "View.h"
#include <GL/glut.h>
#include "../Log.h"
#include <math.h>
#include <vector>
#include "..\Model\Objects\Ants\Queen.h"
#include <sstream>
#include "..\Model\Objects\Ants\Larvae.h"
#include "..\Model\Objects\Ants\Policeman.h"
#include "..\Model\Objects\Ants\Worker.h"
#include "..\Model\Objects\Ants\Warrior.h"
#include "..\Model\Objects\ObjectsProperties.h"

using namespace std;

#define TIMER_INTERVAL 14
#define DELTA_TIME TIMER_INTERVAL / 1000.

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

void View::FillCircle(float x, float y, float r, int segments)
{
	glPushMatrix();
	glTranslatef(x, y, 0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * 3.14; i += 2 * 3.14 / segments)
		glVertex2f(r * sin(i), r * cos(i));
	glEnd();
	glPopMatrix();
}

void View::DrawAnt(BaseAnt * ant)
{
	if (typeid(*ant) == typeid(Worker))
		glColor4f(0.5, 0.5, 0.5, 1);
	else if (typeid(*ant) == typeid(Warrior))
		glColor4f(0.65, 0.2, 0.2, 1);
	else if(typeid(*ant) == typeid(Larvae))
		glColor4f(0.9, 0.9, 0.8, 1);
	else if (typeid(*ant) == typeid(Policeman))
		glColor4f(0, 0, 1, 1);
	else if (typeid(*ant) == typeid(Queen))
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
	glColor4f(0.7, 0.7, 0.4, 1);
	FillCircle(anthill->GetStorage()->Position()->X(),
		anthill->GetStorage()->Position()->Y(),
		anthill->GetStorage()->Size() * anthill->GetStorage()->GetFill() / FOOD_STORAGE_MAX_FOOD, 16);
}

void View::Update(int arg)
{
	World::Instance().Update(DELTA_TIME);
	glutPostRedisplay();
	glutTimerFunc(TIMER_INTERVAL, Update, 0);
}

void View::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE);
	for (int i = 0; i < 1000; i += 100)
	{
		glVertex2f(i, 0);
		glVertex2f(i, 1000);
	}
	glEnd();
	DrawAthill(World::Instance().GetAnthill());
	vector<BaseAnt *> ants = World::Instance().GetAnthill()->GetAnts();
	for (vector<BaseAnt *>::iterator ant = ants.begin(); ant != ants.end(); ant++)
		DrawAnt(*ant._Ptr);
	glColor4f(0.9, 0.9, 0.5, 1);
	vector<FoodSource *> foodSources = World::Instance().GetFoodSources();
	for (vector<FoodSource *>::iterator source = foodSources.begin(); source != foodSources.end(); source++)
		FillCircle((*source._Ptr)->Position()->X(), (*source._Ptr)->Position()->Y(), (*source._Ptr)->getStorage() / FOOD_SOURCE_STORAGE_FACTOR, 16);
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
	glutTimerFunc(TIMER_INTERVAL, Update, 0);

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
