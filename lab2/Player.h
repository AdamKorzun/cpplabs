//---------------------------------------------------------------------------
//#include <ustring.h>

#ifndef PlayerH
#define PlayerH
#include <string.h>
#include <iostream>
#include <System.hpp>
//---------------------------------------------------------------------------
#endif

class Player{
	private:
		UnicodeString name;
		UnicodeString club;
		UnicodeString role;
		int numberOfGoals;
		int penalties;
	public:
		Player();
		Player(UnicodeString name, UnicodeString club, UnicodeString role, int numberOfGoals, int penalties);
		void SetName(UnicodeString);
		void SetClub(UnicodeString);
		void SetRole(UnicodeString);
		void SetNumberOfGoals(int);
		void SetPenalties(int);
		UnicodeString GetName();
		UnicodeString GetClub();
		UnicodeString GetRole();
		int GetNumberOfGoals();
		int GetPenalties();
		~Player(){}
};
