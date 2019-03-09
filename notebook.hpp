#include <string>
#include <memory>

class Note
{
  private:
    std::string title_, note_;

  public:
    void createNote();
    //Public Accessors
    std::string getTitle { return title_; }
    std::string getNote { return note_; }
    //Public Mutators
    
}
