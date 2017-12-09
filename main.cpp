#include "Question.hpp"
#include "Player.hpp"
#include "QuestionTF.hpp"
#include "QuestionMC.hpp"
#include "QuestionSA.hpp"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

string ask_user_enter_first_name();
string ask_user_enter_last_name();
void check_file_enter_status(ifstream& Quiz);

int main()
{
  vector <Question *> qlist;
  srand(time(NULL));

  Player *p = new Player;
  string fname = ask_user_enter_first_name();
  p->setFname(fname);
  string lname = ask_user_enter_last_name();
  p->setLname(lname);

  string filename, line;
  cout << "Filename: ";
  getline(cin, filename);
  ifstream Quiz(filename.c_str());

  check_file_enter_status(Quiz);

  string no_of_que;
  int num_in_file, noq, point;
  getline(Quiz,line);
  stringstream(line)>>num_in_file;

  //pull question from file and store it in particular class
  while(!Quiz.eof())
  {
    Quiz >> line;
    if (line=="TF")
    {
      Question *q = new QuestionTF;
      q->setType(line);
      Quiz >> line;
      stringstream(line)>>point;
      q->setPoint(point);
      Quiz.ignore();
      getline(Quiz, line);
      q->setLine(line);
      getline(Quiz, line);
      q->setAnswer(line);

      qlist.push_back(q);
    }
    if (line=="MC")
    {
      int no_of_Choice;
      Question *q = new QuestionMC;
      q->setType(line);
      Quiz>>line;
      stringstream(line)>>point;
      q->setPoint(point);
      Quiz.ignore();
      getline(Quiz, line);
      q->setLine(line);
      getline(Quiz, line);
      stringstream(line) >> no_of_Choice;
      for(int i=0; i<no_of_Choice; i++)
      {
        getline(Quiz, line);
        q->setLine(line);
      }
      getline(Quiz, line);
      q->setAnswer(line);

      qlist.push_back(q);
    }
    if (line=="SA")
    {
      Question *q = new QuestionSA;
      q->setType(line);
      Quiz >> line;
      stringstream(line)>>point;
      q->setPoint(point);
      Quiz.ignore();
      getline(Quiz, line);
      q->setLine(line);
      getline(Quiz, line);
      q->setAnswer(line);

      qlist.push_back(q);
    }
  }

  Quiz.close();

  //set random question for user
  int count=0;
  string panswer, type;
  int totalpoint=0;
  vector<int> vrandom;
  cout << "No. of question: " << num_in_file << endl;
  cout << "How many questions would you like (out of " << num_in_file << ")?" << endl;
  getline(cin, no_of_que);
  stringstream(no_of_que)>>noq;
  while(noq<1 || noq>num_in_file)
  {
    cout << "Invalid input. How many questions would you like (out of " << num_in_file << ")?" << endl;
    getline(cin, no_of_que);
    stringstream(no_of_que)>>noq;
  }
  int random;
  bool check;
  for(int i=0;i<noq;i++)
  {
    do
    {
      random = rand()%noq;
      check=true;
      for (int j=0;j<i;j++)
      {
        if (random == vrandom[j])
        {
          check=false;
          break;
        }
      }
    }while (!check);
    vrandom.push_back(random);
  }  
  for(int i=0; i<noq;i++)
  {
    cout << "Question " << count+1 << " (" << qlist[vrandom[i]]->getPoint() << " points)"<< endl;
    qlist[vrandom[i]]->getLine();
    cin >> panswer;
    if (panswer!= qlist[vrandom[i]]->getAnswer())
    {
      cout << "Incorrect, the answer was " << qlist[vrandom[i]]->getAnswer() << ". You lose " << qlist[vrandom[i]]->getPoint() <<  " points.\n\n";
      totalpoint = totalpoint - qlist[vrandom[i]]->getPoint();
    }
    else
    {
      cout << "Correct! You get " << qlist[vrandom[i]]->getPoint() << " points.\n\n";
      totalpoint = totalpoint + qlist[vrandom[i]]->getPoint();
    }
    count++;
  }


  p->setPoint(totalpoint);

  cout << p->getFname() << " " << p->getLname()
       << ", Your game is over!\nYour final scare is "
       << p->getPlayerPoint() << " points.\nBetter luck next time.\n\n";


  //store best player performance
  ofstream player_performance("Player_Performance.txt", ios::out | ios::app);
  player_performance << p->getFname() << " " << p->getLname() << ", total point " << p->getPlayerPoint() << " points.\r\n";
  player_performance.close();
  string bline;
  char seebest;
  cout << "Enter Y/y to view the past player performance. Enter any letter to skip: ";
  cin >> seebest;
  if (seebest == 'Y' || seebest == 'y')
  {
    ifstream best("Player_Performance.txt");
    while(!best.eof())
    {
      getline(best, bline);
      cout << bline << endl;
    }
  }

  return 0;
}

string ask_user_enter_first_name()
{
  string fname;
  cout << "What is your first name?\n";
  getline(cin, fname);

  return fname;
}

string ask_user_enter_last_name()
{
  string lname;
  cout << "What is your last name?\n";
  getline(cin, lname);

  return lname;
}

void check_file_enter_status(ifstream& Quiz)
{
  if (Quiz.is_open())
  {
    cout << "Reading data.....\n\n";
  }
  else{
    cout << "Fail to connect to the server.\n";
    cout << "Please ensure your filename is correct.\n";
    exit(0);
  }
}
