//
// Created by Tre on 7/5/2020.
//

#ifndef OGLEXPERIMENTS_VERTEXBUFFERS_H
#define OGLEXPERIMENTS_VERTEXBUFFERS_H

#define GRID_VERTICE_BUFFER_SIZE ((1.0f / WorldProperties::getEntityWorldScale() * 2 * 2) * 2 * 2)

namespace Buffers {
    float *getCoordinateGridBuffer();
}

#endif //OGLEXPERIMENTS_VERTEXBUFFERS_H
