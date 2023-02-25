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

        delete stack[top];//Verify that this was deleted

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



