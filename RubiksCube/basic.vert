#version 330 core

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec4 inCol;

out vec4 chCol;
uniform vec2 uPos;

void main()
{
	gl_Position = vec4(inPos +  uPos, 0.3, 1.0);
	chCol = inCol;
}