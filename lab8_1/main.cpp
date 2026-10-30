/*
CIS 280X
Lab 8 - Problem 2
Melesse, Joseph
*/

#include <iostream>
#include <string>
#include <exception>
#include "AuthenticationError.h"

// define validateCredentials function that compares the input with the expected values 
// and throws AutenticationError accordingly
void validateCredentials(std::string_view user, std::string_view pass, std::string_view expectedUser, std::string_view expectedPassword) {
  if (user != expectedUser || pass != expectedPassword)
    throw AuthenticationError("Invalid username or password");
}

int main(){
  const std::string expectedUser = "joseph-melesse";
  const std::string expectedPassword = "password";

  // for loop to give user two attempts
  for (int attempt = 1; attempt <= 2; ++attempt) {
    std::string user, pass;
    std::cout << "Username: ";
    std::getline(std::cin, user);
    std::cout << "Password: ";
    std::getline(std::cin, pass);

    // try catch statement to validate user
    try {
      validateCredentials(user, pass, expectedUser, expectedPassword);
      std::cout << "Login successful\n";
      return 0;
    }
    catch (const AuthenticationError& e) {
      std::cout << e.what();
      if (attempt < 2) std::cout << " (try again)\n";
      else std::cout << '\n';
    }
    catch (const std::exception& e) {
      std::cout << "Unexpected error: " << e.what() << '\n';
    }
  }

  std::cout
      << "Please contact the system administrator to reset your password.\n";

}
