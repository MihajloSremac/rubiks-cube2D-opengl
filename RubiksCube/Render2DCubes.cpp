

#include "Render2DCubes.h"

//NEPOMERIVI KVADRATI - CENTRI - 6 komada
float greenCenter[] = {

	-0.225, 0.05,      0.0, 1.0, 0.0, 1.0,
	-0.225, -0.05,       0.0, 1.0, 0.0, 1.0,
	-0.125, 0.05,       0.0, 1.0, 0.0, 1.0,
	-0.125, -0.05,        0.0, 1.0, 0.0, 1.0,

};

float orangeCenter[] = {
	-0.575, 0.05,       1.0, 0.5, 0.0, 1.0,
	-0.575, -0.05,       1.0, 0.5, 0.0, 1.0,
	-0.475, 0.05,	     1.0, 0.5, 0.0, 1.0,
	-0.475, -0.05,        1.0, 0.5, 0.0, 1.0,
};

float redCenter[] = {
	0.125, 0.05,       1.0, 0.0, 0.0, 1.0,
	0.125, -0.05,       1.0, 0.0, 0.0, 1.0,
	0.225, 0.05,	     1.0, 0.0, 0.0, 1.0,
	0.225, -0.05,        1.0, 0.0, 0.0, 1.0,
};

float blueCenter[] = {
	0.475, 0.05,       0.0, 0.0, 1.0, 1.0,
	0.475, -0.05,       0.0, 0.0, 1.0, 1.0,
	0.575, 0.05,	     0.0, 0.0, 1.0, 1.0,
	0.575, -0.05,        0.0, 0.0, 1.0, 1.0,
};

float whiteCenter[] = {
	-0.225, 0.4,       1.0, 1.0, 1.0, 1.0,
	-0.225, 0.3,       1.0, 1.0, 1.0, 1.0,
	-0.125, 0.4,	     1.0, 1.0, 1.0, 1.0,
	-0.125, 0.3,        1.0, 1.0, 1.0, 1.0,
};

float yellowCenter[] = {
	-0.225, -0.4,       1.0, 1.0, 0.0, 1.0,
	-0.225, -0.3,       1.0, 1.0, 0.0, 1.0,
	-0.125, -0.4,	     1.0, 1.0, 0.0, 1.0,
	-0.125, -0.3,        1.0, 1.0, 0.0, 1.0,
};

//POMERIVI KVADRATI
//Svaki kvadrat je jedinstven i imace svoje neke kordinate sa xcubeBroj i ycubeBroj od 1-54
float cubeRow11121White[] = {
	-0.125, 0.05,       1.0, 1.0, 1.0, 1.0,
	-0.125, -0.05,       1.0, 1.0, 1.0, 1.0,
	-0.025, 0.05,	     1.0, 1.0, 1.0, 1.0,
	-0.025, -0.05,        1.0, 1.0, 1.0, 1.0,
};

float cubeRow11121Green[] = {
	-0.125, 0.05,       0.0, 1.0, 0.0, 1.0,
	-0.125, -0.05,       0.0, 1.0, 0.0, 1.0,
	-0.025, 0.05,	     0.0, 1.0, 0.0, 1.0,
	-0.025, -0.05,        0.0, 1.0, 0.0, 1.0,
};

float cubeRow11121Yellow[] = {
	-0.125, 0.05,       1.0, 1.0, 0.0, 1.0,
	-0.125, -0.05,       1.0, 1.0, 0.0, 1.0,
	-0.025, 0.05,	     1.0, 1.0, 0.0, 1.0,
	-0.025, -0.05,        1.0, 1.0, 0.0, 1.0,
};

float cubeRow234Red[] = {
	-0.125, 0.05,       1.0, 0.0, 0.0, 1.0,
	-0.125, -0.05,       1.0, 0.0, 0.0, 1.0,
	-0.025, 0.05,	     1.0, 0.0, 0.0, 1.0,
	-0.025, -0.05,        1.0, 0.0, 0.0, 1.0,
};

float cubeRow567Blue[] = {
	-0.125, 0.05,       0.0, 0.0, 1.0, 1.0,
	-0.125, -0.05,       0.0, 0.0, 1.0, 1.0,
	-0.025, 0.05,	     0.0, 0.0, 1.0, 1.0,
	-0.025, -0.05,        0.0, 0.0, 1.0, 1.0,
};

float cubeRow8910Orange[] = {
	-0.125, 0.05,       1.0, 0.5, 0.0, 1.0,
	-0.125, -0.05,       1.0, 0.5, 0.0, 1.0,
	-0.025, 0.05,	     1.0, 0.5, 0.0, 1.0,
	-0.025, -0.05,        1.0, 0.5, 0.0, 1.0,
};

float linesVertices[] = {
	-0.32, 0.5,       0.2, 0.2, 0.2, 1.0,
	-0.32, 0.2,       0.2, 0.2, 0.2, 1.0,
	-0.22, 0.5,       0.2, 0.2, 0.2, 1.0,
	-0.22, 0.2,       0.2, 0.2, 0.2, 1.0,
	-0.12, 0.5,       0.2, 0.2, 0.2, 1.0,
	-0.12, 0.2,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.5,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.2,       0.2, 0.2, 0.2, 1.0,

	-0.32, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.15,       0.2, 0.2, 0.2, 1.0,
	-0.22, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.22, -0.15,       0.2, 0.2, 0.2, 1.0,
	-0.12, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.12, -0.15,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.15,       0.2, 0.2, 0.2, 1.0,

	-0.32, -0.2,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.5,       0.2, 0.2, 0.2, 1.0,
	-0.22, -0.2,       0.2, 0.2, 0.2, 1.0,
	-0.22, -0.5,       0.2, 0.2, 0.2, 1.0,
	-0.12, -0.2,       0.2, 0.2, 0.2, 1.0,
	-0.12, -0.5,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.2,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.5,       0.2, 0.2, 0.2, 1.0,

	-0.67, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.67, -0.15,       0.2, 0.2, 0.2, 1.0,
	-0.57, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.57, -0.15,       0.2, 0.2, 0.2, 1.0,
	-0.47, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.47, -0.15,       0.2, 0.2, 0.2, 1.0,
	-0.37, 0.15,       0.2, 0.2, 0.2, 1.0,
	-0.37, -0.15,       0.2, 0.2, 0.2, 1.0,

	0.03, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.03, -0.15,       0.2, 0.2, 0.2, 1.0,
	0.13, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.13, -0.15,       0.2, 0.2, 0.2, 1.0,
	0.23, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.23, -0.15,       0.2, 0.2, 0.2, 1.0,
	0.33, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.33, -0.15,       0.2, 0.2, 0.2, 1.0,

	0.38, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.38, -0.15,       0.2, 0.2, 0.2, 1.0,
	0.48, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.48, -0.15,       0.2, 0.2, 0.2, 1.0,
	0.58, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.58, -0.15,       0.2, 0.2, 0.2, 1.0,
	0.67, 0.15,       0.2, 0.2, 0.2, 1.0,
	0.67, -0.15,       0.2, 0.2, 0.2, 1.0,

	-0.32, 0.495,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.495,       0.2, 0.2, 0.2, 1.0,
	-0.32, 0.4,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.4,       0.2, 0.2, 0.2, 1.0,
	-0.32, 0.304,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.304,       0.2, 0.2, 0.2, 1.0,
	-0.32, 0.205,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.205,       0.2, 0.2, 0.2, 1.0,

	-0.32, 0.147,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.147,       0.2, 0.2, 0.2, 1.0,
	-0.32, 0.052,       0.2, 0.2, 0.2, 1.0,
	-0.02, 0.052,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.05,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.05,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.147,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.147,       0.2, 0.2, 0.2, 1.0,

	-0.32, -0.205,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.205,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.304,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.304,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.4,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.4,       0.2, 0.2, 0.2, 1.0,
	-0.32, -0.495,       0.2, 0.2, 0.2, 1.0,
	-0.02, -0.495,       0.2, 0.2, 0.2, 1.0,

	-0.67, 0.147,       0.2, 0.2, 0.2, 1.0,
	-0.37, 0.147,       0.2, 0.2, 0.2, 1.0,
	-0.67, 0.052,       0.2, 0.2, 0.2, 1.0,
	-0.37, 0.052,       0.2, 0.2, 0.2, 1.0,
	-0.67, -0.05,       0.2, 0.2, 0.2, 1.0,
	-0.37, -0.05,       0.2, 0.2, 0.2, 1.0,
	-0.67, -0.147,       0.2, 0.2, 0.2, 1.0,
	-0.37, -0.147,       0.2, 0.2, 0.2, 1.0,

	0.03, 0.147,       0.2, 0.2, 0.2, 1.0,
	0.33, 0.147,       0.2, 0.2, 0.2, 1.0,
	0.03, 0.052,       0.2, 0.2, 0.2, 1.0,
	0.33, 0.052,       0.2, 0.2, 0.2, 1.0,
	0.03, -0.05,       0.2, 0.2, 0.2, 1.0,
	0.33, -0.05,       0.2, 0.2, 0.2, 1.0,
	0.03, -0.147,      0.2, 0.2, 0.2, 1.0,
	0.33, -0.147,      0.2, 0.2, 0.2, 1.0,

	0.38, 0.147,        0.2, 0.2, 0.2, 1.0,
	0.67, 0.147,		0.2, 0.2, 0.2, 1.0,
	0.38, 0.052,		0.2, 0.2, 0.2, 1.0,
	0.67, 0.052,		0.2, 0.2, 0.2, 1.0,
	0.38, -0.05,		0.2, 0.2, 0.2, 1.0,
	0.67, -0.05,		0.2, 0.2, 0.2, 1.0,
	0.38, -0.147,		0.2, 0.2, 0.2, 1.0,
	0.67, -0.147,		0.2, 0.2, 0.2, 1.0,

};

Render2DCubes::Render2DCubes() {
}

void Render2DCubes::SetupCube(GLuint& vao, GLuint& vbo, float* data, size_t dataSize) {
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

void Render2DCubes::SetupAllCubes(GLuint VAO[], GLuint VBO[]) {
	SetupCube(VAO[0], VBO[0], greenCenter, 96);
	SetupCube(VAO[1], VBO[1], orangeCenter, 96);
	SetupCube(VAO[2], VBO[2], redCenter, 96);
	SetupCube(VAO[3], VBO[3], blueCenter, 96);
	SetupCube(VAO[4], VBO[4], whiteCenter, 96);
	SetupCube(VAO[5], VBO[5], yellowCenter, 96);
	SetupCube(VAO[6], VBO[6], cubeRow11121White, 96);
	SetupCube(VAO[7], VBO[7], cubeRow11121White, 96);
	SetupCube(VAO[8], VBO[8], cubeRow11121White, 96);
	SetupCube(VAO[9], VBO[9], cubeRow11121Green, 96);
	SetupCube(VAO[10], VBO[10], cubeRow11121Green, 96);
	SetupCube(VAO[11], VBO[11], cubeRow11121Green, 96);
	SetupCube(VAO[12], VBO[12], cubeRow11121Yellow, 96);
	SetupCube(VAO[13], VBO[13], cubeRow11121Yellow, 96);
	SetupCube(VAO[14], VBO[14], cubeRow11121Yellow, 96);
	SetupCube(VAO[15], VBO[15], cubeRow234Red, 96);
	SetupCube(VAO[16], VBO[16], cubeRow234Red, 96);
	SetupCube(VAO[17], VBO[17], cubeRow234Red, 96);
	SetupCube(VAO[18], VBO[18], cubeRow234Red, 96);
	SetupCube(VAO[19], VBO[19], cubeRow234Red, 96);
	SetupCube(VAO[20], VBO[20], cubeRow234Red, 96);
	SetupCube(VAO[21], VBO[21], cubeRow234Red, 96);
	SetupCube(VAO[22], VBO[22], cubeRow234Red, 96);
	SetupCube(VAO[23], VBO[23], cubeRow567Blue, 96);
	SetupCube(VAO[24], VBO[24], cubeRow567Blue, 96);
	SetupCube(VAO[25], VBO[25], cubeRow567Blue, 96);
	SetupCube(VAO[26], VBO[26], cubeRow567Blue, 96);
	SetupCube(VAO[27], VBO[27], cubeRow567Blue, 96);
	SetupCube(VAO[28], VBO[28], cubeRow567Blue, 96);
	SetupCube(VAO[29], VBO[29], cubeRow567Blue, 96);
	SetupCube(VAO[30], VBO[30], cubeRow567Blue, 96);
	SetupCube(VAO[31], VBO[31], cubeRow8910Orange, 96);
	SetupCube(VAO[32], VBO[32], cubeRow8910Orange, 96);
	SetupCube(VAO[33], VBO[33], cubeRow8910Orange, 96);
	SetupCube(VAO[34], VBO[34], cubeRow8910Orange, 96);
	SetupCube(VAO[35], VBO[35], cubeRow8910Orange, 96);
	SetupCube(VAO[36], VBO[36], cubeRow8910Orange, 96);
	SetupCube(VAO[37], VBO[37], cubeRow8910Orange, 96);
	SetupCube(VAO[38], VBO[38], cubeRow8910Orange, 96);
	SetupCube(VAO[39], VBO[39], cubeRow11121White, 96);
	SetupCube(VAO[40], VBO[40], cubeRow11121White, 96);
	SetupCube(VAO[41], VBO[41], cubeRow11121White, 96);
	SetupCube(VAO[42], VBO[42], cubeRow11121Green, 96);
	SetupCube(VAO[43], VBO[43], cubeRow11121Green, 96);
	SetupCube(VAO[44], VBO[44], cubeRow11121Green, 96);
	SetupCube(VAO[45], VBO[45], cubeRow11121Yellow, 96);
	SetupCube(VAO[46], VBO[46], cubeRow11121Yellow, 96);
	SetupCube(VAO[47], VBO[47], cubeRow11121Yellow, 96);
	SetupCube(VAO[48], VBO[48], cubeRow11121White, 96);
	SetupCube(VAO[49], VBO[49], cubeRow11121White, 96);
	SetupCube(VAO[50], VBO[50], cubeRow11121Green, 96);
	SetupCube(VAO[51], VBO[51], cubeRow11121Green, 96);
	SetupCube(VAO[52], VBO[52], cubeRow11121Yellow, 96);
	SetupCube(VAO[53], VBO[53], cubeRow11121Yellow, 96);
}

void Render2DCubes::RenderCube(GLuint& vao, GLuint& vbo, float* data, size_t dataSize) {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

	// Postavljanje atributa za pozicije
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Postavljanje atributa za boje
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Render2DCubes::RenderAllCubes(GLuint vao[], GLuint vbo[]) {
	RenderCube(uPosLoc, 0, 0, VAO[0], render2DCubes.greenCenter, 96, stride);
	RenderCube(uPosLoc, 0, 0, VAO[1], orangeCenter, 96, stride);
	RenderCube(uPosLoc, 0, 0, VAO[2], redCenter, 96, stride);
	RenderCube(uPosLoc, 0, 0, VAO[3], blueCenter, 96, stride);
	RenderCube(uPosLoc, 0, 0, VAO[4], whiteCenter, 96, stride);
	RenderCube(uPosLoc, 0, 0, VAO[5], yellowCenter, 96, stride);

	//pokretljive stranice
	for (int i = 0; i < 9; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow11121White, 96, stride);
	}

	for (int i = 9; i < 15; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow11121Green, 96, stride);
	}

	for (int i = 15; i < 21; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow11121Yellow, 96, stride);
	}

	for (int i = 21; i < 28; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow234Red, 96, stride);
	}

	for (int i = 28; i < 35; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow567Blue, 96, stride);
	}

	for (int i = 35; i < 42; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow8910Orange, 96, stride);
	}

	for (int i = 42; i < 48; ++i) {
		RenderCube(uPosLoc, xcube[i], ycube[i], VAO[i + 6], cubeRow11121White, 96, stride);
	}
}