#include <iostream>
#include <GL/glut.h>
#include "Log.h"
#include "Model/World.h"
#include "View/View.h"

#define WinWid 800
#define WinHei 800

View * view;

void InitLog()
{
	Log::Init();
	Log::SetLevel(ALL);
}

void InitializeView(int argc, char * argv[])
{
	view = new View();
	view->Initialize(argc, argv, WinWid, WinHei);
}

void InitializeModel()
{
	World::Instance().InitWorld(1000, 1000);
}

int main(int argc, char * argv[])
{
	InitializeModel();
	InitializeView(argc, argv);
	Log::Message("Application started");
	view->Start();
	delete view;
	Log::Message("Application closed");
	return 0;
}