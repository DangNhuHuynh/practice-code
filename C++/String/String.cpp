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
    this->capacity = this->size * 2;
    this->original = new char[this->capacity];

    size_t index;
    for (index = 0; index < this->size; index++) {
        this->original[index] = target;
    }
    this->original[index] = '\0';
}

String::String(const String &copyString) {
    this->size = copyString.size;
    this->capacity = copyString.capacity;
    this->original = new char[this->capacity];

    size_t index;
    for (index = 0; index < this->size; index++) {
        this->original[index] = copyString.original[index];
    }
    this->original[index] = '\0';
}

String::~String() {
    this->size = 0;
  delete[] this->original;
}

size_t String::getSize() const {
    return this->size;
}

size_t String::getCapacity() const {
    return this->capacity;
}

char* String::toString() {
    char* result = new char[this->size + 1];

    size_t index;
    for(index = 0; index < this->size; index++) {
        result[index] = this->original[index];
    }
    result[index] = '\0';
    return result;
}

String& String::append(const String &target) {
    this->size = target.size;
    this->capacity = target.capacity;
    this->original = new char[this->capacity];

    size_t index;
    for (index = 0; index < this->size; index++) {
        this->original[index] = target.original[index];
    }
    delete[] this->original;
    this->original[index] = '\0';
    return *this;
}