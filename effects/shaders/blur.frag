#version 430
#define pi 3,14159265

//Gaussian Blur with Standard Deviation = 1

uniform sampler2D blurTexture;
uniform int blurRange;

out vec4 out_Color;

void main() {

    vec3 result = vec3(0.0);
    ivec2 texCoord = ivec2(gl_FragCoord.xy);

    //Weights for Gaussian Blur:
    float weight;
    float weightSum = 0.0;

    for(int i = -(blurRange-1)/2 ; i <= (blurRange-1)/2 ; i++)
    {
        for(int j = -(blurRange-1)/2 ; j <= (blurRange-1)/2 ; j++)
        {
            ivec2 offset = ivec2(i, j);
            weight = (1.0/2.0*pi) * exp(-0.5*(offset.x*offset.x + offset.y*offset.y));
            vec4 pixelColor = texelFetch(blurTexture, texCoord + offset, 0);
            weight *= pixelColor.a;
            result += pixelColor.rgb * weight;
            weightSum += weight;
        }
    }

    result /= weightSum;

    out_Color = vec4(result, 1.0);

}
