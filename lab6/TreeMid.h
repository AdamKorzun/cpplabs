//---------------------------------------------------------------------------

#ifndef TreeMidH
#define TreeMidH
#include "Tree.h"
class TreeMid : public Tree{
	public:
	void GetAverage(TMemo* memo, int numOfEls){
		memo->Clear();

		int averageNum = 0;
		root->Average(&averageNum, memo);

		averageNum /= numOfEls;
		int artr = root->GetPassNum();
		String astr = root->GetFio();
		float deviation = float(abs(averageNum - artr));
		root->FindAverage(&astr,&artr, averageNum, &deviation);
		memo->Lines->Add(astr + ":" + IntToStr(artr));
	}

};
//---------------------------------------------------------------------------
#endif
