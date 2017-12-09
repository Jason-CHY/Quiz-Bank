#ifndef QUESTIONSA_HPP
#define QUESTIONSA_HPP
#include "Question.hpp"

class QuestionSA : public Question{
public:
  virtual void getLine();
  virtual void setLine(const string& line);
};

#endif
