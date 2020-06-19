#version 430
out vec4 color;
uniform vec3 uColor;
void main(void){
    color=vec4(uColor,1);
//    color=vec4(0,0,1,1);
}