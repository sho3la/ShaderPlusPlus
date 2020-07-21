#version 330 core
out vec4 FragColor;

uniform vec2 Resolution;
#define iResolution Resolution

float checker(vec2 uv, float repeats) 
{
	float cx = floor(repeats * uv.x);
	float cy = floor(repeats * uv.y); 
	float result = mod(cx + cy, 2.0);
	return sign(result);
}

void main() 
{
	vec2 st = gl_FragCoord.xy/iResolution;	
	st.x *= iResolution.x / iResolution.y;
	float c = mix(0.8, 1.0, checker(st, 18.0));
	
	FragColor = vec4(c,c,c,1.0);
}