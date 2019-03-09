#include "notebook.hpp"

void Note::createNote() //Function Implementation
{
  //Putting array in here
  title_ = title;
  body_ = note;

  std::cout << "Please enter the note's title: ";
  std::getline(std::cin, title);
  std::cout << "Please enter the note: ";
  std::getline(std::cin, note);

  std::cout << "\nNote added!\n\n";
}
