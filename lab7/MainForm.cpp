//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "HashTable.h"
#include "Stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
HashTable* table;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
	Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	try {
		table = new HashTable(StrToInt(Edit2->Text));
	} catch (...) {
		return;
	}
	for (int i = 0; i < StrToInt(Edit1->Text); i++) {
		int random =  1 + rand() % 100;
		table->Add(random);
		Memo1->Lines->Add(IntToStr(random));
	}
	int* keyArr = new int[StrToInt(Edit1->Text)];
	int pos = 0;
	for (int i = 0; i < StrToInt(Edit2->Text); i++) {

		Stack* stack = table->GetStack(i);
		String str = "";
		while (stack->Filled()){
			keyArr[pos] = stack->GetKey();
			str += IntToStr(stack->GetKey());
			str+= "->";
			stack = stack->Pop();


			pos++;

		}
		table->SetStack(i, stack);
		Memo3->Lines->Append(str);


	}
	for (int i = 0; i < StrToInt(Edit1->Text); i++) {

		table->Add(keyArr[i]);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::DeleteButtonClick(TObject *Sender)
{
	table->DeleteTable();
	Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	int keySum = 0;
	int* keyArr = new int[StrToInt(Edit1->Text)];
	int pos = 0;

	for (int i = 0; i < StrToInt(Edit2->Text); i++) {

		Stack* stack = table->GetStack(i);

		while (stack->Filled()){
			keyArr[pos] = stack->GetKey();
			keySum += stack->GetKey();

			stack = stack->Pop();


			pos++;

		}
		table->SetStack(i, stack);



	}
	for (int i = 0; i < StrToInt(Edit1->Text); i++) {

		table->Add(keyArr[i]);

	}


	Memo2->Lines->Add("Average: " + IntToStr(keySum  / StrToInt(Edit1->Text)));
	int biggerKeys = 0;
	for (int i = 0; i < StrToInt(Edit1->Text); i++) {
		if (keyArr[i] > keySum  / StrToInt(Edit1->Text)) {
		   biggerKeys++;
		}
	}
	Memo2->Lines->Add("Bigger: " + IntToStr(biggerKeys));
}
//---------------------------------------------------------------------------

