#version 430
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoord;
layout(binding = 1) uniform sampler2D samp;
uniform float xPos;
uniform float yPos;
uniform float scale;
out vec2 tc;
void main(void) {
    gl_Position=vec4((position.x + xPos) * scale, (position.y + yPos) * scale, 1.0, 1.0);
    tc = texCoord;
}