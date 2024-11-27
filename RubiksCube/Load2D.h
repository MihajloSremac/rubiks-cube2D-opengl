#pragma once
#ifndef LOAD2D_H
#define LOAD2D_H

#include <chrono>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Load2D {
public:
    Load2D();
    void SetupAllCubes(GLuint(&VAO)[55], GLuint(&VBO)[55], float(&xcube)[48], float(&ycube)[48]);
    void RenderAllCubes(GLuint(&VAO)[55], GLuint(&VBO)[55], float(&xcube)[48], float(&ycube)[48], unsigned int uPosLoc);

    
};

#endif // TIMER_H