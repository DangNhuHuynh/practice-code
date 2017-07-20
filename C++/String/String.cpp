//
// Created by danghuynh on 19/07/2017.
//

#include <cstring>
#include "String.hpp"

using namespace dtnh;

String::String() {
    this->original = new char[4];
    this->capacity = 4;
    this->size = 0;
}

String::String(const char *target) {
    this->size = strlen(target);
    this->capacity = this->size * 2;
    this->original = new char[this->capacity];

    size_t index;
    for (index = 0; index < this->size; index++) {
        this->original[index] = target[index];
    }
    this->original[index] = '\0';
}
