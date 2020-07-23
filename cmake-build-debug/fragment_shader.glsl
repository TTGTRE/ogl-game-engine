#version 430

out vec4 color;

layout(binding = 0) uniform sampler2D sampler;
in vec2 texCoords;

uniform vec3 uColor;

void main(void) {
    color = vec4(uColor, 1.0) * texture(sampler, texCoords);
}