#include "2DCube.h"
#include <iostream> 

RubiksCube2D::RubiksCube2D() {
    defineCube();
}


void RubiksCube2D::defineCube() {
    // Front face at z = 1.0f
    float frontFaceZ = 1.0f;
    for (int i = 0; i < 9; i++) {
        float x = (i % 3) - 1;  // -1 to 1 for x-axis
        float y = (i / 3) - 1;  // -1 to 1 for y-axis
        cubeVertices[0][i][0] = { x - 0.5f, y - 0.5f, frontFaceZ, 1.0f, 0.0f, 0.0f }; // Red square vertex
        cubeVertices[0][i][1] = { x + 0.5f, y - 0.5f, frontFaceZ, 1.0f, 0.0f, 0.0f };
        cubeVertices[0][i][2] = { x - 0.5f, y + 0.5f, frontFaceZ, 1.0f, 0.0f, 0.0f };
        cubeVertices[0][i][3] = { x + 0.5f, y + 0.5f, frontFaceZ, 1.0f, 0.0f, 0.0f };
    }

    // Top face at y = 1.0f
    float topFaceY = 1.0f;
    for (int i = 0; i < 9; i++) {
        float x = (i % 3) - 1;
        float z = (i / 3) - 1;
        cubeVertices[1][i][0] = { x - 0.5f, topFaceY, z - 0.5f, 0.0f, 0.0f, 1.0f }; // Blue square vertex
        cubeVertices[1][i][1] = { x + 0.5f, topFaceY, z - 0.5f, 0.0f, 0.0f, 1.0f };
        cubeVertices[1][i][2] = { x - 0.5f, topFaceY, z + 0.5f, 0.0f, 0.0f, 1.0f };
        cubeVertices[1][i][3] = { x + 0.5f, topFaceY, z + 0.5f, 0.0f, 0.0f, 1.0f };
    }

    // Left face at x = -1.0f
    for (int i = 0; i < 9; i++) {
        float y = (i % 3) - 1;
        float z = (i / 3) - 1;
        cubeVertices[2][i][0] = { -1.0f, y - 0.5f, z - 0.5f, 0.0f, 1.0f, 0.0f }; // Green square vertex
        cubeVertices[2][i][1] = { -1.0f, y + 0.5f, z - 0.5f, 0.0f, 1.0f, 0.0f };
        cubeVertices[2][i][2] = { -1.0f, y - 0.5f, z + 0.5f, 0.0f, 1.0f, 0.0f };
        cubeVertices[2][i][3] = { -1.0f, y + 0.5f, z + 0.5f, 0.0f, 1.0f, 0.0f };
    }

    // Right face at x = 1.0f
    for (int i = 0; i < 9; i++) {
        float y = (i % 3) - 1;
        float z = (i / 3) - 1;
        cubeVertices[3][i][0] = { 1.0f, y - 0.5f, z - 0.5f, 1.0f, 1.0f, 0.0f }; // Yellow square vertex
        cubeVertices[3][i][1] = { 1.0f, y + 0.5f, z - 0.5f, 1.0f, 1.0f, 0.0f };
        cubeVertices[3][i][2] = { 1.0f, y - 0.5f, z + 0.5f, 1.0f, 1.0f, 0.0f };
        cubeVertices[3][i][3] = { 1.0f, y + 0.5f, z + 0.5f, 1.0f, 1.0f, 0.0f };
    }

    // Bottom face at y = -1.0f
    float bottomFaceY = -1.0f;
    for (int i = 0; i < 9; i++) {
        float x = (i % 3) - 1;
        float z = (i / 3) - 1;
        cubeVertices[4][i][0] = { x - 0.5f, bottomFaceY, z - 0.5f, 0.5f, 0.5f, 0.5f }; // Gray square vertex
        cubeVertices[4][i][1] = { x + 0.5f, bottomFaceY, z - 0.5f, 0.5f, 0.5f, 0.5f };
        cubeVertices[4][i][2] = { x - 0.5f, bottomFaceY, z + 0.5f, 0.5f, 0.5f, 0.5f };
        cubeVertices[4][i][3] = { x + 0.5f, bottomFaceY, z + 0.5f, 0.5f, 0.5f, 0.5f };
    }

    // Back face at z = -1.0f
    float backFaceZ = -1.0f;
    for (int i = 0; i < 9; i++) {
        float x = (i % 3) - 1;
        float y = (i / 3) - 1;
        cubeVertices[5][i][0] = { x - 0.5f, y - 0.5f, backFaceZ, 1.0f, 1.0f, 1.0f }; // White square vertex
        cubeVertices[5][i][1] = { x + 0.5f, y - 0.5f, backFaceZ, 1.0f, 1.0f, 1.0f };
        cubeVertices[5][i][2] = { x - 0.5f, y + 0.5f, backFaceZ, 1.0f, 1.0f, 1.0f };
        cubeVertices[5][i][3] = { x + 0.5f, y + 0.5f, backFaceZ, 1.0f, 1.0f, 1.0f };
    }
}


// Function to render the cube
void RubiksCube2D::renderCube() {
    // Iterate through the cube's faces and draw vertices (using OpenGL, DirectX, etc.)
    for (int face = 0; face < 6; face++) {
        for (int square = 0; square < 9; square++) {
            for (int vertex = 0; vertex < 4; vertex++) {
                // This is a placeholder for how you'd render the vertices in OpenGL
                // Use your rendering API to draw the vertices here
                // For example, in OpenGL, you'd use glVertex3f() to define each vertex in space
                std::cout << "Vertex " << vertex << " for square " << square
                    << " on face " << face << ": "
                    << cubeVertices[face][square][vertex].x << ", "
                    << cubeVertices[face][square][vertex].y << ", "
                    << cubeVertices[face][square][vertex].z << "\n";
            }
        }
    }
}
