//
// Created by Tre on 7/13/2019.
//

#ifndef OGLEXPERIMENTS_CUBE_H
#define OGLEXPERIMENTS_CUBE_H


class cube {

    float x, y, z;

public:
    void draw(float x, float y, float z);
    float loc_x();
    float loc_y();
    float loc_z();
};


#endif //OGLEXPERIMENTS_CUBE_H
