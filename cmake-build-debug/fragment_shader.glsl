#version 430

out vec4 color;

layout(binding = 0) uniform sampler2D samp;
in vec2 tc;

void main(void){
    color = texture(samp, tc);
}