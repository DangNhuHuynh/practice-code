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

void String::reAllocate(size_t newCapacity) {
    this->capacity = newCapacity * 2;
    char * holder = new char[this->capacity];

    size_t index;
    for (index = 0; index < this->size; index++) {
        holder[index] = this->original[index];
    }

    delete[] this->original;
    this->original = holder;
    this->original[index] = '\0';
}

void String::clear() {
    delete[] this->original;
    this->original = new char;
    this->original[0] = '\0';
    this->size = 0;
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

string String::toString() {
    return this->original;
}

// FIXME: danghuynh please fix this method
String String::append(const String &target) {
    this->size = this->size + target.size;
    this->capacity = this->size * 2;
    char *temp = this->original;
    this->original = new char[this->capacity];
    size_t index;
    for (index = 0; index < strlen(temp); index++) {
         this->original[index] = temp[index];
    }

    for (index = 0; index < target.size; index++) {
        size_t indexInLoop = index + strlen(temp);
        this->original[indexInLoop] = target.original[index];
    }

    delete[] temp;
    this->original[this->size] = '\0';
    return *this;
}

bool String::compare(const String &target) {
    size_t indexFirst;
    size_t indexSecond;
    for (indexFirst = 0; indexFirst < this->size; indexFirst++) {
        for (indexSecond = 0; indexSecond < target.size; indexSecond++) {
            if (this->original[indexFirst] == target.original[indexSecond]) {
                return true;
            }
        }
    }
    return false;
}

// FIXME: danghuynh please fix this method
String String::insert(size_t position, String &target) {
    size_t index;
    for (index = this->size; index >= position; index--) {
        this->original[index + target.size] = this->original[index];
    }

    for (index = 0; index < target.size; index++) {
        this->original[index + position] = target.original[index];
    }
    return *this;
}

String String::replace(size_t position, size_t length, const String &target) {
    if (position < 0 || position >= this->size) {
        throw (std::invalid_argument("Position out of bond!!!"));
    }

    if (length <= 0) {
        throw (std::invalid_argument("Cant replace"));
    }

    size_t index;
    if (length > target.size) {
        for (index = position + target.size; index < this->size; index++) {
            this->original[index] = this->original[index + 1];
        }
        this->size = this->size - (length - target.size);
    }

    if (length < target.size) {
        if (this->size + (target.size - length) > this->capacity - 2) {
            this->reAllocate(this->size + (target.size - length));
        }
        for (index = this->size; index >= position + length; index--) {
            this->original[index + 1] = this->original[index];
        }
        this->size = this->size + (target.size - length);
        this->reAllocate();
    }

    for (index = 0; index < target.size; index++) {
        this->original[position + index] = target.original[index];
    }

    this->original[this->size] = '\0';
    return *this;
}

String String::operator+(const String &target) {
    char *holder = strcat(this->original, target.original);
    String result = holder;
    return result;
}

String String::operator=(const String &target) {
    this->size = target.size;
    this->capacity = target.capacity;
    delete[] this->original;
    this->original = new char[this->capacity];

    size_t index;
    for (index =0; index < target.size; index++) {
        this->original[index] = target.original[index];
    }
    this->original[index] = '\0';
    return  *this;
}
