//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Tree.h"
#include "TreeMid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Tree tree;
int numberOfElements = 0;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::NumberOfElsChange(TObject *Sender)
{
	try{
		StringGrid1->RowCount = StrToInt(NumberOfEls->Text);
		numberOfElements = StrToInt(NumberOfEls->Text);
	}
	catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FillButtonClick(TObject *Sender)
{
    tree.~Tree();
	for(int i = 0; i < numberOfElements; i++){
		tree.Insert(StringGrid1->Cells[0][i], StrToInt(StringGrid1->Cells[1][i]));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::PrintButtonClick(TObject *Sender)
{
	Memo1->Clear();
	TreeView1->Items->Clear();
	for (int i = 0; i < numberOfElements; i++) {
		Memo1->Lines->Add(StringGrid1->Cells[0][i] + ":" + StringGrid1->Cells[1][i]);
	}
	tree.Print(TreeView1,Form3->Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BalanceButtonClick(TObject *Sender)
{
	tree.~Tree();
	String* strArr = new String[numberOfElements];
	int* intArr = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++) {
		strArr[i] = StringGrid1->Cells[0][i];
		intArr[i] = StrToInt(StringGrid1->Cells[1][i]);
	}
	int minEl = 0;
	String tempStr;
	int temp;
	for (int i = 0; i < numberOfElements; i++) {
		minEl = i;
		for (int j=i; j < numberOfElements; j++) {
			if (intArr[j] < intArr[minEl]) {
				minEl = j;
			}
		}
		temp = intArr[i];
		tempStr = strArr[i];
		intArr[i] = intArr[minEl];
		strArr[i] = strArr[minEl];
		intArr[minEl] = temp;
		strArr[minEl] = tempStr;

	}



	tree.Balance(strArr,intArr,0,numberOfElements);


	/*
	for(int i = 0; i < numberOfElements; i++){
		tree.Balance(StringGrid1->Cells[0][i], StrToInt(StringGrid1->Cells[1][i]));
	}
	*/
}
//---------------------------------------------------------------------------
void __fastcall TForm3::AddButtonClick(TObject *Sender)
{
	tree.Insert(FioAddEdit->Text,StrToInt(PassNumAddEdit->Text));
	numberOfElements++;
	StringGrid1->RowCount+=1;
	StringGrid1->Cells[0][numberOfElements - 1] = FioAddEdit->Text;
	StringGrid1->Cells[1][numberOfElements - 1] = PassNumAddEdit->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SearchButtonClick(TObject *Sender)
{
    tree.Search(Memo1,StrToInt(SearchNumberEdit->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm3::PrButtonClick(TObject *Sender)
{
	tree.PrObh(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ObrButtonClick(TObject *Sender)
{
	tree.ObrObh(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::VozrButtonClick(TObject *Sender)
{
	tree.KeyObh(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DeleteButtonClick(TObject *Sender)
{
	int delEl = StrToInt(DeleteEdit->Text);
	int numToDel = 0;
	for (int i = 0; i < numberOfElements - numToDel; i++) {
		if (delEl == StrToInt(StringGrid1->Cells[1][i])){
			numToDel++;
		}
		StringGrid1->Cells[1][i] = StringGrid1->Cells[1][i + numToDel];
		StringGrid1->Cells[0][i] = StringGrid1->Cells[0][i + numToDel];
	}
	for (int i = numberOfElements - numToDel; i < numberOfElements; i++) {
		StringGrid1->Cells[0][i] = " ";
		StringGrid1->Cells[1][i] = " ";
	}
	numberOfElements -= numToDel;
	StringGrid1->RowCount = numberOfElements;
	NumberOfEls->Text = IntToStr(numberOfElements);
	tree.~Tree();
	for(int i = 0; i < numberOfElements; i++){
		tree.Insert(StringGrid1->Cells[0][i], StrToInt(StringGrid1->Cells[1][i]));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	TreeMid tm;
	tm.SetRoot(tree.GetRoot());
	tm.GetAverage(Memo1,numberOfElements);
}
//---------------------------------------------------------------------------

