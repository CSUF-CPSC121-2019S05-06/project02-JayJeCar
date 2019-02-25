#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../notebook.hpp"

TEST(Milestone1, FiniteChoiceLoop) {
  srand(time(NULL));
  ASSERT_DURATION_LE(3, { main_output("tuffynotes", "c\nX\nX\ne"); });
}

TEST(Milestone1, CreateQuestionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\ne\n", unittest_output); });
}

TEST(Milestone1, QuitChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "e\n", unittest_output); });
}

TEST(Milestone1, InvalidOptionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n[C] Create a note\n[E] Exit\n"
      "Choice: \nInvalid choice. Please try "
      "again.\n\n[C] Create a note\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, {ASSERT_EXECIO_EQ("tuffynotes", "x\ne\n", unittest_output)});
}

TEST(Milestone1, ChoiceLoopLowercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!\n";
  char choices[] = {'c', 'e', 'C', 'E'};
  char choice = ' ';
  do {
    choice = choices[rand() % 2];
    unittest_output += "[C] Create a note\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'c':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n\n";
      input += "t\\nb\\n";
      break;
    case 'e':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "Invalid choice. Please try again.\n\n";
    }
  } while (choice != 'e');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST(Milestone1, ChoiceLoopUppercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!\n";
  char choices[] = {'c', 'e', 'C', 'E'};
  char choice = ' ';
  do {
    choice = choices[rand() % 2 + 2];
    unittest_output += "[C] Create a note\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'C':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n\n";
      input += "t\\nb\\n";
      break;
    case 'E':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "Invalid choice. Please try again.\n\n";
    }
  } while (choice != 'E');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST(Milestone2, NoteClass) {
  Note temp;
  temp.set_title("title");
  temp.set_body("body");
  temp.title();
  temp.body();
}

TEST(Milestone2, TitleGetSet) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  your_note_object.set_title(unittest_title);
  ASSERT_EQ(your_note_object.title(), unittest_title);
}

TEST(Milestone2, BodyGetSet) {
  Note your_note_object;
  std::string unittest_body = generate_string(10);
  your_note_object.set_body(unittest_body);
  ASSERT_EQ(your_note_object.body(), unittest_body);
}

TEST(Milestone2, CreateNote) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  std::string unittest_body = generate_string(10);
  std::string input = unittest_title + "\n" + unittest_body + "\n";
  std::string unittest_output = "\nPlease enter the note's title: ";
  unittest_output += "Please enter the note: \nNote added!\n\n";
  ASSERT_SIO_EQ(input, unittest_output, {
    your_note_object = create_note();
  });
  ASSERT_EQ(your_note_object.title() , unittest_title);
  ASSERT_EQ(your_note_object.body(), unittest_body);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
