//---------------------------------------------------------------------------

#include <vcl.h>
#include <exception>
#include <iostream>
#pragma hdrstop
#include "Bus.cpp"
#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Bus* firstBus = new Bus();
Bus* head = firstBus;

Bus* firstOTWBus = new Bus();
Bus* OTWHead = firstOTWBus;

bool timerOn = false;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm3::EnterPress(TObject *Sender, System::WideChar &Key)
{
	if (Key != VK_RETURN) {
    	Form3->TypeMemo->Clear();
		Form3->DestMemo->Clear();
		Form3->DestinationMemo->Clear();
		Form3->DepartureComboHours->Text = "0";
		Form3->DepartureComboMin->Text = "0";
		Form3->ArrivalComboHours->Text = "0";
		Form3->ArrivalComboMin->Text = "0";
		return;
	}

	Form3->Memo1->Clear();
	try{
		StrToInt(Form3->BusCombo->Text);
	}
	catch(...){
		Form3->Memo1->Lines->Add("Error occured");
		return;
	}

	Bus* iteration = firstBus;
	while(iteration->next){
		if (iteration->GetNumber() == StrToInt(Form3->BusCombo->Text)) {
			return;
		}
		iteration = iteration->next;
	}
	Form3->BusCombo->Items->Add(Form3->BusCombo->Text);
	head->next = new Bus();




	head->SetNumber(StrToInt(Form3->BusCombo->Text));

	head->SetType(Form3->TypeMemo->Lines->Strings[0]);
	head->SetDestination(Form3->DestMemo->Lines->Strings[0]);
	head->SetDepartureTime(StrToInt(Form3->DepartureComboHours->Text) * 60 + StrToInt(Form3->DepartureComboMin->Text));
	head->SetArrivalTime(StrToInt(Form3->ArrivalComboHours->Text) * 60 + StrToInt(Form3->ArrivalComboMin->Text));
	//Form3->Memo1->Lines->Add(head->GetNumber());
	head = head->next;
	head->next = nullptr;


}
//---------------------------------------------------------------------------
void __fastcall TForm3::SaveButtonClick(TObject *Sender)
{
	Bus* iteration = firstBus;
	while(iteration->next){
		if (iteration->GetNumber() == StrToInt(Form3->BusCombo->Text)) {

			iteration->SetNumber(StrToInt(Form3->BusCombo->Text));
			iteration->SetType(Form3->TypeMemo->Lines->Strings[0]);
			iteration->SetDestination(Form3->DestMemo->Lines->Strings[0]);
			iteration->SetDepartureTime(StrToInt(Form3->DepartureComboHours->Text) * 60 + StrToInt(Form3->DepartureComboMin->Text));
			iteration->SetArrivalTime(StrToInt(Form3->ArrivalComboHours->Text) * 60 + StrToInt(Form3->ArrivalComboMin->Text));
			return;
		}
		iteration = iteration->next;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ShowButtonClick(TObject *Sender)
{
	Bus* iteration = firstBus;
	Form3->Memo1->Clear();
	if (Form3->BusCombo->Text == "All") {
		while(iteration->next){
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetNumber()));
			Form3->Memo1->Lines->Add(iteration->GetType());
			Form3->Memo1->Lines->Add(iteration->GetDestination());
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetDepartureTime()));
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetArrivalTime()));
			Form3->Memo1->Lines->Add("");
			iteration = iteration->next;
		}
		return;
	}

	while(iteration->next){
		if (iteration->GetNumber() == StrToInt(Form3->BusCombo->Text)) {

			Form3->Memo1->Lines->Add(IntToStr(iteration->GetNumber()));
			Form3->Memo1->Lines->Add(iteration->GetType());
			Form3->Memo1->Lines->Add(iteration->GetDestination());
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetDepartureTime()));
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetArrivalTime()));

			return;
		}
		iteration = iteration->next;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CreateForm(TObject *Sender)
{
	Form3->TypeMemo->Clear();
	Form3->DestMemo->Clear();
	Form3->DestinationMemo->Clear();
	Form3->DestinationMemo2->Clear();
	Form3->BusCombo->Items->Add("All");
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Form3->Memo1->Clear();
	Bus* iteration = firstBus;
	while(iteration->next){
		if (iteration->GetDestination() == Form3->DestinationMemo->Lines->Strings[0]) {
			if (StrToInt(Form3->SortHours->Text) * 60 + StrToInt(Form3->SortMins->Text) > iteration->GetArrivalTime()) {
				Form3->Memo1->Lines->Add(IntToStr(iteration->GetNumber()));
				Form3->Memo1->Lines->Add(iteration->GetType());
				Form3->Memo1->Lines->Add(iteration->GetDestination());
				Form3->Memo1->Lines->Add(IntToStr(iteration->GetDepartureTime()));
				Form3->Memo1->Lines->Add(IntToStr(iteration->GetArrivalTime()));
				Form3->Memo1->Lines->Add("");
			}


		}
		iteration = iteration->next;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm3::DestPButtonClick(TObject *Sender)
{
	Form3->Memo1->Clear();
	Bus* iteration = firstBus;
	while(iteration->next){
		if (Form3->DestinationMemo2->Lines->Strings[0] == iteration->GetDestination()) {


			Form3->Memo1->Lines->Add(IntToStr(iteration->GetNumber()));
			Form3->Memo1->Lines->Add(iteration->GetType());
			Form3->Memo1->Lines->Add(iteration->GetDestination());
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetDepartureTime()));
			Form3->Memo1->Lines->Add(IntToStr(iteration->GetArrivalTime()));
			Form3->Memo1->Lines->Add("");



		}
		iteration = iteration->next;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	Form3->Memo1->Clear();
	Bus* iteration = firstOTWBus;
	while(iteration->next){


		Form3->Memo1->Lines->Add(IntToStr(iteration->GetNumber()));
		Form3->Memo1->Lines->Add(iteration->GetType());
		Form3->Memo1->Lines->Add(iteration->GetDestination());
		Form3->Memo1->Lines->Add(IntToStr(iteration->GetDepartureTime()));
		Form3->Memo1->Lines->Add(IntToStr(iteration->GetArrivalTime()));
		Form3->Memo1->Lines->Add("");




		iteration = iteration->next;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	int timer =  StrToInt(Form3->ComboHours2->Text) * 60 + StrToInt(Form3->ComboMins2->Text);
	if (!timerOn) {
		return;
	}
	if (timer >= 1440) {
		timer = 0;
		return;
	}
	timer++;
	Form3->ComboHours2->Text= timer  /60;
	Form3->ComboMins2->Text  = timer % 60;
	bool atStation = true;
	Bus* iterationMO = firstBus;
	Bus* iteration;
	if (iterationMO->next) {
		iteration = iterationMO->next;


	}
	else{
		//Memo1->Lines->Add("Empty1: ");
		atStation = false;
	}




	if (atStation) {
		if (timer > iterationMO->GetDepartureTime() && timer < iterationMO->GetArrivalTime()) {
			Memo1->Lines->Add("Left: " + IntToStr(iterationMO->GetNumber())+ " " + timer / 60 + ":" + timer%60);
			OTWHead->next = new Bus();
			OTWHead->SetNumber(iterationMO->GetNumber());
			OTWHead->SetType(iterationMO->GetType());
			OTWHead->SetDestination(iterationMO->GetDestination());
			OTWHead->SetDepartureTime(iterationMO->GetDepartureTime());
			OTWHead->SetArrivalTime(iterationMO->GetArrivalTime());
			OTWHead = OTWHead->next;
			OTWHead->next = nullptr;

			firstBus = iterationMO->next;

			//iteration = firstBus->next;

		}
		while(iteration->next){
			if (timer > iteration->GetDepartureTime() && timer < iteration->GetArrivalTime()) {
				Memo1->Lines->Add("Left: " + IntToStr(iteration->GetNumber())+ " " + timer / 60 + ":" + timer%60);
				OTWHead->next = new Bus();
				OTWHead->SetNumber(iteration->GetNumber());
				OTWHead->SetType(iteration->GetType());
				OTWHead->SetDestination(iteration->GetDestination());
				OTWHead->SetDepartureTime(iteration->GetDepartureTime());
				OTWHead->SetArrivalTime(iteration->GetArrivalTime());
				OTWHead = OTWHead->next;
				OTWHead->next = nullptr;
				iterationMO->next = iteration->next;

				iteration = iteration->next;
			}
			if (iterationMO->next) {
				iterationMO = iterationMO->next;
			}

			if (iteration->next) {
				iteration = iteration->next;
			}
			else {
				break;
			}

		}
	}

	bool onRoad = true;
	iterationMO = firstOTWBus;
	iteration = iterationMO;
	if (iterationMO->next) {
		iteration = iterationMO->next;
		//Memo1->Lines->Add("Empty2: ");
	}
	else{
		onRoad = false;

	}

	if (onRoad) {
		if (timer <= iterationMO->GetDepartureTime() || timer > iterationMO->GetArrivalTime()) {
			Memo1->Lines->Add("Back: " + IntToStr(iterationMO->GetNumber())+ " " + timer / 60 + ":" + timer%60);
			head->next = new Bus();
			head->SetNumber(iterationMO->GetNumber());
			head->SetType(iterationMO->GetType());
			head->SetDestination(iterationMO->GetDestination());
			head->SetDepartureTime(iterationMO->GetDepartureTime());
			head->SetArrivalTime(iterationMO->GetArrivalTime());
			head = head->next;
			head->next = nullptr;

			firstOTWBus = iterationMO->next;

			//iteration = firstOTWBus->next;
		}
		while(iteration->next){
			if (timer <= iteration->GetDepartureTime() || timer > iteration->GetArrivalTime()) {
				Memo1->Lines->Add("Back: " + IntToStr(iteration->GetNumber())+ " " + timer / 60 + ":" + timer%60);
				head->next = new Bus();
				head->SetNumber(iteration->GetNumber());
				head->SetType(iteration->GetType());
				head->SetDestination(iteration->GetDestination());
				head->SetDepartureTime(iteration->GetDepartureTime());
				head->SetArrivalTime(iteration->GetArrivalTime());
				head = head->next;
				head->next = nullptr;
				iterationMO->next = iteration->next;

				iteration = iteration->next;
			}
			if (iterationMO->next) {
				iterationMO = iterationMO->next;
			}

			if (iteration->next) {
				iteration = iteration->next;
			}
			else {
				break;
			}

		}
	}





}
//---------------------------------------------------------------------------
void __fastcall TForm3::TimerControlButtonClick(TObject *Sender)
{
	timerOn = !timerOn;
}
//---------------------------------------------------------------------------
