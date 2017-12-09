#ifndef QUESTIONMC_HPP
#define QUESTIONMC_HPP
#include "Question.hpp"
#include <vector>
#include <string>
using namespace std;

class QuestionMC : public Question{
  vector<string>vline;
public:
  virtual void setLine(const string& line);
  virtual void getLine();
};

#endif
