#include "GLObject.h"

void GLObject::InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, points, GL_STATIC_DRAW);
	glEnableVertexAttribArray(arrayNum);
	glVertexAttribPointer(arrayNum, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

GLObject::GLObject(int x, int y, int heigth, int width) : x(x), y(y), width(width), heigth(heigth)
{
	GLfloat g_vertex_buffer_data[] = {
		(2 - (((float)x + width) / SCREEN_WIDTH) * 2) - 1, ((float)y / SCREEN_HEIGTH) * 2 - 1, // bottom-right
		(2 - ((float)x / SCREEN_WIDTH) * 2) - 1, ((float)y / SCREEN_HEIGTH) * 2 - 1, // bottom-left
		(2 - (((float)x + width) / SCREEN_WIDTH) * 2) - 1, (((float)y + heigth) / SCREEN_HEIGTH) * 2 - 1, // top-left
		(2 - ((float)x / SCREEN_WIDTH) * 2) - 1, (((float)y + heigth) / SCREEN_HEIGTH) * 2 - 1, // top-right
	};
	GLfloat uv_vertex_buffer_data[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
	};
	coordinates = new GLfloat[8];
	uvcoordinates = new GLfloat[8];
	for (int i = 0; i < 8; i++)
	{
		coordinates[i] = g_vertex_buffer_data[i];
		uvcoordinates[i] = uv_vertex_buffer_data[i];
	}
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	InitObject(coordinates, 8 * sizeof(GLfloat), vbo, 0);
	glBindVertexArray(0);
	glGenBuffers(1, &vboT);
	glBindVertexArray(vao);
	InitObject(uvcoordinates, 8 * sizeof(GLfloat), vboT, 1);
	glBindVertexArray(1);
}

void GLObject::draw()
{
	glUseProgram(shaders);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//glBindVertexArray(0);
}

bool GLObject::isMouseOnObject(double xpos, double ypos)
{
	return (xpos >= x && xpos <= (x + heigth) && ypos >= y && ypos <= (y + width));
}

void GLObject::active()
{
}

void GLObject::disactive()
{
}

GLObject::~GLObject()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}
