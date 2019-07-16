#version 430
in vec3 position;
in vec2 vTexCoord;
out vec2 fTexCoord;
uniform mat4 view_matrix;
uniform mat4 model_matrix;
uniform mat4 rotation_matrix;
uniform mat4 perspective_matrix;
void main(void) {
    gl_Position = perspective_matrix * view_matrix * model_matrix * rotation_matrix * vec4(position, 1.0);
    fTexCoord = vTexCoord;
}