//
// Created by Tre on 6/15/2020.
//

#ifndef OGLEXPERIMENTS_MODELSQUARE_CPP
#define OGLEXPERIMENTS_MODELSQUARE_CPP

namespace ModelInfo {

    enum {
        SQUARE_VERTEX_BUFFER_INDEX,
        SQUARE_TEXTURE_BUFFER_INDEX,
        GRID_VERTEX_BUFFER_INDEX
    };

    static int constexpr SQUARE_NUM_VERTICES = 12;
    static int constexpr SQUARE_NUM_TEX_COORDS = 12;
    static float const SQUARE_VERTICES[SQUARE_NUM_VERTICES] = {
            // First top left half of square
            -0.5f, 0.5f,
            0.5f, 0.5f,
            -0.5f, -0.5f,
            // Second bottom right half of square
            -0.5f, -0.5f,
            0.5f, 0.5f,
            0.5f, -0.5f
    };
    static float const SQUARE_TEX_COORDS[SQUARE_NUM_TEX_COORDS] = {
            // First top left half of square
            0, 0,
            1, 0,
            0, 1,
            // Second bottom right half of square
            0, 1,
            1, 0,
            1, 1
    };
}

#endif //OGLEXPERIMENTS_MODELSQUARE_CPP
