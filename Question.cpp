#include "Question.hpp"

Question::~Question()
{
  cout << "Object has been deleted." << endl;
}

int Question::getPoint()
{
  return point;
}

void Question::setPoint(const int& point)
{
  this->point = point;
}

void Question::setLine(const string& line)
{
  this->line = line;
}

void Question::getLine()
{
  cout << line << endl;
}

void Question::setAnswer(const string& answer)
{
  this->answer = answer;
}

string Question::getAnswer()
{
  return answer;
}

void Question::setType(string type)
{
  this->type = type;
}

string Question::getType()
{
  return type;
}
