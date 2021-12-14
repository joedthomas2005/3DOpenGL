#version 330 core
out vec4 FragColor;
in vec3 vertexColor;
in vec3 TexCoord;
in float cubeMap;

uniform sampler2D myTexture;
uniform samplerCube map;

void main() {
	if(cubeMap > 0.5)
	{
		FragColor = texture(map, TexCoord) * vec4(vertexColor, 1.0);
	}
	else{
		FragColor = texture(myTexture, vec2(TexCoord.x, TexCoord.y)) * vec4(vertexColor, 1.0);
	}
}
