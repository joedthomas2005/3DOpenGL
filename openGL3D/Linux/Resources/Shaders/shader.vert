#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

out vec3 vertexColor;
out vec3 TexCoord;
out float cubeMap;
uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;
uniform float isCube;

void main()
{
	gl_Position = projection * view * transform * vec4(aPos, 1.0);
	vertexColor = aColor;
	if(isCube > 0.5){
		TexCoord = aPos;
	}
	else{
		TexCoord = vec3(aTexCoord, 0);
	}
	cubeMap = isCube;
}
