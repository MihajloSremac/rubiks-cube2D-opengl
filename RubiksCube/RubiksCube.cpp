#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include <GL/glew.h>
#include <GLFW/glfw3.h>


unsigned int compileShader(GLenum type, const char* source);
unsigned int createShader(const char* vsSource, const char* fsSource);
void SetupCube(GLuint vao, GLuint vbo, float* data, size_t dataSize);
void RenderCube(GLint uPosLoc, GLfloat x, GLfloat y, GLuint vao, float* center, size_t centerSize, GLuint stride);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void UpdateValueR(float& xcube, float& ycube);
void UpdateValueRPrime(float& xcube, float& ycube);
void UpdateValueU(float& xcube, float& ycube);
void UpdateValueUPrime(float& xcube, float& ycube);

//R rotacija
bool rKeyPressed = false;
bool tKeyPressed = false;

//U rotacija
bool uKeyPressed = false;
bool iKeyPressed = false;

bool rightArrowPressed = false; // Praćenje desne strelice
bool upArrowTriggered = false; // Praćenje redosleda za strelicu gore
bool downArrowTriggered = false; // Praćenje redosleda za strelicu dole

float xcube[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.15, 0.15, 0.15, 0.25, 0.25, 0.35, 0.35, 0.35, 0.50, 0.50, 0.50, 0.60, 0.60, 0.70, 0.70, 0.70, -0.55, -0.55, -0.55, -0.45, -0.45, -0.35, -0.35, -0.35, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.1, -0.1, -0.1, -0.1, -0.1, -0.1};
float ycube[] = {0.45, 0.35, 0.25, 0.1, 0.0, -0.1, -0.25, -0.35, -0.45, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.45, 0.35, 0.25, 0.1, 0.0, -0.1, -0.25, -0.35, -0.45, 0.45, 0.25, 0.1, -0.1, -0.25, -0.45};

int main(void)
{
	if (!glfwInit()) {
		cout << "Greska pri inicijalizaciji GLFW!" << endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	unsigned int wWidth = 700;
	unsigned int wHeight = 700;
	const char wTitle[] = "Rubik's Cube Simulator";
	window = glfwCreateWindow(wWidth, wHeight, wTitle, NULL, NULL);

	if (window == NULL)
	{
		cout << "Prozor nije napravljen! :(\n";
		glfwTerminate();
		return 2;
	}

	glfwMakeContextCurrent(window);


	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW nije mogao da se ucita! :'(\n";
		return 3;
	}

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


	unsigned int stride = 6 * sizeof(float);

	//generisanja
	unsigned int VAO[54];
	glGenVertexArrays(54, VAO);

	unsigned int VBO[54];
	glGenBuffers(54, VBO);


	//bindovanja
		//centri
	{
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
	unsigned int basicShader = createShader("basic.vert", "basic.frag");
	unsigned int uPosLoc = glGetUniformLocation(basicShader, "uPos");

	glfwSetKeyCallback(window, keyCallback);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(basicShader);

		//renderovanje

		//centri
		{
			RenderCube(uPosLoc, 0, 0, VAO[0], greenCenter, 96, stride);
			RenderCube(uPosLoc, 0, 0, VAO[1], orangeCenter, 96, stride);
			RenderCube(uPosLoc, 0, 0, VAO[2], redCenter, 96, stride);
			RenderCube(uPosLoc, 0, 0, VAO[3], blueCenter, 96, stride);
			RenderCube(uPosLoc, 0, 0, VAO[4], whiteCenter, 96, stride);
			RenderCube(uPosLoc, 0, 0, VAO[5], yellowCenter, 96, stride);
		}
		{
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


		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(window);
	}

	glDeleteBuffers(54, VBO);
	glDeleteVertexArrays(54, VAO);
	glDeleteProgram(basicShader);

	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_R)
	{
		if (action == GLFW_PRESS && !rKeyPressed)
		{
			rKeyPressed = true;
		}
		else if (action == GLFW_RELEASE && rKeyPressed)
		{


			for (int i = 0; i < 48; i++)
				UpdateValueR(xcube[i], ycube[i]);

			rKeyPressed = false;
		}
	}
	else if (key == GLFW_KEY_U)
	{
		if (action == GLFW_PRESS && !uKeyPressed)
		{
			uKeyPressed = true;
		}
		else if (action == GLFW_RELEASE && uKeyPressed)
		{

			for (int i = 0; i < 48; i++)
				UpdateValueU(xcube[i], ycube[i]);

			uKeyPressed = false;
		}
	}
	else if (key == GLFW_KEY_T)
	{
		if (action == GLFW_PRESS && !tKeyPressed)
		{
			tKeyPressed = true;
		}
		else if (action == GLFW_RELEASE && tKeyPressed)
		{

			for (int i = 0; i < 48; i++)
				UpdateValueRPrime(xcube[i], ycube[i]);

			tKeyPressed = false;
		}
	}
	else if (key == GLFW_KEY_I)
	{
		if (action == GLFW_PRESS && !iKeyPressed)
		{
			iKeyPressed = true;
		}
		else if (action == GLFW_RELEASE && iKeyPressed)
		{

			for (int i = 0; i < 48; i++)
				UpdateValueUPrime(xcube[i], ycube[i]);

			iKeyPressed = false;
		}
	}
}


void UpdateValueR(float& xcube, float& ycube) {
	if (ycube + 0.34 >= 0.45 && xcube < 0.01 && xcube > -0.01)		
		ycube -= 0.7;		
	else if(xcube < 0.01 && xcube > -0.01)
		ycube += 0.35;
}

void UpdateValueRPrime(float& xcube, float& ycube) {
	if (ycube - 0.34 <= -0.45 && xcube < 0.01 && xcube > -0.01)
		ycube += 0.7;
	else if (xcube < 0.01 && xcube > -0.01)
		ycube -= 0.35;
}

void UpdateValueU(float& xcube, float& ycube) {
	if (xcube + -0.34 < -0.55 && ycube > 0.05 && ycube< 0.15)
		xcube += 1.05;
	else if (ycube > 0.05 && ycube < 0.15)
		xcube -= 0.35;
}

void UpdateValueUPrime(float& xcube, float& ycube) {
	if (xcube + 0.34 > 0.7 && ycube > 0.05 && ycube < 0.15)
		xcube -= 1.05;
	else if (ycube > 0.05 && ycube < 0.15)
		xcube += 0.35;
}

unsigned int compileShader(GLenum type, const char* source) {

	//Uzima kod u fajlu na putanji "source", kompajlira ga i vraca sejder tipa "type"
	//Citanje izvornog koda iz fajla
	string content = "";
	ifstream file(source);
	stringstream ss;

	if (file.is_open()) {
		ss << file.rdbuf();
		file.close();
		cout << "Uspesno procitao fajl sa putanje \"" << source << "\"!" << endl;
	}
	else {
		ss << "";
		cout << "Greska pri citanju fajla sa putanje \"" << source << "\"!" << endl;
	}

	string temp = ss.str();
	const char* sourceCode = temp.c_str(); //Izvorni kod sejdera koji citamo iz fajla na putanji "source"

	int shader = glCreateShader(type); //Napravimo prazan sejder odredjenog tipa (vertex ili fragment)

	int success; //Da li je kompajliranje bilo uspjesno (1 - da)
	char infoLog[512]; //Poruka o gresci (Objasnjava sta je puklo unutar sejdera)
	glShaderSource(shader, 1, &sourceCode, NULL); //Postavi izvorni kod sejdera
	glCompileShader(shader); //Kompajliraj sejder

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success); //Provjeri da li je sejder uspjesno kompajliran
	if (success == GL_FALSE)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog); //Pribavi poruku o gresci
		if (type == GL_VERTEX_SHADER)
			printf("VERTEX");
		else if (type == GL_FRAGMENT_SHADER)
			printf("FRAGMENT");
		printf(" sejder ima gresku! Greska: \n");
		printf(infoLog);
	}
	return shader;
}
unsigned int createShader(const char* vsSource, const char* fsSource)
{
	//Pravi objedinjeni sejder program koji se sastoji od Vertex sejdera ciji je kod na putanji vsSource

	unsigned int program; //Objedinjeni sejder
	unsigned int vertexShader; //Verteks sejder (za prostorne podatke)
	unsigned int fragmentShader; //Fragment sejder (za boje, teksture itd)

	program = glCreateProgram(); //Napravi prazan objedinjeni sejder program

	vertexShader = compileShader(GL_VERTEX_SHADER, vsSource); //Napravi i kompajliraj vertex sejder
	fragmentShader = compileShader(GL_FRAGMENT_SHADER, fsSource); //Napravi i kompajliraj fragment sejder

	//Zakaci verteks i fragment sejdere za objedinjeni program
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program); //Povezi ih u jedan objedinjeni sejder program
	glValidateProgram(program); //Izvrsi provjeru novopecenog programa

	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_VALIDATE_STATUS, &success); //Slicno kao za sejdere
	if (success == GL_FALSE)
	{
		glGetShaderInfoLog(program, 512, NULL, infoLog);
		cout << "Objedinjeni sejder ima gresku! Greska: \n";
		cout << infoLog << std::endl;
	}

	//Posto su kodovi sejdera u objedinjenom sejderu, oni pojedinacni programi nam ne trebaju, pa ih brisemo zarad ustede na memoriji
	glDetachShader(program, vertexShader);
	glDeleteShader(vertexShader);
	glDetachShader(program, fragmentShader);
	glDeleteShader(fragmentShader);

	return program;
}

void SetupCube(GLuint vao, GLuint vbo, float* data, size_t dataSize) {
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

void RenderCube(GLint uPosLoc, GLfloat x, GLfloat y, GLuint vao, float* center, size_t centerSize, GLuint stride) {
	// Postavite poziciju kroz uniform
	glUniform2f(uPosLoc, x, y);

	// Povežite odgovarajući VAO
	glBindVertexArray(vao);

	// Nacrtajte objekat koristeći glDrawArrays
	glDrawArrays(GL_TRIANGLE_STRIP, 0, centerSize / stride);
}



