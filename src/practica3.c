/*
 * Practica2.c
 *
 *  Created on: 22/08/2016
 *      Author: Cursos


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <time.h>
#include "Utils.h"
#define N_C 1
#define BUFFERS 2
static float vertexPos[] = { 0.0,  0.9, 0.0,
		             	 	-0.9, -0.9, 0.0,
					         0.9, -0.9, 0.0
};

static float vertexColor[] = {
							1.0, 0.0, 0.0,
							0.0, 1.0, 0.0,
							0.0, 0.0, 1.0
};

GLuint vertexArrayId[N_C];
GLuint programId;
static void initShaders()
{
	GLuint vShaderId = compileShader("shaders/position.vsh",GL_VERTEX_SHADER);
	if(!shaderCompiled(vShaderId)) return;
	GLuint fShaderId = compileShader();


}
static void createTriangle() {
	glGenVertexArrays(N_C,vertexArrayId);
	printf("%d",vertexArrayId[0]);

	GLuint buffersId[BUFFERS];
	glGenBuffers(BUFFERS,buffersId);
	glBindVertexArray(vertexArrayId[0]);
	glBindBuffer(GL_ARRAY_BUFFER, buffersId[0]);
	glBufferData(GL_ARRAY_BUFFER,
			     sizeof(vertexPos),
			     vertexPos,
				 GL_STATIC_DRAW
	);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, buffersId[1]);
	glBufferData(GL_ARRAY_BUFFER,
				 sizeof(vertexColor),
				 vertexColor,
				 GL_STATIC_DRAW
	);
	glColorPointer(3, GL_FLOAT, 0, 0);
	glEnableClientState(GL_COLOR_ARRAY);
}

static void exitFunc(unsigned char key, int x, int y) {
	if(key == 27) exit(0);
}

static void displayFunc() {
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(programId);
	glBindVertexArray(vertexArrayId[0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

int main(int argc, char **argv) {
	srand(time(NULL));
	int apasar = 1 + rand() % 26;
	printf("A pasar: %d\n", apasar);

	glutInit(&argc, argv);
	int width = 400, height = 400;
	glutInitWindowSize(width, height);
	int wx = (glutGet(GLUT_SCREEN_WIDTH)  - width)  / 2;
	int wy = (glutGet(GLUT_SCREEN_HEIGHT) - height) / 2;
	glutInitWindowPosition(wx, wy);
	glutCreateWindow("Mi primer tri�ngulo con OpenGL");
	glutKeyboardFunc(exitFunc);
	glutDisplayFunc(displayFunc);
	glewInit();
	createTriangle();
//	if(GLEW_VERSION_4_0) printf("Soporte para 4.0\n");
//	printf("%s\n", glewGetString(GLEW_VERSION));
//	printf("%s\n", glGetString(GL_VERSION));
	glClearColor(0.6, 0.7, 0.8, 1.0);
	glutMainLoop();
	return 0;
}
*/
