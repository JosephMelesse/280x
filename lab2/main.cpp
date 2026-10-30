/*
CIS 280x
Assignment 2
Melesse, Joseph
*/
#include <array>
#include <string>
#include <iostream>

// global constexpr variable that has the number_size to avoid magic numbers
constexpr size_t number_size{7};
// prototype function for the word_generator function
void word_generator(const std::array<int, number_size>& phone);

int main() {
  // array that accepts the phone number element by element
  std::array<int, number_size> phone_number{};
  // prompt for user to insert phone number
  std::cout<<"Enter a phone number (digits 2 through 9) in the form: xxx-xxxx:\n";
  // cin.get() and for loop with counter to 
  for (int i = 0; i < number_size; ) {
    char number;
    // end loop if user enters blank 
    if (!std::cin.get(number)) break;
    // convert the stringed numbers between 2 and 9 to integers by subtracting '0' and store each integer in the phone_number array 
    // using internal iteration for general safety
    if (number >= '2' && number <= '9' ) {
      phone_number[i] = number - '0';
      ++i;
    }
  }

  // call the word_generator function and pass the phone_number array
  word_generator(phone_number);
  std::cout << '\n';
}

// word_generator function
void word_generator(const std::array<int, number_size>& phone) {
  // a string that has the available letters at the appropriate index
  const std::string phone_letters[10]{"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
  // constexpr value that holds the amount of words per row
  constexpr int word_per_row = 9;
  int count = 0;

  // nested for loops that iterate through each possible letter combination that can be drawn from the inputted phone number
  for (std::size_t i0 = 0; phone_letters[phone[0]][i0] != '\0'; ++i0)
    for (std::size_t i1 = 0; phone_letters[phone[1]][i1] != '\0'; ++i1)
      for (std::size_t i2 = 0; phone_letters[phone[2]][i2] != '\0'; ++i2)
        for (std::size_t i3 = 0; phone_letters[phone[3]][i3] != '\0'; ++i3)
          for (std::size_t i4 = 0; phone_letters[phone[4]][i4] != '\0'; ++i4)
            for (std::size_t i5 = 0; phone_letters[phone[5]][i5] != '\0'; ++i5)
              for (std::size_t i6 = 0; phone_letters[phone[6]][i6] != '\0'; ++i6) {
                std::cout
                  << phone_letters[phone[0]][i0]
                  << phone_letters[phone[1]][i1]
                  << phone_letters[phone[2]][i2]
                  << phone_letters[phone[3]][i3]
                  << phone_letters[phone[4]][i4]
                  << phone_letters[phone[5]][i5]
                  << phone_letters[phone[6]][i6]
                  // a space after each 7 letter combination
                  << " ";
    // for every 9 word generated (whenever the counter is divisable by 9) there will be a new line printed
    // ++count is just a counter variable that does the incrementation first and then computes whether we've reached 9 words on the row
    if (++count % word_per_row == 0) std::cout << '\n';
  }
}


