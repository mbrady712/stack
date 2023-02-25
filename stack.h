/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a stack ADT that holds a collection of pointers to Structures.
**********************/

/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H

#define BOTTOM -1
#define DEFAULT 10

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#include <iostream> 

class Stack {

public:
    Stack(int);
    bool push(int, string&);
    bool pop(Data*);
    int peek();
    bool isEmpty();
    //~Stack();
    
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
