#pragma once
#include "GLFrame.h"

class GLWindow
{
	GLFWwindow* window;
protected:
	GLFrame* frame;
public:
	GLWindow();
	void loop();
	friend static void onMouseMove(GLFWwindow* window, double xpos, double ypos);
	~GLWindow();
};

