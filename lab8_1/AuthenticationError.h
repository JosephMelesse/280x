#include <exception>
#include <iostream>

// custom error called AuthenticationError that is a runtime error type
class AuthenticationError : public std::runtime_error {
public:
  using std::runtime_error::runtime_error;   
};