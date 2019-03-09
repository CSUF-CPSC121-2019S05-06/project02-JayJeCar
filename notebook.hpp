#include <string>
#include <memory>

class Note
{
  private:
    std::string title_, note_;

  public:
    void createNote();
    //Public Accessors
    std::string gettitle { return title_; }
    std::string getnote { return note_; }
}
