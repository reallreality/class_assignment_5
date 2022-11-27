/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* Stack ADT definitions
**********************/

// each cpp includes ONLY it's header directly
#include "stack.h"


//Constructor
Stack::Stack(int stackSize) {

    top = NEGATIVE_ONE;

    size = stackSize;



    if (size > ZERO) {

        stack = new Data*[size];
    }

    else if (size <= ZERO) {

        size = DEFAULT_SIZE;

        stack = new Data*[size];

    }
    
}

Stack::~Stack() {

    for (int i = 0; i < top; i++) {

        delete stack[i];

    }

    delete[] stack;

}




//Push function definition
bool Stack::push(int identity, string *info) {

    bool executed = false;

    if (top < (size - 1)) {

        if (identity > NEGATIVE_ONE and *info != "") {
        
            Data *newData = new Data;

            newData->id = identity;

            newData->information = *info;

            top++;

            stack[top] = newData;

            executed = true;

        }
    
    }

    return executed;
}



//Pop function definition
bool Stack::pop(Data *mainDataStruct) {

    bool popped = false;

    if (top != NEGATIVE_ONE) {

        mainDataStruct->id = stack[top]->id;

        mainDataStruct->information = stack[top]->information;

        delete stack[top];

        top--;

        popped = true;

    }

    else {

        mainDataStruct->id = NEGATIVE_ONE;

        mainDataStruct->information = "";

        popped = false;

    }

    return popped;


}


//Peek function definition
bool Stack::peek(Data *mainDataStruct) {

    bool canPeek = false;

    if (top != NEGATIVE_ONE) {

        mainDataStruct->id = stack[top]->id;

        mainDataStruct->information = stack[top]->information;

        canPeek = true;

    }

    else {

        mainDataStruct->id = NEGATIVE_ONE;

        mainDataStruct->information = "";

        canPeek = false;

    }

    return canPeek;


}


bool Stack::isEmpty() {

    bool empty = false;

    if (top == NEGATIVE_ONE) {

        empty = true;

    }

    return empty;

}





