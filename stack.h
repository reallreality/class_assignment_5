/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* Stack ADT function prototypes
**********************/

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */
#include <cctype>
#include "data.h"

//Created to use instead of literal
#define ZERO 0
#define NEGATIVE_ONE -1
#define DEFAULT_SIZE 10



class Stack {

    public:

        /* 
        * write all your public method prototypes here
        * this includes you constructor and destructor
        */

        Stack(int);

        ~Stack();

        bool push(int, string*);

        bool pop(Data*);

        bool peek(Data*);

        bool isEmpty();


        
    private:

        /* 
        * write all your private method prototypes here
        */

        // these are the only attributes you need.
        // do not modify them or add any other attributes
        int top;
        int size;
        Data **stack;
        // notice stack is a pointer to a pointer. That means if you do
        // a single array allocation, you will get an array of pointers
};

#endif //STACK_H
