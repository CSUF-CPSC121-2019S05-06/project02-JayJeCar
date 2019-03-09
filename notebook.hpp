#include <string>
#include <memory>

class Note
{
  private:
    std::string title_, body_;

  public:
    void createNote();
    //Public Accessors
    std::string getTitle { return title_; }
    std::string getBody { return body_; }
    //Public Mutators
    void setTitle() { title_ = title; }
    void setBody() { body_ = note; }
};
