#version 430
	 
in vec4 color;
in vec3 normal;
in vec4 vert;

out vec4 out_Color;

uniform mat4 lightViewMatrix;
uniform float quantizationLevel;
uniform vec4 normalcolor;
	 
void main(void)
{

    vec3 lightDirection = (lightViewMatrix * vec4(0.0, 0.0, 1.0, 0.0)).xyz;
    lightDirection = normalize(lightDirection);

    vec3 lightReflection = reflect(-lightDirection, normal);
    vec3 eyeDirection = -normalize(vert.xyz);
    float shininess = 100.0;

    vec4 diffuseLight = color * max(dot(lightDirection, normal), 0.0);
    vec4 specularLight = vec4(1.0) *  max(pow(dot(lightReflection, eyeDirection), shininess), 0.0);

    float intensity_light = dot(lightDirection, normal);
    float intensity_eyes  = dot(eyeDirection, normal);

    vec3 currentColor = vec3(diffuseLight.xyz + specularLight.xyz);

    // color quantization for toon effect:

    currentColor = floor(0.5 + (quantizationLevel * currentColor)) / quantizationLevel;

    if ( intensity_eyes >= 0.95 )
        out_Color = normalcolor;

    if ( intensity_light >= 0.95 )
        out_Color = vec4(0.0,0.0,1.0,1.0);
    if ( intensity_eyes < 0.95 && intensity_light < 0.95)
        out_Color = vec4(currentColor, 1.0);

}


