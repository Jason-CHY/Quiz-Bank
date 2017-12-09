#ifndef QUESTIONTF_HPP
#define QUESTIONTF_HPP
#include "Question.hpp"

class QuestionTF : public Question{
public:
  virtual void getLine();
  virtual void setLine(const string& line);

};

#endif
