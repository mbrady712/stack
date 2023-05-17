/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a stack ADT that holds a collection of pointers to Structures.
**********************/

#include "stack.h"

Stack::Stack(int arg){
    top = BOTTOM;

    if(arg >= 2){
        size = arg;
    }else{
        size = DEFAULT_SIZE;
    }

    stack = new Data*[size];
}

bool Stack::push(int num, string& data){
    bool success = false;

    if(num >= 0 && data != "" && top < size - 1){
        Data *myData = new Data;

        myData->id = num;
        myData->information = data;

        top++;

        stack[top] = myData;

        success = true;
    }

    return success;
}

bool Stack::pop(Data* popper){
    bool success;

    if(top > BOTTOM){

        popper->id = stack[top]->id;
        popper->information = stack[top]->information;

        delete stack[top];

        top--;

        success = true;
    }else{

        popper->id = -1;
        popper->information = "";

        success = false;
    }
    return success;
}

bool Stack::peek(Data* peeker){
    bool success;

    if(top > BOTTOM){

        peeker->id = stack[top]->id;
        peeker->information = stack[top]->information;

        success = true;
    }else{

        peeker->id = -1;
        peeker->information = "";

        success = false;
    }
    return success;
}

bool Stack::isEmpty(){
    return top == BOTTOM;
}

int Stack::getSize(){
    return top + 1;
}

Stack::~Stack(){
    for(int i = 0; i < top; i++){
        delete stack[i];
    }
    delete[] stack;
}


