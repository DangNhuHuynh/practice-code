//
// Created by danghuynh on 19/07/2017.
//

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
         *
         */
        void reAllocate();

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
         * Extends the string by appending additional characters
         * at the end of its current value:
         *
         * @param target `String'
         * @return String
         */
        String &append(const String &target);

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

        /**
         * Return chain character with String type.
         *
         * @return char*
         */
        char *toString();

    public: /* For friend function */
        /**
         * Console String
         *
         * @param os
         * @param str
         * @return String
         */
        friend std::ostream& operator<<(std::ostream &os, const String &str) {
            size_t index;
            for (index = 0; index < str.lengthStr; index++) {
                os << str.myString[index];
            }
            return os;
        }
    };

}

#endif //PRACTICE_CODE_STRING_H