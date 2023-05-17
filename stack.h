/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a stack ADT that holds a collection of pointers to Structures.
**********************/

#ifndef STACK_H
#define STACK_H

#define DEFAULT_SIZE 10
#define BOTTOM -1
#define DEFAULT 10

#include "data.h"

class Stack {

public:
    Stack(int);
    bool push(int, string&);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
    ~Stack();
    int getSize();

private:
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
