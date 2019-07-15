//
// Created by Tre on 7/14/2019.
//

#include <glew.h>
#include <glfw3.h>
#include "DrawHandle.h"
#include "../GLUtilities.h"

float viewX = 0.0f, viewY = 0.0f, viewZ = 0.0f;

//std::vector<Engine::Model *> modelVector;
GLuint vaObjects[1];
GLuint vbObjects[2];

GLuint shaderProgram;

float *vertices;

bool initialized;
void doPreDrawInit() {
    if (initialized) return;
//    modelVector.push_back(new Engine::Cube(0.0f, 0.0f, -0.5f));

    vertices = new float[108]{
        -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
                1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
                1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
                1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0, 1.0f, -1.0f,
                1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f,
                1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f
    };

    glGenVertexArrays(1, vaObjects);
    glBindVertexArray(vaObjects[0]);

    glGenBuffers(1, vbObjects);
    glBindBuffer(GL_ARRAY_BUFFER, vbObjects[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    std::cout << "Did first time initialization." << std::endl;

    shaderProgram = ShaderMaker::createShaderProgram();

    initialized = true;
}

glm::mat4 vMat, mMat, mvMat, pMat;
GLuint mvLoc, projLoc;

void Engine::DrawHandle::draw() {

    doPreDrawInit();

    glClear(GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram);

    // get the uniform variables for the MV and projection martrices
    mvLoc = glGetUniformLocation(shaderProgram, "mv_matrix");
    projLoc = glGetUniformLocation(shaderProgram, "proj_matrix");

    // build perspective matrix
    pMat = glm::perspective(1.0472f, (float) width / (float) height, 0.0f, 1000.0f); // 1.0472 radians = 60 degrees

    // build view matrix, model matrix, and model-view matrix
    vMat = glm::translate(glm::mat4(1.0f), glm::vec3(-viewX, -viewY, -viewZ));
    mMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f));
    mvMat = vMat * mMat;

    // copy perspective and MV matrices to corresponding uniform variables
    glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvMat));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pMat));

    // associate VBO with the corresponding vertex attribute in the vertex shader
    glBindBuffer(GL_ARRAY_BUFFER, vbObjects[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // adjust OpenGL settings and draw model
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDrawArrays(GL_TRIANGLES, 0, 36);

//    glClear(GL_COLOR_BUFFER_BIT);
//    glClear(GL_DEPTH_BUFFER_BIT);
//    std::cout << "Cleared bits." << std::endl;
//
//    glUseProgram(shaderProgram);
//    std::cout << "Shader in use." << std::endl;
//
//    GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "model_matrix");
//    GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "view_matrix");
//    GLuint rotationMatrixLocation = glGetUniformLocation(shaderProgram, "rotation_matrix");
//    GLuint perspectiveMatrixLocation = glGetUniformLocation(shaderProgram, "perspective_matrix");
//
//    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-viewX, -viewY, -viewZ));
//    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), (float) glfwGetTime() * 2.0f, glm::vec3(0.0f, 1.0f, 0.0f));
//    glm::mat4 perspectiveMatrix = glm::perspective(1.0472f, (float) width / (float) height, 0.0f, 1000.0f);

//    auto iterator = modelVector.begin();
//    int index = 0;
//    std::cout << "Total models to draw: " << modelVector.size() << std::endl;
//    while (iterator != modelVector.end()) {
//
//        std::cout << "Beginning draw at resolution " << width << "x" << height << "." << std::endl;
//
//        float modelX = (*iterator)->getX();
//        float modelY = (*iterator)->getY();
//        float modelZ = (*iterator)->getZ();
//        std::cout << "Drawing model at " << modelX << ", " << modelY << ", " << modelZ << std::endl;
//
//        glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(modelX, modelY, modelZ));
//        std::cout << "Matrices created." << std::endl;
//
//        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
//        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
//        glUniformMatrix4fv(rotationMatrixLocation, 1, GL_FALSE, glm::value_ptr(rotationMatrix));
//        glUniformMatrix4fv(perspectiveMatrixLocation, 1, GL_FALSE, glm::value_ptr(perspectiveMatrix));
//        std::cout << "Uniform variables set." << std::endl;
//
//        glBindBuffer(GL_ARRAY_BUFFER, vbObjects[0]);
//        GLint positionLocation = glGetAttribLocation(shaderProgram, "position");
//        glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, 0); // TODO May need to change 5th parameter
//        glEnableVertexAttribArray(positionLocation);
//        std::cout << "Buffers bound. (Index : " << index << ")." << std::endl;
//
//        glEnable(GL_DEPTH_TEST);
//        glDepthFunc(GL_LEQUAL);
//        std::cout << "Pre-draw settings set." << std::endl;
//
//        glDrawArrays(GL_POINTS, 0, sizeof(vertices) / 3);
//        std::cout << "Finished drawing arrays." << std::endl;
//
//        iterator++;
//        index++;
//        std::cout << "Getting ready to draw next model (Index: " << index << ")" << std::endl;
//    }
}

void Engine::DrawHandle::setResolution(int width, int height) {
    this->width = width;
    this->height = height;
}