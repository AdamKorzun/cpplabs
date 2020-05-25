//---------------------------------------------------------------------------

#pragma hdrstop

#include "Bus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Bus::GetNumber(){
	return number;
}
void Bus::SetNumber(int number){
    this->number = number;
}
String Bus::GetType(){
	return type;
}
void Bus::SetType(String type){
	this->type = type;
}
String Bus::GetDestination(){
	return destination;
}
void Bus::SetDestination(String destination){
	this->destination = destination;
}
int  Bus::GetDepartureTime(){
	return departureTime;
}
void Bus::SetDepartureTime(int departureTime){
	this->departureTime = departureTime;
}
int  Bus::GetArrivalTime(){
	return arrivalTime;
}
void Bus::SetArrivalTime(int arrivalTime){
	this->arrivalTime = arrivalTime;
}

