/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a stack ADT that holds a collection of pointers to Structures.
**********************/

#include "main.h"

int main(int argc, char **argv) {
    
    if(argc == 2 && isPosInt(argv[1])){

        //convert command line input from char **argv to int
        int size = atoi(argv[1]);

        Stack stack(size);

        srand(time(NULL));

        //ID and information values to be used for testing
        int testID;
        std::string testInfo;

        //************************************************************************************************
        //EMPTY TESTS
        //Test pop(), peek(), and isEmpty() operations when stack is empty. push() will be tested on empty
        //stack when tests on filling are conducted
        //************************************************************************************************

        std::cout << "Test pop(), peek(), and isEmpty() operations when stack is empty." << std::endl;
        std::cout << "=================================================================" << std::endl;

        //Testing isEmpty() on empty stack
        std::cout << "Result of isEmpty(): ";
        if (stack.isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            std::cout << "Stack is NOT empty" << std::endl;
        }

        //Testing peek() on empty stack
        std::cout << "Result of peek(): ";

        //Create 'empty' struct to pass to stack
        Data peeker;

        if(stack.peek(&peeker)){
            std::cout << "Struct with following attributes successfully peeked:" << std::endl;
            std::cout << "ID: " << peeker.id << std::endl;
            std::cout << "Information: " << peeker.information << std::endl;
        }else{
            std::cout << "Peek underflow error: stack is empty" << std::endl;
        }

        //Testing pop() on empty stack
        std::cout << "Result of pop(): ";

        //Create 'empty' struct to pass to stack
        Data popper;

        if(stack.pop(&popper)){
            std::cout << "Struct with following attributes successfully popped from stack:" << std::endl;
            std::cout << "ID: " << popper.id << std::endl;
            std::cout << "Information: " << popper.information << std::endl;
        }else{
            std::cout << "Pop underflow error: stack is empty" << std::endl;
        }
        std::cout << std::endl;

        //************************************************************************************************
        //FILLING AND FULL TESTS
        //************************************************************************************************

        std::cout << "Testing all operations when stack is filling and full." << std::endl;
        std::cout << "======================================================" << std::endl;

        //Test filling stack with invalid ID and information values
        //Test with negative ID value 
        std::cout << "Test filling stack with negative and therefore invalid ID:" << std::endl;

        testID = rand() * -1;
        testInfo = "Testing a struct with a negative ID";
        try
        {
            stack.push(testID, testInfo);
        }
        catch(std::string& e)
        {
            std::cout << e << std::endl;
        }
        std::cout << std::endl;
        
        //Test with empty information value
        std::cout << "Test filling stack with empty and therefore invalid information:" << std::endl;

        testID = rand();
        testInfo = "";
        try
        {
            stack.push(testID, testInfo);
        }
        catch(std::string& e)
        {
            std::cout << e << std::endl;
        }
        std::cout << std::endl;

        //Testing filling the stack and overflow
        std::cout << "Filling the stack until overflow error occurs:" << std::endl;

        for (int i = 0; i < size + 1; i++) {
            //Create valid random ID and info
            testID = rand();
            rand_string(&testInfo);
            testInfo += "a";

            if(stack.push(testID, testInfo)){
                std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
                std::cout << "ID: " << testID << std::endl;
                std::cout << "Information: " << testInfo << std::endl;
            }else{
                std::cout << "Overflow error: stack is full." << std::endl;
            }
        }
        std::cout << std::endl;

        //Testing isEmpty() on full stack
        std::cout << "Result of isEmpty(): ";

        if (stack.isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            std::cout << "Stack is NOT empty" << std::endl;
        }
        std::cout << std::endl;

        //Testing peek() on full stack
        std::cout << "Result of peek(): " << std::endl;

        if(stack.peek(&peeker)){
            std::cout << "Struct with following attributes successfully peeked:" << std::endl;
            std::cout << "ID: " << peeker.id << std::endl;
            std::cout << "Information: " << peeker.information << std::endl;
        }else{
            std::cout << "Peek underflow error: stack is empty" << std::endl;
        }
        std::cout << std::endl;

        //Testing pop() on full stack. Pop each struct until stack is empty and underflow error occurs.
        std::cout << "Result of pop():" << std::endl;

        if(stack.pop(&popper)){
            std::cout << "Struct with following attributes successfully popped from stack:" << std::endl;
            std::cout << "ID: " << popper.id << std::endl;
            std::cout << "Information: " << popper.information << std::endl;
        }else{
            std::cout << "Pop underflow error: stack is empty" << std::endl;
        }
        std::cout << std::endl;
        
        //************************************************************************************************
        //EMPTYING AND EMPTY TESTS
        //************************************************************************************************

        std::cout << "Testing peek() and pop() until stack is empty" << std::endl;
        std::cout << "=============================================" << std::endl;

        for (int i = 0; i < size; i++) {
            std::cout << "Result of peek(): " << std::endl;
            if(stack.peek(&peeker)){
                std::cout << "Struct with following attributes successfully peeked:" << std::endl;
                std::cout << "ID: " << peeker.id << std::endl;
                std::cout << "Information: " << peeker.information << std::endl;
            }else{
                std::cout << "Peek underflow error: stack is empty" << std::endl;
            }

            std::cout << "Result of pop():" << std::endl;
            if(stack.pop(&popper)){
                std::cout << "Struct with following attributes successfully popped from stack:" << std::endl;
                std::cout << "ID: " << popper.id << std::endl;
                std::cout << "Information: " << popper.information << std::endl;
            }else{
                std::cout << "Pop underflow error: stack is empty" << std::endl;
            }
        }
        std::cout << std::endl;

        //Testing isEmpty() on an empty stack
        std::cout << "Result of isEmpty(): ";
        if (stack.isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            std::cout << "Stack is NOT empty" << std::endl;
        }
        std::cout << std::endl;

        //Testing peek() on empty stack
        std::cout << "Result of peek(): ";

        if(stack.peek(&peeker)){
            std::cout << "Struct with following attributes successfully peeked:" << std::endl;
            std::cout << "ID: " << peeker.id << std::endl;
            std::cout << "Information: " << peeker.information << std::endl;
        }else{
            std::cout << "Peek underflow error: stack is empty" << std::endl;
        }
        std::cout << std::endl;

        //Testing pop() on empty stack
        std::cout << "Result of pop(): ";

        if(stack.pop(&popper)){
            std::cout << "Struct with following attributes successfully popped from stack:" << std::endl;
            std::cout << "ID: " << popper.id << std::endl;
            std::cout << "Information: " << popper.information << std::endl;
        }else{
            std::cout << "Pop underflow error: stack is empty" << std::endl;
        }
        std::cout << std::endl;

        //************************************************************************************************
        //MID-STACK TESTS
        //************************************************************************************************
        std::cout << "Filling stack halfway and testing the middle of the stack..." << std::endl;
        std::cout << "============================================================" << std::endl;

        //Use push() to fill stack halfway
        for (int i = 0; i < int(size/2); i++) {
            //Create valid random ID and info
            testID = rand();
            rand_string(&testInfo);
            testInfo += "a";

            if(stack.push(testID, testInfo)){
                std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
                std::cout << "ID: " << testID << std::endl;
                std::cout << "Information: " << testInfo << std::endl;
            }else{
                std::cout << "Overflow error: stack is full." << std::endl;
            }
        }
        std::cout << std::endl;

        //Test isEmpty(), peek(), and pop() on a range of structs in the middle of the stack
        for(int i = 0; i < size*NARROW; i++){
            //isEmpty
            std::cout << "Result of isEmpty(): ";
            if (stack.isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
            } else {
                std::cout << "Stack is NOT empty" << std::endl;
            }
            //peek()
            std::cout << "Result of peek(): ";
            if(stack.peek(&peeker)){
                std::cout << "Struct with following attributes successfully peeked:" << std::endl;
                std::cout << "ID: " << peeker.id << std::endl;
                std::cout << "Information: " << peeker.information << std::endl;
            }else{
                std::cout << "Peek underflow error: stack is empty" << std::endl;
            }
            //pop()
            std::cout << "Result of pop(): ";
            if(stack.pop(&popper)){
                std::cout << "Struct with following attributes successfully popped from stack:" << std::endl;
                std::cout << "ID: " << popper.id << std::endl;
                std::cout << "Information: " << popper.information << std::endl;
            }else{
                std::cout << "Pop underflow error: stack is empty" << std::endl;
            }
        }

        //************************************************************************************************
        //RANDOM TESTS
        //************************************************************************************************

        std::cout << "Random testing..." << std::endl;
        std::cout << "=================" << std::endl;

        //Empty the stack
        while(!stack.isEmpty()){
            stack.pop(&popper);
        }

        /* ***************************************************************
        * First get your arguments from the command line. Your program must
        * accept one and only one argument not including the program name
        * itself. That argument must be an integer. If anything else is entered
        * in any way, terminate the program with a suitable error message
        * telling the user how to use your program correctly.
        * 
        * Remember, you may not use more than one return, even in main()
        * and you may not use exit() or anything like that.
        * ***************************************************************///complete
        
        /* ***************************************************************
        * Use the number passed in from the command line and declare a stack
        * that uses that number as the size of the stack. NOTE: Make sure
        * your stack checks the number passed in to it. You cannot rely
        * on main checking the number first, each part of every program and
        * ADT is always responsible for it's own error checking. Main must
        * check the user gave it an int. The stack must check main()
        * gave it a good number. This is proper error checking, no part of
        * any program can assume it's caller is behaving correctly. To do this,
        * try passing -1 or 0 or some other "bad" number to the stack from
        * main and make sure your stack rejects it, or defaults to some
        * pre-defined default value. This will be tested during grading.
        * ***************************************************************/

        
        /* ***************************************************************
        * Throughly test your stack. You must perform an exhaustive series
        * of tests on your stack. Show all possible ways your stack can be used
        * and abused and prove that your stack can gracefully handle ALL cases.
        * You must use automated testing (no user input). First cover all
        * explicit cases which you can think of, then execute random operations.
        * When generating test data, use random ints for ids and random short
        * strings for string. There is a string generator made for you in the
        * functions module. You are free to use it or make your own.
        * ***************************************************************/

        /* ***************************************************************
        * Below is some sample code for the random string function. It's
        * only here to demonstrate the function. DELETE it once you study
        * it and understand it and can use it yourself in your code.
        * ***************************************************************/
        
        /* ***************************************************************
        * Your code will be tested by applying your stack to a custom main
        * designed to break your code. If it can be broken, you risk a
        * substantially reduced grade, up to and including a zero.
        * ***************************************************************/
        
        // WHEN YOU SUBMIT, DELETE ALL THESE INSTRUCTIONALCOMMENTS


    }else{
        std::cout << "Invalid command line argument. You must enter one and only one positive integer." << std::endl;
    }
    
    return 0;

    /*        std::string test = "hi";

        //push()

        std::cout << "Result of push no. 1:" << s1.push(5, test) << std::endl;

        //pop()

        //Pass an ‘empty’ struct Data to the stack (by reference)

        Data popper;

        //Verify that pop() works
        std::cout << "Result of pop:" << s1.pop(&popper) << std::endl;
        std::cout << "ID returned from pop: " << popper.id << std::endl;
        std::cout << "Info returned from pop: " << popper.information << std::endl;

        //peek()

        //Push new struct to stack

        test = "hello";

        s1.push(4, test);

        //Pass an ‘empty’ struct Data to the stack (by reference)

        Data peeker;

        //Verify that peek() works
        std::cout << "Result of peek:" << s1.peek(&peeker) << std::endl;
        std::cout << "ID returned from peek: " << peeker.id << std::endl;
        std::cout << "Info returned from peek: " << peeker.information << std::endl;

        //isEmpty()

        std::cout << "Result of isEmpty:" << s1.isEmpty() << std::endl;

        //getSize()

        std::cout << "Number of structs in stack:" << s1.getSize() << std::endl;*/
}
