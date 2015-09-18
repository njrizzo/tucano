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
uniform bool gooshenable;
	 
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

    if (gooshenable) {

        vec3 u_objectColor = vec3(1, 1, 1);
        vec3 u_coolColor = vec3(159.0f/255, 148.0f/255, 255.0f/255);
        vec3 u_warmColor = vec3(255.0f/255, 75.0f/255, 75.0f/255);

        float u_alpha = 0.25;
        float u_beta = 0.5;

        ///////////////////////////////////////////////////////////

           // intensity of diffuse lighting [-1, 1]
           float diffuseLighting = dot(lightDirection, normal);
           // map intensity of lighting from range [-1; 1] to [0, 1]
           diffuseLighting = (1.0 + diffuseLighting)/2;

           //////////////////////////////////////////////////////////////////

           // cool color mixed with color of the object
           vec3 coolColorMod = u_coolColor + color.rgb /*u_objectColor*/ * u_alpha;
           // warm color mixed with color of the object
           vec3 warmColorMod = u_warmColor + color.rgb /* u_objectColor */ * u_beta;
           // interpolation of cool and warm colors according
           // to lighting intensity. The lower the light intensity,
           // the larger part of the cool color is used
           vec3 colorOut = mix(coolColorMod, warmColorMod, diffuseLighting);

           //////////////////////////////////////////////////////////////////

           // save color
           out_Color.rgb = colorOut;
           out_Color.a = 1.0;


    }else {
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

}


