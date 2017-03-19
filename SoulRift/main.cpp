// Include standard headers
#include "GameWindow.h"

int main()
{
	GameWindow *win = new GameWindow();
	win->loop();
	delete win;
	return 0;
}

