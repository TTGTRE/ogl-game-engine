#version 430
layout(location=0) in vec2 position;
uniform vec3 color;
void main(void) {
    gl_Position=vec4(position,1.0,1.0);
}