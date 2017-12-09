#include "QuestionMC.hpp"

void QuestionMC::setLine(const string& line)
{
  vline.push_back(line);
}

void QuestionMC::getLine()
{
  cout << vline[0] << endl;
  string ab = "ABCDEF";
  for(int i=1; i<vline.size(); i++)
  {
    cout << ab[i-1] << ") " << vline[i] << endl;
  }
}
