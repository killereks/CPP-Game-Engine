#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

out vec2 TexCoord;
out vec3 fragPos;
out vec3 Normal;

//out mat3 TBN;

out vec4 fragPosLight;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 lightProjection;

void main(){
	fragPos = vec3(model * vec4(aPos, 1.0));
	gl_Position = projection * view * vec4(fragPos, 1.0);

	TexCoord = aTexCoord;

	fragPosLight = lightProjection * vec4(fragPos, 1.0);

	Normal = mat3(transpose(inverse(model))) * aNormal;

	/*vec3 T = normalize(vec3(model * vec4(aTangent, 0.0)));
	vec3 B = normalize(vec3(model * vec4(aBitangent, 0.0)));
	vec3 N = normalize(vec3(model * vec4(aNormal, 0.0)));

	TBN = mat3(T, B, N);*/
}