#version 330 core
out vec4 FragColor;

vec2 u_resolution = vec2(800,600);

void main() 
{
	vec2 st = gl_FragCoord.xy/u_resolution;
	FragColor = vec4(st.x,st.y,0.0,1.0);
}