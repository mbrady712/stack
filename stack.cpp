/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a stack ADT that holds a collection of pointers to Structures.
**********************/

/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly
#include "stack.h"

//accepts an int for the stack size
Stack::Stack(int arg){
    top = BOTTOM;

    if(arg >= 2){
        size = arg;
    }else{
        size = 10;
    }

    std::cout << size;

    stack = new Data*[size];
}



