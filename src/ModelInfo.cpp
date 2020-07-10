//
// Created by Tre on 6/15/2020.
//

#ifndef OGLEXPERIMENTS_MODELSQUARE_CPP
#define OGLEXPERIMENTS_MODELSQUARE_CPP

namespace ModelInfo {
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
