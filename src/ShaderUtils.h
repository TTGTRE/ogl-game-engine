//
// Created by Tre on 6/28/2020.
//

#ifndef OGLEXPERIMENTS_SHADERUTILS_H
#define OGLEXPERIMENTS_SHADERUTILS_H

//
// Created by Tre on 5/20/2020.
//

#include <string>
#include <iostream>
#include <fstream>
#include <glew.h>

using namespace std;

string readShaderSource(const char *filePath);

void printShaderLog(GLuint shader);

void printProgramLog(GLuint program);

bool checkOpenGLError();

bool getCompileStatus(GLuint shader);

GLuint createShaderProgram(const char *vertexPath, const char *fragmentPath);

#endif //OGLEXPERIMENTS_SHADERUTILS_H
