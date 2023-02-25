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

        //Test pop(), peek(), and isEmpty() operations when stack is empty. push() will be tested on empty
        //stack when tests on filling are conducted

        std::cout << "Test pop(), peek(), and isEmpty() operations when stack is empty." << std::endl;
        std::cout << "=================================================================" << std::endl;

        //Testing isEmpty() on empty stack
        std::cout << "Result of isEmpty(): ";
        if (stack.isEmpty()) {
            std::cout << "stack is empty" << std::endl;
        } else {
            std::cout << "stack is NOT empty" << std::endl;
        }

        //Testing peek() on empty stack
        std::cout << "Result of peek(): ";

        //Create 'empty' struct to pass to stack
        Data peeker;

        if(stack.peek(&peeker)){
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
            std::cout << "ID: " << popper.id << std::endl;
            std::cout << "Information: " << popper.information << std::endl;
        }else{
            std::cout << "Pop underflow error: stack is empty" << std::endl;
        }

        // here for the rand_string() function
        // if you don't use it, get rid of this
        //srand(time(NULL));

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
        
        // make 20 random strings, store them, display them
        /*std::string strtemp;
        for(int i=0; i<20; i++){
            rand_string(&strtemp);
            std::cout << strtemp << std::endl;
        }*/
        
        
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
