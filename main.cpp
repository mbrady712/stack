/*********************
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a stack ADT that holds a collection of pointers to Structures.
**********************/

#include "main.h"

int main(int argc, char **argv) {
    
    if(argc == 2 && checkInput(argv[1])){
        
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
        std::cout << "=================================================================" << std::endl;

        //Test filling stack with invalid ID and information values
        //Test with negative ID value 
        std::cout << "Test filling stack with negative and therefore invalid ID:" << std::endl;

        testID = rand() * -1;
        testInfo = "Testing a struct with a negative ID";
        if(stack.push(testID, testInfo)){
            std::cout << "Struct successfully pushed" << std::endl;
        }else{
            std::cout << "Struct not pushed" << std::endl;
        }
        std::cout << std::endl;
        
        //Test with empty information value
        std::cout << "Test filling stack with empty and therefore invalid information:" << std::endl;

        testID = rand();
        testInfo = "";
        if(stack.push(testID, testInfo)){
            std::cout << "Struct successfully pushed" << std::endl;
        }else{
            std::cout << "Struct not pushed" << std::endl;
        }
        std::cout << std::endl;

        //Testing filling the stack and overflow
        std::cout << "Filling the stack until overflow error occurs:" << std::endl;

        bool overflow = false;

        while(!overflow){
            //Create random id and information
            testID = (rand() % MAX_INT + 1);
            rand_string(&testInfo);
            if(stack.push(testID, testInfo)){
                std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
                std::cout << "ID: " << testID << std::endl;
                std::cout << "Information: " << testInfo << std::endl;
            }else if (stack.getSize() >= size){
                std::cout << "Overflow error: struct not pushed" << std::endl;
                overflow = true;
            }else{
                std::cout << "Struct not pushed: invalid id or data" << std::endl;
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
        std::cout << "=================================================================" << std::endl;

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
        std::cout << "=================================================================" << std::endl;

        //Use push() to fill stack halfway
        while(stack.getSize() < int(size/2)){
            //Create random id and information
            testID = (rand() % MAX_INT + 1);
            rand_string(&testInfo);
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
        std::cout << std::endl;

        //************************************************************************************************
        //RANDOM TESTS
        //************************************************************************************************

        std::cout << "Random testing..." << std::endl;
        std::cout << "=================================================================" << std::endl;

        //Empty the stack
        while(!stack.isEmpty()){
            stack.pop(&popper);
        }

        //Fill the stack halfway with random data to begin random tests
        while(stack.getSize() < int(size/2)){
            //Create random id and information
            testID = (rand() % MAX_INT + 1);
            rand_string(&testInfo);
            if(stack.push(testID, testInfo)){
                std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
                std::cout << "ID: " << testID << std::endl;
                std::cout << "Information: " << testInfo << std::endl;
            }else{
                std::cout << "Overflow error: stack is full." << std::endl;
            }
        }
        std::cout << std::endl;

        //Test random operations
        int choice = rand() % CHOICES + 1;
        for (int i = 0; i < size*RANDOM_MULTIPLIER; i++) {
            switch (choice) {
                case 1:
                case 2:
                    //push()
                    std::cout << "Result of push():" << std::endl;

                    //Create random id and information
                    testID = (rand() % MAX_INT + 1);
                    rand_string(&testInfo);
                    if(stack.push(testID, testInfo)){
                        std::cout << "Struct with following attributes successfully pushed to stack:" << std::endl;
                        std::cout << "ID: " << testID << std::endl;
                        std::cout << "Information: " << testInfo << std::endl;
                    }else{
                        std::cout << "Overflow error: stack is full." << std::endl;
                    }
                    break;
                case 3:
                case 4:
                    //pop()
                    std::cout << "Result of pop():" << std::endl;
                    if(stack.pop(&popper)){
                        std::cout << "Struct with following attributes successfully popped from stack:" << std::endl;
                        std::cout << "ID: " << popper.id << std::endl;
                        std::cout << "Information: " << popper.information << std::endl;
                    }else{
                        std::cout << "Pop underflow error: stack is empty" << std::endl;
                    }
                    break;
                case 5:
                    //peek()
                    std::cout << "Result of peek(): ";
                    if(stack.peek(&peeker)){
                        std::cout << "Struct with following attributes successfully peeked:" << std::endl;
                        std::cout << "ID: " << peeker.id << std::endl;
                        std::cout << "Information: " << peeker.information << std::endl;
                    }else{
                        std::cout << "Peek underflow error: stack is empty" << std::endl;
                    }
                    break;
                case 6:
                    //isEmpty()
                    std::cout << "Result of isEmpty(): ";
                    if (stack.isEmpty()) {
                        std::cout << "Stack is empty" << std::endl;
                    } else {
                        std::cout << "Stack is NOT empty" << std::endl;
                    }
            }
            choice = rand() % CHOICES + 1;
        }
        std::cout << std::endl;

        std::cout << "Testing complete." << std::endl;
        
    }else{
        std::cout << "Invalid command line argument. You must enter one and only one positive integer that is not 0 or 1." << std::endl;
    }
    
    return 0;

}