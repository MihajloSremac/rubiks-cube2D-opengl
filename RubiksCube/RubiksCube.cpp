#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <map>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>   
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>    
#include "CubeScramble.h"
#include "TextRender.h"
#include "Timer.h"
#include "Load2D.h"


unsigned int compileShader(GLenum type, const char* source);
unsigned int createShader(const char* vsSource, const char* fsSource);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
string printTime(double elapsedTime);
void ColorBackground(float x, float y, float width, float height, float r, float g, float b, float a);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const float targetFrameTime = 1.0f / 60.0f;
string scramble = "";

float xcube[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.15, 0.15, 0.15, 0.25, 0.25, 0.35, 0.35, 0.35, 0.50, 0.50, 0.50, 0.60, 0.60, 0.70, 0.70, 0.70, -0.55, -0.55, -0.55, -0.45, -0.45, -0.35, -0.35, -0.35, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.1, -0.1, -0.1, -0.1, -0.1, -0.1 };
float ycube[] = { 0.45, 0.35, 0.25, 0.1, 0.0, -0.1, -0.25, -0.35, -0.45, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.1, 0.0, -0.1, 0.1, -0.1, 0.1, 0.0, -0.1, 0.45, 0.35, 0.25, 0.1, 0.0, -0.1, -0.25, -0.35, -0.45, 0.45, 0.25, 0.1, -0.1, -0.25, -0.45 };

CubeScramble cubeScramble;
Timer timer;
Load2D load2D;

int main(void)
{
	if (!glfwInit()) {
		cout << "Greska pri inicijalizaciji GLFW!" << endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	unsigned int wWidth = 1200;
	unsigned int wHeight = 850;
	const char wTitle[] = "Rubik's Cube Simulator";
	window = glfwCreateWindow(wWidth, wHeight, wTitle, NULL, NULL);

	if (window == NULL)
	{
		cout << "Prozor nije napravljen! :(\n";
		glfwTerminate();
		return 2;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, keyCallback);
	if (glewInit() != GLEW_OK)
	{
		cout << "GLEW nije mogao da se ucita! :'(\n";
		return 3;
	}

	//generisanja
	unsigned int VAO[55];
	glGenVertexArrays(55, VAO);

	unsigned int VBO[55];
	glGenBuffers(55, VBO);

	load2D.SetupAllCubes(VAO, VBO, xcube, ycube);

	unsigned int basicShader = createShader("basic.vert", "basic.frag");
	unsigned int uPosLoc = glGetUniformLocation(basicShader, "uPos");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	TextRender textRender("font/consolab.ttf", "text.vert", "text.frag", 29);
	TextRender timeTextRender("font/digital-7.ttf", "text.vert", "text.frag", 150);

	scramble = cubeScramble.generateScramble(xcube, ycube);
	while (!glfwWindowShouldClose(window)) {

		int windowWidth, windowHeight;
		glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

		auto frameStart = std::chrono::high_resolution_clock::now();

		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, windowWidth, windowHeight);
		//ColorBackground(0, 770, 1200, 80, 0.5f, 0.5f, 0.5f, 1.0f);
		//tekst
		textRender.RenderText("Sremac Mihajlo RA 138/2021", 30.0f, 30.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
		textRender.RenderText(scramble, 50.0f, 800.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
		timer.Update();
		glm::vec3 color = timer.GetTextColor();
		std::string timerText = std::to_string(timer.GetElapsedTime()).substr(0, 4);
		timeTextRender.RenderText(printTime(timer.GetElapsedTime()), 500.0f, 400.0f, 1.0f, color);

		if (cubeScramble.isSolved(xcube, ycube, timer.IsRunning()))
			timer.Stop();

		glViewport(0.64 * windowWidth, -0.09 * windowHeight, 0.41 * windowWidth, 0.50 * windowHeight);
		glUseProgram(basicShader);	
		//renderovanje 2D kockica
		load2D.RenderAllCubes(VAO, VBO, xcube, ycube, uPosLoc);

		glBindVertexArray(0);
		glUseProgram(0);
		glfwSwapBuffers(window);

		//60FPS 
		auto frameEnd = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> frameDuration = frameEnd - frameStart;
		if (frameDuration.count() < targetFrameTime) {
			std::this_thread::sleep_for(std::chrono::duration<float>(targetFrameTime - frameDuration.count()));
		}
	}

	glDeleteBuffers(55, VBO);
	glDeleteVertexArrays(55, VAO);
	glDeleteProgram(basicShader);

	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	struct KeyAction {
		bool* keyPressed;
		std::function<void()> onRelease;
	};
	static std::unordered_map<int, KeyAction> keyActions = {
		{GLFW_KEY_R, {&cubeScramble.rKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueR(xcube[i], ycube[i]); }}},
		{GLFW_KEY_U, {&cubeScramble.uKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueU(xcube[i], ycube[i]); }}},
		{GLFW_KEY_T, {&cubeScramble.tKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueRPrime(xcube[i], ycube[i]); }}},
		{GLFW_KEY_I, {&cubeScramble.iKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueUPrime(xcube[i], ycube[i]); }}},
		{GLFW_KEY_L, {&cubeScramble.lKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueL(xcube[i], ycube[i]); }}},
		{GLFW_KEY_SEMICOLON, {&cubeScramble.semiColonKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueLPrime(xcube[i], ycube[i]); }}},
		{GLFW_KEY_F, {&cubeScramble.fKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueF(xcube[i], ycube[i]); }}},
		{GLFW_KEY_G, {&cubeScramble.gKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueFPrime(xcube[i], ycube[i]); }}},
		{GLFW_KEY_D, {&cubeScramble.dKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueD(xcube[i], ycube[i]); }}},
		{GLFW_KEY_S, {&cubeScramble.sKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueDPrime(xcube[i], ycube[i]); }}},
		{GLFW_KEY_B, {&cubeScramble.bKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueB(xcube[i], ycube[i]); }}},
		{GLFW_KEY_N, {&cubeScramble.nKeyPressed, []() { for (int i = 0; i < 48; i++) cubeScramble.updateValueBPrime(xcube[i], ycube[i]); }}},
		{GLFW_KEY_BACKSPACE, {&cubeScramble.backspacePressed, []() { cubeScramble.ResetCube(xcube, ycube); }}},
		{GLFW_KEY_LEFT_SHIFT, {&cubeScramble.scramblePressed, []() {
			scramble = cubeScramble.generateScramble(xcube, ycube);
		}}},
	};

	if (keyActions.find(key) != keyActions.end()) {
		auto& actionData = keyActions[key];
		if (action == GLFW_PRESS && !(*actionData.keyPressed)) {
			*actionData.keyPressed = true;
		}
		else if (action == GLFW_RELEASE && *actionData.keyPressed) {
			actionData.onRelease();
			*actionData.keyPressed = false;
		}
	}

	timer.KeyCallback(key, action);
}

unsigned int compileShader(GLenum type, const char* source) {

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

string printTime(double elapsedTime) {
	// Calculate minutes, seconds, and milliseconds
	int minutes = static_cast<int>(elapsedTime) / 60;
	int seconds = static_cast<int>(elapsedTime) % 60;
	int milliseconds = static_cast<int>((elapsedTime - static_cast<int>(elapsedTime)) * 100);

	// Format the output string
	std::ostringstream timeStream;
	if (minutes > 0) {
		// If minutes > 0, include minutes in the format
		timeStream << minutes << ":"
			<< std::setfill('0') << std::setw(2) << seconds << ".";
	}
	else {
		// If minutes == 0, exclude the "0:" prefix
		timeStream << seconds << ".";
	}
	timeStream << std::setfill('0') << std::setw(2) << milliseconds;

	return timeStream.str();
}

void ColorBackground(float x, float y, float width, float height, float r, float g, float b, float a) {
	glEnable(GL_SCISSOR_TEST);
	glScissor(x, y, width, height);
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

