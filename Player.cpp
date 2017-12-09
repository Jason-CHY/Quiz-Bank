#include "Player.hpp"

void Player::setPoint(const int& player_point)
{
  this->player_point = player_point;
}

Player::~Player()
{
  cout << "PLayer has been deleted.\n";
}

void Player::setFname(string& first_name)
{
  this->first_name = first_name;
}

void Player::setLname(string& last_name)
{
  this->last_name = last_name;
}

string Player::getFname()
{
  return first_name;
}

string Player::getLname()
{
  return last_name;
}

int Player::getPlayerPoint()
{
  return player_point;
}
