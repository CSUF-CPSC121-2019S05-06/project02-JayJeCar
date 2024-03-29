//Using the solution provided for Tuffynotes.cpp Project Milestone 1

#include <iostream>
#include <string>
#include "notebook.hpp"

void createNote();

int main()
{
  char choice;
  std::string rem;
  bool display_menu = true;
  std::string array = {0};
  Note title;
  Note body;

  std::cout << "Welcome to TuffyNotes!\n";

  do {
    std::cout << "[C] Create a note" << std::endl;
    std::cout << "[E] Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    if (rem.length() > 0) {
      choice = ' ';
    }
    std::cout << std::endl;

    switch (choice) {
      case 'C':
      case 'c':
        createNote(); //Calling the function
        for (int i = 0; i < 100; i++) {
          if (array[i] > 0) {
          std::string getTitle(array);
          std::string getBody(array);
        }
        break;
      case 'E':
      case 'e':
        display_menu = false;
        break;
      default:
        std::cout << "Invalid choice. Please try again.\n\n";
        break;
    }
  } while (true == display_menu);

  std::cout << "Thank you for using TuffyNotes!" << std::endl;

  std::cout << "\n(temporary debug)\nArray contents:\n";

  for (int i = 0; i < 100; i++) {
    if (!array[i].getTitle().empty() || !array[i].getBody().empty()) {
      std::cout << "Array location [" << i << "]: <" << array[i].getTitle()
        << "> " << array[i].getBody() << std::endl;
    }
  }

  return 0;
}
