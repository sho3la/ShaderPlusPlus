#version 330 core
out vec4 FragColor;

uniform float time;
#define iTime time

void main() 
{
	FragColor = vec4(sin(time),cos(time),0.1,1.0);
}