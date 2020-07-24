#version 430
layout(location = 0) in vec4 position;
//layout(location = 1) in vec2 _texCoords;
out vec2 texCoords;
uniform mat4 uProjection;
uniform mat4 uModel;
void main(void) {
//    texCoords = _texCoords;
    texCoords = position.zw;
    gl_Position = uProjection * uModel * vec4(position.xy, 0.0, 1.0);
}