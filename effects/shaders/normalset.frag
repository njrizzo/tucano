#version 430
	 
in vec4 color;
in vec3 normal;
in vec4 vert;

out vec4 out_Color;

uniform mat4 lightViewMatrix;
uniform float quantizationLevel;
uniform vec4 normalcolor;
uniform bool eyesnormal;
uniform bool lightnormal;
uniform bool cossenoenable;
	 
void main(void){

    float ang;
    float len_eyes, len_light;

    vec3 eyescolor = vec3(0.0,1.0,0.0);
    vec3 lightcolor = vec3(0.0,0.0,1.0);

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

    if ( cossenoenable ) {
        len_eyes = sqrt(eyeDirection.x * eyeDirection.x + eyeDirection.y * eyeDirection.y + eyeDirection.z * eyeDirection.z);
        len_light = sqrt(lightDirection.x * lightDirection.x + lightDirection.y * lightDirection.y + lightDirection.z * lightDirection.z);
        ang = dot(lightDirection, eyeDirection) / (len_eyes * len_light);
    }
    else
        ang = 1;

    if ( !eyesnormal && !lightnormal) {
        out_Color = vec4(currentColor, 1.0);
        out_Color.x = out_Color.x * ang;
        out_Color.y = out_Color.y / ang;
    }

    if ( (intensity_eyes >= 0.95) && eyesnormal)
        out_Color = vec4(eyescolor,1.0);

    if ( (intensity_light >= 0.95) && lightnormal)
        out_Color = vec4(lightcolor,1.0);

    if ((eyesnormal && lightnormal) && (intensity_eyes >= 0.95 && intensity_light >= 0.95))
            out_Color = vec4((eyescolor+lightcolor),1.0);

}


