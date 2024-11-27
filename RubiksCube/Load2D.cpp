#include "Load2D.h"
#include "CubeScramble.h"

CubeScramble cubeNotation;

Load2D::Load2D(){}

void SetupCube(GLuint& vao, GLuint& vbo, float* data, size_t dataSize) {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

	// Postavljanje atributa za pozicije
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Postavljanje atributa za boje
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Load2D::SetupAllCubes(GLuint (&VAO)[55], GLuint(&VBO)[55],float(&xcube)[48], float(&ycube)[48]) {
	SetupCube(VAO[0], VBO[0], cubeNotation.greenCenter, 96);
	SetupCube(VAO[1], VBO[1], cubeNotation.orangeCenter, 96);
	SetupCube(VAO[2], VBO[2], cubeNotation.redCenter, 96);
	SetupCube(VAO[3], VBO[3], cubeNotation.blueCenter, 96);
	SetupCube(VAO[4], VBO[4], cubeNotation.whiteCenter, 96);
	SetupCube(VAO[5], VBO[5], cubeNotation.yellowCenter, 96);
	SetupCube(VAO[6], VBO[6], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[7], VBO[7], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[8], VBO[8], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[9], VBO[9], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[10], VBO[10], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[11], VBO[11], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[12], VBO[12], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[13], VBO[13], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[14], VBO[14], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[15], VBO[15], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[16], VBO[16], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[17], VBO[17], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[18], VBO[18], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[19], VBO[19], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[20], VBO[20], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[21], VBO[21], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[22], VBO[22], cubeNotation.cubeRow234Red, 96);
	SetupCube(VAO[23], VBO[23], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[24], VBO[24], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[25], VBO[25], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[26], VBO[26], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[27], VBO[27], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[28], VBO[28], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[29], VBO[29], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[30], VBO[30], cubeNotation.cubeRow567Blue, 96);
	SetupCube(VAO[31], VBO[31], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[32], VBO[32], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[33], VBO[33], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[34], VBO[34], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[35], VBO[35], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[36], VBO[36], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[37], VBO[37], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[38], VBO[38], cubeNotation.cubeRow8910Orange, 96);
	SetupCube(VAO[39], VBO[39], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[40], VBO[40], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[41], VBO[41], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[42], VBO[42], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[43], VBO[43], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[44], VBO[44], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[45], VBO[45], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[46], VBO[46], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[47], VBO[47], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[48], VBO[48], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[49], VBO[49], cubeNotation.cubeRow11121White, 96);
	SetupCube(VAO[50], VBO[50], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[51], VBO[51], cubeNotation.cubeRow11121Green, 96);
	SetupCube(VAO[52], VBO[52], cubeNotation.cubeRow11121Yellow, 96);
	SetupCube(VAO[53], VBO[53], cubeNotation.cubeRow11121Yellow, 96);

	glBindVertexArray(VAO[54]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[54]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeNotation.linesVertices), cubeNotation.linesVertices, GL_STATIC_DRAW);

	// Postavljanje atributa za pozicije
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Postavljanje atributa za boje
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void RenderCube(GLint uPosLoc, GLfloat x, GLfloat y, GLuint vao, float* center, size_t centerSize, GLuint stride) {
	// Postavite poziciju kroz uniform
	glUniform2f(uPosLoc, x, y);

	// Povežite odgovarajući VAO
	glBindVertexArray(vao);

	// Nacrtajte objekat koristeći glDrawArrays
	glDrawArrays(GL_TRIANGLE_STRIP, 0, centerSize / stride);
}

void Load2D::RenderAllCubes(GLuint(&VAO)[55], GLuint(&VBO)[55], float(&xcube)[48], float(&ycube)[48], unsigned int uPosLoc) {
	RenderCube(uPosLoc, 0, 0, VAO[0], cubeNotation.greenCenter, 96, 6 * sizeof(float));
	RenderCube(uPosLoc, 0, 0, VAO[1], cubeNotation.orangeCenter, 96, 6 * sizeof(float));
	RenderCube(uPosLoc, 0, 0, VAO[2], cubeNotation.redCenter, 96, 6 * sizeof(float));
	RenderCube(uPosLoc, 0, 0, VAO[3], cubeNotation.blueCenter, 96, 6 * sizeof(float));
	RenderCube(uPosLoc, 0, 0, VAO[4], cubeNotation.whiteCenter, 96, 6 * sizeof(float));
	RenderCube(uPosLoc, 0, 0, VAO[5], cubeNotation.yellowCenter, 96, 6 * sizeof(float));

	//pokretljive stranice
	for (int i = 0; i < 9; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow11121White, 96, 6 * sizeof(float));
	}

	for (int i = 9; i < 15; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow11121Green, 96, 6 * sizeof(float));
	}

	for (int i = 15; i < 21; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow11121Yellow, 96, 6 * sizeof(float));
	}

	for (int i = 21; i < 28; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow234Red, 96, 6 * sizeof(float));
	}

	for (int i = 28; i < 35; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow567Blue, 96, 6 * sizeof(float));
	}

	for (int i = 35; i < 42; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow8910Orange, 96, 6 * sizeof(float));
	}

	for (int i = 42; i < 48; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeNotation.cubeRow11121White, 96, 6 * sizeof(float));
	}

	int numVertices = sizeof(cubeNotation.linesVertices) / (6 * sizeof(float));


	glUniform2f(uPosLoc, 0, 0);
	glBindVertexArray(VAO[54]);
	glLineWidth(3.0);
	for (int i = 0; i < numVertices; i += 2) {
		glDrawArrays(GL_LINE_LOOP, i, 2);
	}
	glLineWidth(1.0);
}


