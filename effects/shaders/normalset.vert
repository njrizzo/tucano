#version 430
	 
in vec4 in_Position;
in vec3 in_Normal;
in vec4 in_Color;
in vec4 in_Light;

out vec4 color;
out vec3 normal;
out vec4 vert;
	 
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 lightViewMatrix;
uniform bool gooshenable;

uniform bool has_color;
const vec4 default_color = vec4(1.0, 0.0, 0.0, 1.0);
	 
void main(void)
{

        mat4 modelViewMatrix = viewMatrix*modelMatrix;
        mat4 normalMatrix = transpose(inverse(modelViewMatrix));
        normal = normalize(vec3(normalMatrix * vec4(in_Normal,0.0)).xyz);
        vert = modelViewMatrix * in_Position;
        gl_Position = (projectionMatrix * modelViewMatrix) * in_Position;

        if (has_color)
            color = in_Color;
        else
            color = default_color;
}
