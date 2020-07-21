#version 430
layout(location = 0) in vec2 position;
uniform float xPos;
uniform float yPos;
uniform float uWidth;
uniform float uHeight;
uniform float scale;
uniform mat4 uProjection;
void main(void) {
    gl_Position = uProjection * vec4((position.x * uWidth) + xPos, (position.y * uHeight) + yPos, 1.0, 1.0);
}