//
// Created by Tre on 6/19/2020.
//

#ifndef OGLEXPERIMENTS_TRIPLE_CPP
#define OGLEXPERIMENTS_TRIPLE_CPP

#include "Triple.h"

template<class T>
T Triple<T>::operator[](int i) {
    return *((reinterpret_cast<T *>(this)) + i);
}

#endif