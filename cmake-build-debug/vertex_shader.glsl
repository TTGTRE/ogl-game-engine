#version 430
in vec3 position;
out vec4 varyingColor;
uniform mat4 view_matrix;
uniform mat4 model_matrix;
uniform mat4 rotation_matrix;
uniform mat4 perspective_matrix;
void main(void) {
    gl_Position = perspective_matrix * view_matrix * model_matrix * rotation_matrix * vec4(position, 1.0);
    if (position.x > 0) varyingColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    else if (position.z > 0) varyingColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
    else varyingColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);
}