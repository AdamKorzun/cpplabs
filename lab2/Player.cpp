//---------------------------------------------------------------------------

#pragma hdrstop
#include <string.h>
#include <iostream>
#include <System.hpp>
#include "Player.h"

Player::Player()
	{

	}
Player::Player(UnicodeString name, UnicodeString club, UnicodeString role,
	int numberOfGoals, int penalties)
	{
	this->name = name;
	this->club = club;
	this->role = role;
	this->numberOfGoals = numberOfGoals;
	this->penalties = penalties;
	}
void Player::SetName(UnicodeString name)
{
	this->name = name;
}
void Player::SetClub(UnicodeString club)
{
	this->club = club;
}
void Player::SetRole(UnicodeString role)
{
	this->role = role;
}
void Player::SetNumberOfGoals(int numberOfGoals)
{
	this->numberOfGoals = numberOfGoals;
}
void Player::SetPenalties(int penalties)
{
	this->penalties = penalties;
}
UnicodeString Player::GetName(){
	return name;
}
UnicodeString Player::GetClub(){
	return club;
}
UnicodeString Player::GetRole(){
	return role;
}
int Player::GetNumberOfGoals(){

	return numberOfGoals;
}
int Player::GetPenalties(){
	return penalties;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
