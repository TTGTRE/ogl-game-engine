#version 430
layout(location=0) in vec2 position;
uniform float uScale;
void main(void) {
    gl_Position=vec4(position*uScale, 1.0, 1.0);
}