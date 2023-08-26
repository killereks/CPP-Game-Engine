#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoord;
out vec3 Normal;
out vec3 fragPos;

out vec4 fragPosLight;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 lightProjection;

void main(){
	fragPos = vec3(model * vec4(aPos, 1.0));
	gl_Position = projection * view * vec4(fragPos, 1.0);

	Normal = mat3(transpose(inverse(model))) * aNormal;
	TexCoord = aTexCoord;

	fragPosLight = lightProjection * vec4(fragPos, 1.0);
}