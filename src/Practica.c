
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Utils.h"
#include <stdio.h>
#include <time.h>

static float vertexPos[] = { 0.0,  0.9, 0.0,
		             	 	-0.9, -0.9, 0.0,
					         0.9, -0.9, 0.0
};

static float vertexColor[] = {
							1.0, 0.0, 0.0,
							0.0, 1.0, 0.0,
							0.0, 0.0, 1.0
};

#define VERTEX_ARRAYS 1
#define BUFFERS 2
GLuint vertexArrayIds[VERTEX_ARRAYS];
GLuint programId;
GLuint vertexPositionLoc,vertexColorLoc;

static void initShaders() {
	GLuint vShaderId = compileShader("shaders/color_position.vesh",GL_VERTEX_SHADER);
	if(!shaderCompiled(vShaderId)) return;
	GLuint fShaderId = compileShader("shaders/color.fsh",
			                         GL_FRAGMENT_SHADER);
	if(!shaderCompiled(fShaderId)) return;

	programId = glCreateProgram();
	glAttachShader(programId, vShaderId);
	glAttachShader(programId, fShaderId);
	glLinkProgram(programId);

	vertexPositionLoc = glGetAttribLocation(programId,
			                                "vertexPosition");
	vertexColorLoc 	  = glGetAttribLocation(programId,"vertexColor");
}

static void createTriangle() {
	glGenVertexArrays(VERTEX_ARRAYS, vertexArrayIds);
	printf("%d\n", vertexArrayIds[0]); // genera 1
	//crea los buffers
	GLuint bufferIds[BUFFERS];
	glGenBuffers(BUFFERS, bufferIds); // genera 1 y 2
//	glGenBuffers(BUFFERS, bufferIds); // genera 3 y 4
	printf("%d %d\n", bufferIds[0], bufferIds[1]);
	// empieza el de posicion
	glBindVertexArray(vertexArrayIds[0]);
	glBindBuffer(GL_ARRAY_BUFFER, bufferIds[0]);
	glBufferData(GL_ARRAY_BUFFER,
			     sizeof(vertexPos),
			     vertexPos,
				 GL_STATIC_DRAW
	);
	glVertexAttribPointer(vertexPositionLoc, 3,
						  GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexPositionLoc);
	// empieza el de color
	glBindVertexArray(vertexArrayIds[1]);
	glBindBuffer(GL_ARRAY_BUFFER,bufferIds[1]);
	glBufferData(GL_ARRAY_BUFFER,
				 sizeof(vertexColor),
				 vertexColor,
				 GL_STATIC_DRAW);
	glVertexAttribPointer(vertexColorLoc, 3,
							GL_FLOAT,GL_FALSE,0,0);
	glEnableVertexAttribArray(vertexColorLoc);


//	glVertexPointer(3, GL_FLOAT, 0, 0);
//	glEnableClientState(GL_VERTEX_ARRAY);

//	glBindBuffer(GL_ARRAY_BUFFER, bufferIds[1]);
//	glBufferData(GL_ARRAY_BUFFER,
//				 sizeof(vertexColor),
//				 vertexColor,
//				 GL_STATIC_DRAW
//	);
//	glColorPointer(3, GL_FLOAT, 0, 0);
//	glEnableClientState(GL_COLOR_ARRAY);
}

static void exitFunc(unsigned char key, int x, int y) {
	if(key == 27) exit(0);
}

static void displayFunc() {
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(programId);
	glBindVertexArray(vertexArrayIds[0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

 int main(int argc, char **argv) {
//	srand(time(NULL));
//	int apasar = 1 + rand() % 26;
//	printf("A pasar: %d\n", apasar);

	glutInit(&argc, argv);
	int width = 400, height = 400;
	glutInitWindowSize(width, height);
	int wx = (glutGet(GLUT_SCREEN_WIDTH)  - width)  / 2;
	int wy = (glutGet(GLUT_SCREEN_HEIGHT) - height) / 2;
	glutInitWindowPosition(wx, wy);
	glutCreateWindow("Mi primer triangulo con OpenGL");
	glutKeyboardFunc(exitFunc);
	glutDisplayFunc(displayFunc);
	glewInit();
	initShaders();
	createTriangle();
//	if(GLEW_VERSION_4_0) printf("Soporte para 4.0\n");
//	printf("%s\n", glewGetString(GLEW_VERSION));
//	printf("%s\n", glGetString(GL_VERSION));
	glClearColor(0.6, 0.7, 0.8, 1.0);
	glutMainLoop();
	return 0;
}
