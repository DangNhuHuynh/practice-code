//
// Created by danghuynh on 19/07/2017.
//

#include <cstring>
#include "String.hpp"

using namespace dtnh;

void String::reAllocate() {
   if (this->size == this->capacity - 1) {
       this->capacity = this->capacity * 2;
       char * holder = new char[this->capacity];

       size_t index;
       for (index = 0; index < this->size; index++) {
           holder[index] = this->original[index];
       }

       delete[] this->original;
       this->original = holder;
       this->original[index] = '\0';
   }
}

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

String::String(char target, size_t size) {
    this->size = size;
    this->capacity = this->capacity * 2;
    this->original = new char[this->capacity];

    size_t index;
    for (index = 0; index < this->size; index++) {
        this->original[index] = target;
    }
    this->original[index] = '\0';
}

String::~String() {
  delete[] this->original;
}

size_t String::getSize() const {
    return this->size;
}

size_t String::getCapacity() const {
    return this->capacity;
}