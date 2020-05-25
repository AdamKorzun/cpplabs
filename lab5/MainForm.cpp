//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Queue.h"
#include "DLList.h"
TForm3 *Form3;
Queue queue;
DLList list;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::NumberOfElsChange(TObject *Sender)
{
	try{
        queue.~Queue();
		Form3->StringGrid1->RowCount = StrToInt(Form3->NumberOfEls->Text);
		for (int i = 0; i < StrToInt(Form3->NumberOfEls->Text); i++) {
			StringGrid1->Cells[0][i] = i;

		}
	}
	catch(...){

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DeleteButtonClick(TObject *Sender)
{
    queue.~Queue();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FillButtonClick(TObject *Sender)
{
    queue.~Queue();
	int temp;
	for (int i = 0; i < StrToInt(Form3->NumberOfEls->Text); i++) {
		temp = StrToInt(StringGrid1->Cells[1][i]);
		queue.Add(temp);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DrawButtonClick(TObject *Sender)
{
	Form3->ListBox1->Clear();
	queue.Show(Form3->ListBox1);

}
//---------------------------------------------------------------------------
void __fastcall TForm3::AddButtonClick(TObject *Sender)
{
	try{

		Form3->NumberOfEls->Text = IntToStr(StrToInt(Form3->NumberOfEls->Text) + 1);
		StringGrid1->Cells[0][StrToInt(NumberOfEls->Text) - 1] = StrToInt(NumberOfEls->Text);
		StringGrid1->Cells[1][StrToInt(NumberOfEls->Text) - 1] = StrToInt(AddElementEdit->Text);
		Form3->ListBox1->Clear();
		queue.Show(Form3->ListBox1);
	}
	catch(...){
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::DeleteFirstButtonClick(TObject *Sender)
{
	try{
		queue.DelN();
	}
	catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SwapButtonClick(TObject *Sender)
{
    Form3->ListBox1->Clear();
	list.SetBase(queue.GetHead(),queue.GetTail());
	list.Swap();
	list.Show(Form3->ListBox1);
}
//---------------------------------------------------------------------------
