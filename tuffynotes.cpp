//Using the solution for Tuffynotes.cpp Project Milestone 1
//Jizzelle Cardenas

#include <iostream>
#include <string>
#include "notebook.hpp"

void createNote();

int main()
{
  char choice;
  std::string rem;
  bool display_menu = true;
  std::string array[] = 0;

  std::cout << "Welcome to TuffyNotes!\n";

  do {
    std::cout << "[C] Create a note" << std::endl;
    std::cout << "[E] Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    std::getline(std::cin, rem);
    if (rem.length() > 0) {
      choice = ' ';
    }
    std::cout << std::endl;

    switch (choice) {
      case 'C':
      case 'c':
        createNote();
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
    if (!array[i].getTitle().empty() || !array[i].getNote().empty()) {
      std::cout << "Array location [" << i << "]: <" << array[i].getTitle()
        << "> " << array[i].getNote() << std::endl;
    }
  }

  return 0;
}
