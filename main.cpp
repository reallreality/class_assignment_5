/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* A program uses dynamic memory allocation to create a stack which holds pointers
* to pointers of data type "Data" which is a struct
**********************/

#include "main.h"

int main(int argc, char **argv) {

    // here for the rand_string() function
    // if you don't use it, get rid of this
    srand(time(NULL));

    //Creating an int variable to stop program
    int stop = -1;
    
    //Creating size comparison variable to not use literal
    int sizeCheck = 2;

    //Creating switch statment choice size variable to not use literal
    int choiceSize = 4;

    //Testing that there is an argument passed to program in terminal
    if (argc == sizeCheck) {

        //Turning terminal input into a string
        std::string size = argv[1];

        //Testing that the argument passed to program in terminal is a int value
        if (isdigit(size[0]) or isdigit(size[1])) {

            //Converting pointer to int and displaying to the user the size the stack will be
            int inputSize = stoi(size);

            //Creating a stack instance and passing the terminal int to it as argument
            Stack myStack(inputSize);

            //Creating a "Data" struct in main in order for pop to work
            Data data1;

            //String variable to hold various random strings created in program
            std::string text;


            //Calling various methods on stack object
            std::cout << std::endl << "Performing various standalone tests on stack ADT." << std::endl << std::endl;

            //Generating a random string and assining it to the address of text variable
            rand_string(&text);

            //Attempting a push on stack array
            std::cout << "Pushing to stack object. (1 - means successful, 0 - means unsuccessful)" << std::endl;
            std::cout << myStack.push(15, &text) << std::endl;

            
            //Attempting to pop from stack array
            std::cout << std::endl << "Popping from stack array. (1 - means successful, 0 - means unsuccessful)" << std::endl;
            std::cout << std::endl << myStack.pop(&data1) << std::endl;


            //Using a for loop to attempt to underflow
            std::cout << std::endl << std::endl << "Calling the pop function on stack object using a for loop attempting underflow." << std::endl;
            
            for (int x = 0; x < inputSize; x++) {

                std::cout << myStack.pop(&data1) << std::endl;

                std::cout << "A pop iteration has completed. (1 - means successful, 0 - means unsuccessful)" << std::endl;

                std::cout << std::endl;
            }



            //Using a for loop to attempt overflow
            std::cout << std::endl << std::endl << "Calling push function on stack object using a for loop attempting overflow." << std::endl;

            for (int x = 0; x < (inputSize * inputSize); x++) {

                rand_string(&text);

                std::cout << myStack.push((x), &text) << std::endl;

                std::cout << "A push iteration complete. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;
            }



            //Calling the peek function and then displaying the information placed in Data object created in main
            std::cout << std::endl << "Calling peek function and then displaying the data placed in 'Data' object in main." << std::endl;
            myStack.peek(&data1);

            std::cout << data1.id << " | " << data1.information << std::endl;

            std::cout << "Peek member function call complete" << std::endl << std::endl;

            
            //Calling isEmpty member function
            std::cout << std::endl << "Here is an isEmpty call: " << myStack.isEmpty() << ". (1 - means empty, 0 - means not empty)" << std::endl << std::endl;



            //Ensuring the stack is empty
            std::cout << std::endl << "We will use a while loop and pop function to ensure that the stack is empty: " << std::endl << std::endl;
            while (!(myStack.isEmpty())) {

                std::cout << myStack.pop(&data1) << std::endl;

                std::cout << "Just completed a pop iteration on stack. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

            }

            //Informing the user once the stack is completely empty
            std::cout << std::endl << "Stack is empty" << std::endl << std::endl;




            //Informing the user of what happene and what is about to happen
            std::cout << "A random string and random positive integer will be generated. Then, a for loop will push " <<
            "'Data' struct pointers to stack." << std::endl;

            std::cout << "A 0 signifies that a push was not complete due to the randomly generated string being empty." << 
            " A 1 signigies that a push() iteration was succesfully performed." << std::endl << std::endl;


            //Filling the stack with random numbers and strings
            for (int x = 0; x < inputSize; x++) {

                //Creating a randomly generated string and assigning it to string variable
                rand_string(&text);

                //Creating a randomly generated integer and assigning it to a variable
                int dataInt = std::rand();

                std::cout << myStack.push(dataInt, &text) << std::endl;

                std::cout << "A push iteration complete. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

            }


            
            //The following switch statement block tests random operations
            std::cout << std::endl << std::endl << "Now entering a switch statement block for random testing to be perform on stack." << std::endl << std::endl;

            
            //For loop for switch statment block
            for (int x = 0; x < (inputSize * inputSize); x++) {

                //Creating a random integer used for switch case selection
                int choice = std::rand() % choiceSize;

                //Switch statement block
                switch (choice) {

                    case 1:

                        //Informing user of which case was entered
                        std::cout << std::endl << std::endl << "You have entered switch case 1." << std::endl << std::endl;

                        //Informing user what this case will do first
                        std::cout << "This case starts by clearing the stack using the pop() function: " << std::endl << std::endl;


                        //While loop to empty stack completely
                        while (!(myStack.isEmpty())) {

                            //Calling pop member function
                            std::cout << myStack.pop(&data1) << std::endl;

                            //Informing user of when operation is complete
                            std::cout << "Just completed a pop iteration on stack. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

                        }

                        //Checking if stack is empty
                        std::cout << std::endl << std::endl << "Now the stack is checked to see if it is empty. (1 - means YES, 0 - means NO)" << std::endl;
                        std::cout << myStack.isEmpty() << std::endl << std::endl;


                        //Informing the user what is happening next in case
                        std::cout << std::endl << "Now using a for loop to push pointers to stack and calling isEmpty function after each push." << std::endl << std::endl;

                        for (int y = 0; y < inputSize; y++) {

                            //Creating random string and assigning it to string variable
                            rand_string(&text);

                            //Creating random int and assigning it to int variable
                            int dataInt = std::rand();

                            //Calling push member function
                            std::cout << myStack.push(dataInt, &text) << std::endl;

                            //Informing user that operation is complete
                            std::cout << "A push iteration complete. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

                            //Calling isEmpty member function
                            std::cout << "Stack is: " << myStack.isEmpty() << " empty. (0 - means not empty, 1 - means empty)" << std::endl << std::endl;

                        }

                        break;

                    case 2:

                        //Informing user of which case was entered
                        std::cout << std::endl << std::endl << "You have entered switch case 2." << std::endl << std::endl;

                        //Informing user what this case will do first
                        std::cout << "This cases starts with a loop that attempts to pop more pointers than are in the stack." << std::endl << std::endl;

                        for (int i = 0; i < (inputSize * inputSize); i++) {
                            
                            //Calling pop member function
                            std::cout << myStack.pop(&data1) << std::endl;

                            //Informing user that the operation is complete
                            std::cout << "Just completed a pop iteration. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

                        }

                        //Informing user what is happening next in case
                        std::cout << std::endl << "Now using a for loop to attempt to push a higher number of pointers to stack than stack size." << std::endl << std::endl;

                        for (int i = 0; i < (inputSize * inputSize); i++) {

                            //Creating a randomly generated string and assigning it to string variable
                            rand_string(&text);

                            //Creating a randomly generated integer and assigning it to a variable
                            int dataInt = std::rand();

                            //Calling push member function
                            std::cout << myStack.push(dataInt, &text) << std::endl;

                            //Informing user that the operation is complete
                            std::cout << "A push iteration complete. (1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

                        }

                        break;

                    case 3:

                        //Informing user of which case was entered
                        std::cout << std::endl << std::endl << "You have entered switch case 3." << std::endl << std::endl;

                        //Informing user what this case will do first
                        std::cout << std::endl << "This case uses a loop to call isEmpty, pop, isEmpty, and peek resepctively." << std::endl << std::endl;

                        for (int i = 0; i < (inputSize * inputSize); i++) {

                            //Calling isEmpty member function
                            std::cout << std::endl << "Calling isEmpty function: " << myStack.isEmpty() << " (0 - means not empty, 1 - means empty)" << std::endl << std::endl;

                            //Calling pop member function
                            std::cout << "Calling pop function: " << myStack.pop(&data1) << "(1 - means successful, 0 - means unsuccessful)" << std::endl << std::endl;

                            //Calling isEmpty member function
                            std::cout << "Calling isEmpty function: " << myStack.isEmpty() << " (0 - means not empty, 1 - means empty)" << std::endl << std::endl;

                            //Calling peek member function
                            std::cout << "Calling peek function: " << myStack.peek(&data1) << ". (1 - means successful, 0 - means unsuccessful)" << std::endl;

                        }


                        break;

                }


            }

            //Setting program terminator once testing is complete
            stop = 0;

        }

        //Prompting user with error message a non-int value is received as input in terminal
        else {

            std::cout << "Program terminating. Next time please enter a single positive integer value in the terminal. " <<
            "The entered positive integer will be the size of your stack." << std::endl;

            stop = 0;

        }


    }

    //Prompting user with error message if an incorrect number of values is passed to program at terminal
    else {

        std::cout << "Program terminating. Next time please enter a single positive integer value in the terminal. " <<
        "The entered positive integer will be the size of your stack." << std::endl;

        stop = 0;

    }


    //Terminating program execution
    return stop;

}
