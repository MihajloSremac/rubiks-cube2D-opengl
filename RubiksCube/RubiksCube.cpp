#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include <GL/glew.h>
#include <GLFW/glfw3.h>


unsigned int compileShader(GLenum type, const char* source);
unsigned int createShader(const char* vsSource, const char* fsSource);
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

float ycube1 = 0.0;
float xcube1 = 0.0;

float ycube2 = 0.2;
float xcube2 = 0.0;

float ycube3 = -0.2;
float xcube3 = 0.0;

float ycube4 = 0.0;
float xcube4 = 0.0;

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
		std::cout << "Prozor nije napravljen! :(\n";
		glfwTerminate();
		return 2;
	}

	glfwMakeContextCurrent(window);


	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW nije mogao da se ucita! :'(\n";
		return 3;
	}

	float cube1[] = {

		-0.1, -0.1,     1.0, 0.0, 0.0, 1.0,
		-0.1, 0.1,      1.0, 0.0, 0.0, 1.0,
		0.1, -0.1,      1.0, 0.0, 0.0, 1.0,
		0.1, 0.1,       1.0, 0.0, 0.0, 1.0,

	};

	float cube2[] = {

		-0.1, -0.1,      0.0, 1.0, 0.0, 1.0,
		-0.1, 0.1,       0.0, 1.0, 0.0, 1.0,
		0.1, -0.1,       0.0, 1.0, 0.0, 1.0,
		0.1, 0.1,        0.0, 1.0, 0.0, 1.0,

	};

	float cube3[] = {

		-0.1, -0.1,      0.0, 0.0, 1.0, 1.0,
		-0.1, 0.1,       0.0, 0.0, 1.0, 1.0,
		0.1, -0.1,       0.0, 0.0, 1.0, 1.0,
		0.1, 0.1,        0.0, 0.0, 1.0, 1.0,

	};

	//float cube4[] = {

	//	-0.3, 0.1,       1.0, 1.0, 0.0, 1.0,
	//	-0.3, 0.3,       1.0, 1.0, 0.0, 1.0,
	//	-0.1, 0.1,	     1.0, 1.0, 0.0, 1.0,
	//	-0.1, 0.3,        1.0, 1.0, 0.0, 1.0,

	//};

	unsigned int stride = 6 * sizeof(float);

	//generisanja
	unsigned int VAO[4];
	glGenVertexArrays(4, VAO);

	unsigned int VBO[4];
	glGenBuffers(4, VBO);
	

	//bindovanja
	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube1), cube1, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube2), cube2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO[2]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube3), cube3, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	/*glBindVertexArray(VAO[3]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube4), cube4, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);*/


	unsigned int basicShader = createShader("basic.vert", "basic.frag");
	unsigned int uPosLoc = glGetUniformLocation(basicShader, "uPos");
	
	glfwSetKeyCallback(window, keyCallback);


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(basicShader);


		glUniform2f(uPosLoc, xcube1, ycube1);
		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(cube1) / stride);

		glUniform2f(uPosLoc, xcube2, ycube2);
		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(cube2) / stride);

		glUniform2f(uPosLoc, xcube3, ycube3);
		glBindVertexArray(VAO[2]);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(cube2) / stride);

		/*glUniform2f(uPosLoc, xcube4, ycube4);
		glBindVertexArray(VAO[3]);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(cube4) / stride);*/

		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(window);
	}

	glDeleteBuffers(2, VBO);
	glDeleteVertexArrays(2, VAO);
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

			UpdateValueR(xcube1, ycube1);
			UpdateValueR(xcube2, ycube2);
			UpdateValueR(xcube3, ycube3);

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

			UpdateValueU(xcube1, ycube1);
			UpdateValueU(xcube2, ycube2);
			UpdateValueU(xcube3, ycube3);

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

			UpdateValueRPrime(xcube1, ycube1);
			UpdateValueRPrime(xcube2, ycube2);
			UpdateValueRPrime(xcube3, ycube3);

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

			UpdateValueUPrime(xcube1, ycube1);
			UpdateValueUPrime(xcube2, ycube2);
			UpdateValueUPrime(xcube3, ycube3);

			iKeyPressed = false;
		}
	}
}


void UpdateValueR(float& xcube, float& ycube) {
	if (ycube < 0.2 && xcube == 0)
		ycube += 0.2;
	else if (ycube > 0.2 && xcube == 0)
		ycube = -0.2;
}

void UpdateValueRPrime(float& xcube, float& ycube) {
	if (ycube > -0.2 && xcube == 0)
		ycube -= 0.2;
	else if (ycube < -0.2 && xcube == 0)
		ycube = 0.2;
}

void UpdateValueU(float& xcube, float& ycube) {
	if (xcube > -0.4 && ycube > 0.2)
		xcube -= 0.2f;
	else if (xcube < -0.4 && ycube > 0.2)
		xcube = 0.0;
}

void UpdateValueUPrime(float& xcube, float& ycube) {
	if (xcube < 0 && ycube > 0.2)
		xcube += 0.2f;
	else if (xcube == 0.0 && ycube > 0.2)
		xcube = -0.4;
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
