/*
CIS 280X
Lab 8 - Problem 1
Melesse, Joseph
*/

#include <iostream>
#include <string>
#include <exception>
#include "MyException.h"

int main(){
    // try catch block that throws a custom error
    try {
        throw MyException("Custom error");
    }
    catch (const MyException& e) { 
        std::cout << "MyException: " << e.what() << '\n'; 
    }
    catch (const std::exception& e){ 
        std::cout << "std::exception: " << e.what() << '\n'; 
    }
    catch (...){ 
        std::cout << "Unknown exception\n"; 
    }
}
