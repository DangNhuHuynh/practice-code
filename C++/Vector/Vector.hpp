#ifndef PRACTICE_CODE_VECTOR_HPP
#define PRACTICE_CODE_VECTOR_HPP


#include <glob.h>
#include <clocale>
#include <cstring>
#include <iostream>

namespace Ahihi {
    template <typename T>
    class Vector {
    private:
        T *original;
        size_t capacity;
        size_t realSize;

    public:

        /**
         * Vector default constructor
         *
         */
        Vector() {
            this->original = new T[4];
            this->capacity = 4;
            this->realSize = 0;
        }

        /**
         * Vector constructor with size
         *
         * @param size
         */
        Vector(size_t size) {
            this->original = new T[size];
            this->capacity = size;
            this->realSize = 0;
        }

        /**
         * Vector copy constructor
         *
         * @param vector
         */
        Vector(const Vector &vector) {
            this->original = new T[vector.capacity];
            this->capacity = vector.capacity;
            this->realSize = vector.realSize;

            int index;
            for (index = 0; index < vector.capacity; index++) {
                this->original[index] = vector.original[index];
            }
        }

        /**
         *
         */
        void reAllocate() {
            if (this->realSize == this->capacity - 1) {
                this->capacity = this->capacity * 2;
                T *holder = new T[this->capacity];

                int index;
                for (index = 0; index < this->realSize; index++) {
                    holder[index] = this->original[index];
                }

                delete[] this->original;
                this->original = holder;
            }
        }

        /**
         * Vector destructor
         *
         */
        ~Vector() {
            delete[] this->original;
        }

        /**
         * Value pushed in Vector
         *
         * @param value
         */
        void pushBack(T value) {
            this->reAllocate();
            this->original[this->realSize] = value;
            this->realSize++;
        }

        /**
         * Pop element in Vector
         *
         * @return value
         */
        T popBack() {
            if (this->realSize == 0) {
                std::cout << "Vector is empty!" << std::endl;
                return 0;
            }
            T result = this->original[this->realSize - 1];
            this->realSize--;
            return result;
        }

        /**
         * Display Vector with operator
         *
         * @param os
         * @param target
         * @return
         */
        friend std::ostream &operator <<(std::ostream &os, const Vector &target) {
            int index;
            for (index = 0; index < target.realSize; index++) {
                os << target.original[index] << " ";
            }
            return os;
        }

        /**
         * Constructor copy Vector
         *
         * @param target
         * @return
         */
        Vector operator= (const Vector &target) {
            this->original = new T[target.capacity];
            this->capacity = target.capacity;
            this->realSize = target.realSize;

            int index;
            for (index = 0; index < this->capacity; index++) {
                this->original[index] = target.original[index];
            }
            return *this;
        }

        /**
         * Get element at index
         *
         * @param index
         * @return T
         */
        T get(int index) const {
            return this->original[index];
        }

        /**
         * Get size of Vector
         *
         * @return realSize
         */
        size_t getSize() const {
            return this->realSize;
        }

        /**
         * Get capacity of Vector
         *
         * @return Capacity
         */
        size_t getCapacity() const {
            return this->capacity;
        }

        /**
         * Insert element at index in Vector
         *
         * @param value
         * @param position
         */
        bool insertAtIndex(T value, int position) {
            if(position < 0 || position > this->capacity) {
                std::cout << "Surpass size of Vector" << std::endl;
                return false;
            }

            int index;
            for(index = this->realSize; index > position; index--) {
                this->original[index] = this->original[index - 1];
            }
            this->original[position] = value;
            this->realSize++;
            this->reAllocate();
            return true;
        }

        /**
         * Element at index position of Vector removed.
         *
         * @param position
         */
        void removeAtIndex(int position) {
            int index;
            for (index = position; index < this->realSize - 1; index++) {
                this->original[index] = this->original[index + 1];
            }
            this->realSize--;
        }

        /**
         * Total Vectors
         *
         * @param target
         * @return Vector
         */
        Vector operator+(Vector target) const {
            Vector result;

            int index;
            for (index = 0; index < this->realSize; index++) {
                result.pushBack(this->original[index]);
            }

            for (index = 0; index < target.realSize; index++) {
                result.pushBack(target.original[index]);
            }
            return result;
        }

    };
}

#endif //PRACTICE_CODE_VECTOR_HPP
