//
// Created by Tre on 6/19/2020.
//

#ifndef OGLEXPERIMENTS_TRIPLE_H
#define OGLEXPERIMENTS_TRIPLE_H


template<class T>
struct Triple {
    T first, second, third;

    T operator[](int i);
};

#include "Triple.cpp"

#endif //OGLEXPERIMENTS_TRIPLE_H
