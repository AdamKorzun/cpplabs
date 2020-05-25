//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainForm.h"
//#include "Player.h"
#include "Container.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Container playerArray;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SaveButtonClick(TObject *Sender)
{
	if (Form3->ComboBox->Text == "All") {
		Form3->MemoText->Lines->SaveToFile("C:\\Users\\admin\\Desktop\\�++\\2\ sem\\lab2\\file.txt");
		Form3->ComboBox->Clear();

        playerArray.SetLength(0);
		TStringList *stringList = new TStringList;
		stringList->LoadFromFile("C:\\Users\\admin\\Desktop\\�++\\2\ sem\\lab2\\file.txt");
		Form3->ComboBox->Items->Add("All");
		Player temp;
		for(int i = 0; i < stringList->Count; i++){

			if (i % 5 == 1) {
				temp.SetClub(stringList->Strings[i]);
			}
			if (i % 5 == 2) {
				temp.SetRole(stringList->Strings[i]);
			}
			if (i % 5 == 3) {
				temp.SetNumberOfGoals(StrToInt(stringList->Strings[i]));
				//Form3->MemoText->Lines->Add(IntToStr(StrToInt(stringList->Strings[i])));
			}
			if (i % 5 == 4) {
				temp.SetPenalties(StrToInt(stringList->Strings[i]));
				playerArray.Add(temp);

			}

			if (i % 5 == 0) {
				temp.SetName(stringList->Strings[i]);
				Form3->ComboBox->Items->Add(stringList->Strings[i]);
			}

		}
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm3::ShowButtonClick(TObject *Sender)
{
	if (Form3->ComboBox->Text == "All") {
		Form3->MemoText->Clear();
		Form3->MemoText->Lines->LoadFromFile("C:\\Users\\admin\\Desktop\\�++\\2\ sem\\lab2\\file.txt");
	}
	else {
		Form3->MemoText->Clear();
		Player pl = playerArray.Search(Form3->ComboBox->Text);
		Form3->MemoText->Lines->Add(pl.GetName());
		Form3->MemoText->Lines->Add(pl.GetClub());
		Form3->MemoText->Lines->Add(pl.GetRole());
		Form3->MemoText->Lines->Add(IntToStr(pl.GetNumberOfGoals()));
		Form3->MemoText->Lines->Add(IntToStr(pl.GetPenalties()));
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
	//Form3->MemoText->Lines->LoadFromFile("C:\\Users\\admin\\Desktop\\�++\\2\ sem\\lab2\\file.txt");
	//Form3->ComboBox->Items->LoadFromFile("C:\\Users\\admin\\Desktop\\�++\\2\ sem\\lab2\\file.txt");
	TStringList *stringList = new TStringList;
	stringList->LoadFromFile("C:\\Users\\admin\\Desktop\\�++\\2\ sem\\lab2\\file.txt");
	Form3->ComboBox->Items->Add("All");
	Player temp;
	for(int i = 0; i < stringList->Count; i++){

		if (i % 5 == 1) {
			temp.SetClub(stringList->Strings[i]);
		}
		if (i % 5 == 2) {
			temp.SetRole(stringList->Strings[i]);
		}
		if (i % 5 == 3) {
			temp.SetNumberOfGoals(StrToInt(stringList->Strings[i]));
			//Form3->MemoText->Lines->Add(IntToStr(StrToInt(stringList->Strings[i])));
		}
		if (i % 5 == 4) {
			temp.SetPenalties(StrToInt(stringList->Strings[i]));
			playerArray.Add(temp);

		}

		if (i % 5 == 0) {
			temp.SetName(stringList->Strings[i]);
			Form3->ComboBox->Items->Add(stringList->Strings[i]);
		}

	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm3::TopTenClick(TObject *Sender)
{
	Player* sortedPlayers = playerArray.TopTenGoals();
	Form3->MemoText->Clear();
	for (int i = 0; i < playerArray.GetLength(); i++) {
		Form3->MemoText->Lines->Add(sortedPlayers[i].GetName());
		Form3->MemoText->Lines->Add(sortedPlayers[i].GetClub());
		Form3->MemoText->Lines->Add(sortedPlayers[i].GetRole());
		Form3->MemoText->Lines->Add(IntToStr(sortedPlayers[i].GetNumberOfGoals()));
		Form3->MemoText->Lines->Add(IntToStr(sortedPlayers[i].GetPenalties()));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Player* sortedPlayers = playerArray.SortPenalties();
	Form3->MemoText->Clear();
	for (int i = 0; i < playerArray.GetLength(); i++) {
		if (i >= 10) {
			break;
		}
		Form3->MemoText->Lines->Add(sortedPlayers[i].GetName());
		Form3->MemoText->Lines->Add(sortedPlayers[i].GetClub());
		Form3->MemoText->Lines->Add(sortedPlayers[i].GetRole());
		Form3->MemoText->Lines->Add(IntToStr(sortedPlayers[i].GetNumberOfGoals()));
		Form3->MemoText->Lines->Add(IntToStr(sortedPlayers[i].GetPenalties()));
	}
}
//---------------------------------------------------------------------------

