#include "GameWindow.h"

GameWindow::GameWindow()
{
	GLObject *start = new GLButton(840, 800, 100, 300, "newGameS.bmp");
	GLObject *resume = new GLButton(840, 600, 100, 300, "continueS.bmp");
	GLObject *settings = new GLButton(840, 400, 100, 300, "settingsS.bmp");
	GLObject *exit = new GLButton(840, 200, 100, 300, "exitS.bmp");
	GLWindow::frame->addChid(start);
	GLWindow::frame->addChid(resume);
	GLWindow::frame->addChid(settings);
	GLWindow::frame->addChid(exit);
}

GameWindow::~GameWindow()
{
}