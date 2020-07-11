//
// Created by Tre on 7/10/2020.
//

#include "Buffers.h"
#include "WorldProperties.h"

float *Buffers::getCoordinateGridBuffer() {

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
            currentY -= WorldProperties::getEntityWorldScale();
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
            currentX -= WorldProperties::getEntityWorldScale();
        }
        d++;
    }

    return buffer;
}