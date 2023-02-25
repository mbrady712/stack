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

    stack = new Data*[size];
}

bool Stack::push(int num, string& data){
    bool success = false;

    if(top < size - 1 && num > 0 && data != ""){
       
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



