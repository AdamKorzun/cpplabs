//---------------------------------------------------------------------------

#pragma hdrstop

#include "Container.h"
Container::Container(){
	length = 0;
}
Container::Container(int length){
	this->length = length;
	playerArray = new Player[length];
}
void Container::Add(Player newPlayer){
	int newLength = length + 1;
	Player *tempArray = new Player[length];
	for (int i = 0; i < length; i++) {
		tempArray[i] = playerArray[i];
	}
	playerArray = new Player[newLength];
	for(int i = 0; i < length;i++){
		playerArray[i] = tempArray[i];
	}
	playerArray[newLength - 1] = newPlayer;
	length++;
	delete[] tempArray;

}
Player Container::Search(UnicodeString name){
	for (int i = 0; i < length; i++) {
		if (name == playerArray[i].GetName()) {
			return playerArray[i];
		}
	}
}
int Container::GetLength(){
	return length;
}
void Container::SetLength(int length){
	this->length = length;
}
Player* Container::TopTenGoals(){
	Player* retArray = new Player[length];
	for (int i = 0; i < length; i++) {
		retArray[i] = playerArray[i];
	}
	Player tempPlayer;
	int minGoals = retArray[0].GetNumberOfGoals();
	for (int i = 0; i < length; i++) {
		minGoals = retArray[i].GetNumberOfGoals();
		for (int j = i; j < length; j++) {
			if (retArray[j].GetNumberOfGoals() > minGoals) {
				minGoals = retArray[j].GetNumberOfGoals();
				tempPlayer = retArray[i];
				retArray[i] = retArray[j];
				retArray[j] = tempPlayer;
			}
		}
	}
	return retArray;

}
Player* Container::SortPenalties(){
	Player* retArray = new Player[length];
	for (int i = 0; i < length; i++) {
		retArray[i] = playerArray[i];
	}
	Player tempPlayer;
	int minGoals = retArray[0].GetPenalties();
	for (int i = 0; i < length; i++) {
		minGoals = retArray[i].GetPenalties();
		for (int j = i; j < length; j++) {
			if (retArray[j].GetPenalties() > minGoals) {
				minGoals = retArray[j].GetPenalties();
				tempPlayer = retArray[i];
				retArray[i] = retArray[j];
				retArray[j] = tempPlayer;
			}
		}
	}
	return retArray;

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
