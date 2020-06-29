//
// Created by Tre on 6/20/2020.
//

#ifndef OGLEXPERIMENTS_SQUAREENTITY_H
#define OGLEXPERIMENTS_SQUAREENTITY_H

class SquareEntity {
    float x, y;
    float scale;
public:
    SquareEntity(float x, float y, float scale);

    float getX() const;

    float getY() const;

    float getScale() const;
};


#endif //OGLEXPERIMENTS_SQUAREENTITY_H
