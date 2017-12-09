#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <iostream>
using namespace std;

class Player{
  string first_name, last_name;
  int player_point;
public:
  Player(string first_name = "Unknown", string last_name = "Unknowm"):first_name(first_name), last_name(last_name){
    player_point = 0;
  }
  ~Player();
  void setPoint(const int& player_point);
  void setFname(string& first_name);
  void setLname(string& last_name);
  int getPlayerPoint();
  string getFname();
  string getLname();
};

#endif
