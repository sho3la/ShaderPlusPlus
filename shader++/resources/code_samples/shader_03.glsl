#version 330 core
out vec4 FragColor;

uniform vec2 Mouse;
#define iMouse Mouse

void main() 
{
	vec2 st = gl_FragCoord.xy/iMouse;
	FragColor = vec4(st.x,st.y,Mouse.x,1.0);
}