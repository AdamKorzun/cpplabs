//---------------------------------------------------------------------------

#ifndef ContainerH
#define ContainerH
#include "Player.h"
//---------------------------------------------------------------------------
class Container{
	private:
	int length;
	Player *playerArray = new Player[0];
	public:
	Container();
	Container(int);

	void Add(Player);
	Player Search(UnicodeString);
	int GetLength();
    void SetLength(int);
	Player* TopTenGoals();
    Player* SortPenalties();


	~Container(){}
};
#endif
