// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// This class is the custom required exception 
// It returns an explicit error message 
class ExplicitException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Error: Explicit Exception";
        }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    // Throws the standard runtime error exception as required
    throw std::runtime_error("Error: Runtime Exception");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}

void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    
    // Outer try group catches if an error occurs inside
    try {
        std::cout << "Running Custom Application Logic." << std::endl;

        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    // If a catch occurs in the previous try group, a standard exception is thrown containing both the exception.what() as well as a message as required
    catch (const std::exception& error) {
        std::cout << "Error: Standard Exception" << std::endl;
        std::cout << error.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    
    // Throws the explicitly required exception which is caught in main
    throw ExplicitException();

    std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    // if the demoninator is 0 (meaining if attempting to divide by zero) an error is thrown pertaining to invalid arguments
    if (den == 0) {
        throw std::invalid_argument("Error: Dividing By Zero");
    }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.
    
    // Outer try group catches if an error with the attempted code occurs
    try {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;

    }
    // Catches ONLY the details thrown by the attempted divide and prints them as required
    catch (const std::invalid_argument& error) {
        std::cout << error.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    
    // Outer try group catches if an error with the attempted code occurs
    try {
        do_division();
        do_custom_application_logic();
    }
    // Catches the explicit exception and prints details as required
    catch (const ExplicitException& error) {
        std::cout << error.what() << std::endl;
    }
    // Catches the standard exception and prints details as required
    catch (const std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    // Catches the all other exceptions if they occur and prints details as required
    catch (...) {
        std::cout << "Error: Uncaught Exception";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu