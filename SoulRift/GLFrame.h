#pragma once
#include "GLButton.h"
#include <list>

class GLFrame
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	GLuint shaders;
	GLuint texture;
	std::list<GLObject*> children;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
public:
	GLFrame();
	void addChid(GLObject* child);
	void draw();
	void onMouseMove(double xpos, double ypos);
	~GLFrame();
};

