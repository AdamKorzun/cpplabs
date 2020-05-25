//---------------------------------------------------------------------------
#include "string.h"
#ifndef BusH
#define BusH
//---------------------------------------------------------------------------
#endif
class Bus {
	private:
	int number;
	String type;
	String destination;
	int departureTime;
	int arrivalTime;

	public:
	Bus(int number, String type, String destination, int departureTime, int arrivalTime, Bus *next){
		this->number = number;
		this->type = type;
		this->destination = destination;
		this->departureTime = departureTime;
		this->arrivalTime = arrivalTime;
		this->next = next;
	}
	Bus(){}
    Bus *next;
	int GetNumber();
	void SetNumber(int);
	String GetType();
	void SetType(String);
	String GetDestination();
	void SetDestination(String);
	int GetDepartureTime();
	void SetDepartureTime(int);
	int GetArrivalTime();
	void SetArrivalTime(int);

};
