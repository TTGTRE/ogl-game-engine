#version 430
uniform sampler2D sampler;
in vec2 fTexCoord;
out vec4 color;
void main(void) {
    color = texture(sampler, fTexCoord.st);
}