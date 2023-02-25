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
        //Dynamically create a struct Data to hold the data.
        Data *myData = new Data;

        //Put the id and string in the struct Data.
        myData->id = num;
        myData->information = data;

        //Increment the stack counter
        top++;

        //Push the pointer for the struct onto the stack.
        stack[top] = myData;

        success = true;
    }
    return success;
}



