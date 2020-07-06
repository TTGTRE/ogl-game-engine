#version 430

out vec4 color;

layout(binding = 0) uniform sampler2D samp;
in vec2 tc;
uniform vec3 uColor;

void main(void){
    //    color = texture(samp, tc);
//    color = vec4(1.0, 1.0, 1.0, 1.0);
    color = vec4(uColor, 1.0);
}