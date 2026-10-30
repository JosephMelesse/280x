#include <iostream>
#include <exception>

// MyException derived class that inherits from exceptions base class
class MyException : public std::exception{
public:
    MyException(std::string message):m_message(std::move(message)){}
    // override the what() method to store a custom error message 
    const char* what() const noexcept override{
        return m_message.data();
    }
private:
    std::string m_message;
};
