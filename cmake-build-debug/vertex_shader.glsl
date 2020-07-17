#version 430
layout(location = 0) in vec2 position;
uniform float xPos;
uniform float yPos;
uniform float scale;
void main(void) {
    gl_Position=vec4((position.x + xPos) * scale, (position.y + yPos) * scale, 1.0, 1.0);
}