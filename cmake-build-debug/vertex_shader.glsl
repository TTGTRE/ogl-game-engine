#version 430
in vec3 position;
in vec3 vColor;
out vec4 fColor;
uniform mat4 view_matrix;
uniform mat4 model_matrix;
uniform mat4 rotation_matrix;
uniform mat4 perspective_matrix;
void main(void) {
    gl_Position = perspective_matrix * view_matrix * model_matrix * rotation_matrix * vec4(position, 1.0);
    fColor = vec4(vColor, 1.0f);
}