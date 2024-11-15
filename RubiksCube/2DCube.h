#pragma once


struct Vertex {
    float x, y, z;
    float r, g, b; 
};


class RubiksCube2D {
public:
    RubiksCube2D(); 
    void defineCube(); 
    void renderCube(); 

private:
    Vertex cubeVertices[6][9][4]; // 6 faces, 9 squares per face, 4 vertices per square
};
