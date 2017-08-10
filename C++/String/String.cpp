//
// Created by danghuynh on 19/07/2017.
//

#include <cstring>
#include <malloc.h>
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
    return this->original;
}

// FIXME: danghuynh please fix this method
//String& String::append(const String &target) {
//    this->size = target.size;
//    this->capacity = target.capacity;
//    this->original = new char[this->capacity];
//
//    size_t index;
//    for (index = 0; index < this->size; index++) {
//        this->original[index] = target.original[index];
//    }
//    delete[] this->original;
//    this->original[index] = '\0';
//    return *this;
//}

// FIXME: danghuynh please fix this method
//String& String::insert(size_t position, String &target) {
//    size_t index;
//        for (index = this->size; index > position; index--) {
//            this->original[index] = this->original[index - 1];
//    }
//
//    for (index = 0; index < target.size; index++) {
//        String Temp = Temp.append(target);
//        this->original[position] = Temp.original[index];
//        position++;
//        this->size++;
//        this->reAllocate();
//    }
//    return *this;
//}

String String::operator+(const String &target) {
    char *holder = strcat(this->original, target.original);
    String result = holder;
    return result;
}

String String::operator=(const String &target) {
    this->size = target.size;
    this->capacity = target.capacity;
    this->original = new char[this->capacity];

    size_t index;
    for (index =0; index < target.size; index++) {
        this->original[index] = target.original[index];
    }
    delete[] this->original;
    this->original[index] = '\0';
    return  *this;
}
