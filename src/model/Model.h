//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


class Model {

    float *verticeArray;

public:
    Model(float *verticeArray);

    float *getVerticeArray() const;
};


#endif //OGLEXPERIMENTS_MODEL_H
