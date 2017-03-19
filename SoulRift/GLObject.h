#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <string>
#include <common/shader.hpp>
#include <common/texture.hpp>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGTH 1080

class GLObject
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
protected:
	int x, y, heigth, width;
	GLuint shaders;
	GLuint texture;
public:
	GLObject(int x = 0, int y = 0, int heigth = 0, int width = 0);
	void draw();
	//void onMouseMove(double xpos, double ypos);
	bool isMouseOnObject(double xpos, double ypos);
	virtual void active() = 0;
	virtual void disactive() = 0;
	virtual ~GLObject();
};