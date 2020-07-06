//
// Created by Tre on 7/5/2020.
//

#ifndef OGLEXPERIMENTS_VERTEXBUFFERS_H
#define OGLEXPERIMENTS_VERTEXBUFFERS_H

#include "EngineConstants.h"

namespace Buffers {

    float *getCoordinateGridBuffer() {

        using namespace EngineConstants;

        float *buffer = new float[GRID_VERTICE_BUFFER_SIZE];

        // Algorithm to generate grid
        int c = 1;
        float currentY = 1.0f;
        for (int i = 0; i < GRID_VERTICE_BUFFER_SIZE / 2; i += 2) {
            if (i % 4 == 0) {
                buffer[i] = -1.0f;
            } else {
                buffer[i] = 1.0f;
            }
            buffer[i + 1] = currentY;
            if (c % 2 == 0) {
                currentY -= COORDINATE_GRID_SCALE;
            }
            c++;
        }

        int d = 1;
        float currentX = 1.0f;
        for (int i = GRID_VERTICE_BUFFER_SIZE / 2; i < GRID_VERTICE_BUFFER_SIZE; i += 2) {
            if (i % 4 == 0) {
                buffer[i + 1] = -1.0f;
            } else {
                buffer[i + 1] = 1.0f;
            }
            buffer[i] = currentX;
            if (d % 2 == 0) {
                currentX -= COORDINATE_GRID_SCALE;
            }
            d++;
        }

        return buffer;
    }
}

#endif //OGLEXPERIMENTS_VERTEXBUFFERS_H
