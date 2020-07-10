#version 330 core
out vec4 FragColor;

uniform vec2 Resolution;
#define iResolution Resolution

void main() 
{
	vec2 st = gl_FragCoord.xy/iResolution;
	FragColor = vec4(st.x,st.y,0.0,1.0);
}