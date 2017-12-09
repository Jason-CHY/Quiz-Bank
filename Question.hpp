#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Question{
  int point;
  string type;
  string answer;
protected:
  string line;
public:
  virtual ~Question()=0;
  virtual void setLine(const string& line);
  void setType(string type);
  void setPoint(const int& point);
  void setAnswer(const string& answer);
  virtual void getLine();
  string getAnswer();
  string getType();
  int getPoint();
};

#endif
