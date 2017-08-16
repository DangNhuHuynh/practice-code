#ifndef PRACTICE_CODE_STRING_H
#define PRACTICE_CODE_STRING_H

#include <iostream>
#include <string>
#include <glob.h>
#include <clocale>

namespace dtnh {
    class String {
    private:
        size_t size;
        size_t capacity;
        char* original;

    private:
        /**
         * Reallocate memories for String
         */
        void reAllocate();

        /**
         * Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
         */
        void clear();

    public:
        /**
         * String default constructor.
         *
         */
        String();

        /**
         * String constructor with argument char*
         *
         * @param arr
         */
        String(const char*);

        /**
         * String constructor with two argument is: char and int.
         * Size_t: is chain character consecutive
         */
        String(char, size_t);

        /**
         * String copy constructor
         *
         */
        String(const String &);

        /**
         * String destructor
         */
        ~String();

    public: /* For method */
        /**
         * Get size reality of string
         *
         * @return size_t
         */
        size_t getSize() const;

        /**
         * Returns the size of the storage space currently allocated for the string.
         *
         * @return size_t
         */
        size_t getCapacity() const;

        /**
         * Return chain character with String type.
         *
         * @return char*
         */
        char* toString();

        /**
         * Extends the string by appending additional characters
         * at the end of its current value:
         *
         * @param target `String'
         * @return String
         */
        String append(const String &target);

        /**
         * Compares the value of String object
         *
         * @param target `String'
         * @return true or false
         */
        bool compare(const String &target);

        /**
         * Inserts additional characters into the string right
         * before the character indicated by pos
         *
         * @param position
         * @param target `String'
         * @return String
         */
        String &insert(size_t position, String &target);


        /**
         * Replace portion of String
         *
         * @param position `size_t'
         * @param target `String'
         * @return String
         */
        String replace(size_t position, size_t length, const String &target);

    public: /* For operator */
        /**
         * Total two String
         *
         * @return String
         */
        String operator+(const String&);

        /**
         * String Assignment
         *
         * @return String
         */
        String operator=(const String&);

    public: /* For friend function */
        /**
         * Console String
         *
         * @param os
         * @param str `String'
         * @return String
         */
        friend std::ostream& operator<<(std::ostream &os, const String &str) {
            size_t index;
            for (index = 0; index < str.size; index++) {
                os << str.original[index];
            }
            return os;
        }
    };

}

#endif //PRACTICE_CODE_STRING_H
