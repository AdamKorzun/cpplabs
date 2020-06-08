//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Stack.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Stack* beginning = NULL ;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "a";
	StringGrid1->Cells[0][1] = "b";
	StringGrid1->Cells[0][2] = "c";
	StringGrid1->Cells[0][3] = "d";
	StringGrid1->Cells[0][4] = "e";
	Edit1->Text = "(a-b)/(c+d)*e";
	Edit2->Text = " ";
	Edit3->Text = "";
	StringGrid1->Cells[1][0] = "0,3";
	StringGrid1->Cells[1][1] = "6,7";
	StringGrid1->Cells[1][2] = "8,4";
	StringGrid1->Cells[1][3] = "9,5";
	StringGrid1->Cells[1][4] = "1,2";
}
//---------------------------------------------------------------------------
int Priority(char temp){
	switch(temp){
		case '^': return 4;
		case '*': return 3;
		case '/': return 3;
		case '+': return 2;
		case '-': return 2;
		case '(': return 1;

	}
	return 0;
}


void __fastcall TForm3::Button2Click(TObject *Sender)
{
	String inStr = Edit1->Text;
	String outStr = "";

	char tempChar;
	char tempCharStr;
	int len = inStr.Length();

	for (int i = 1; i <= len; i++) {

		tempChar = inStr[i];

		if (tempChar == '(') {
			beginning = beginning->Push(beginning, tempChar);
		}
		if (tempChar == ')') {
			while(beginning->GetInfo() != '('){
				beginning = beginning->Pop(beginning,&tempCharStr);
				outStr += tempCharStr;
			}
			beginning = beginning->Pop(beginning, &tempCharStr);
		}
		if (tempChar >= 'a' && tempChar <= 'e') {
			outStr += tempChar;
		}
		if (tempChar == '*' || tempChar == '/' || tempChar == '+' || tempChar == '-' || tempChar == '^') {
			while (beginning != NULL && Priority(beginning->GetInfo()) >= Priority(tempChar)){
				beginning = beginning->Pop(beginning, &tempCharStr);
				outStr += tempCharStr;
			}
			beginning = beginning->Push(beginning, tempChar);
		}

	}
	while(beginning != NULL){
		beginning = beginning->Pop(beginning, &tempChar);
		outStr+= tempChar;
	}

	Edit2->Text = outStr;
}
//---------------------------------------------------------------------------
float Calculate(String str, float arr[]){
	char tempChar;
	char temp1, temp2;
	float op1,op2,result = 0;
	char chr = 'z' + 1;
	for (int i = 1; i <= str.Length(); i++) {

		tempChar = str[i];
		if (!(tempChar == '*' || tempChar == '/' || tempChar == '+' || tempChar == '-' || tempChar == '^')) {
			beginning = beginning->Push(beginning, tempChar);
		}
		else {

			beginning = beginning->Pop(beginning, &temp1);
			beginning = beginning->Pop(beginning, &temp2);

			op1 = arr[temp1];
			op2 = arr[temp2];

			switch(tempChar){
				case '*': result = op2 * op1;break;
				case '/': result = op2 / op1;break;
				case '+': result = op2 + op1;break;
				case '-': result = op2 - op1;break;
				case '^': result = pow(op2,op1);break;
			}
			arr[chr] = result;
			beginning = beginning->Push(beginning,chr);
			chr++;

		}
	}
	return result;
}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	String outStr = Edit2->Text;
	float arr[201];
	for (int i = 0; i < 5; i++) {
		arr[StringGrid1->Cells[0][i][1]] = StrToFloat(StringGrid1->Cells[1][i]);
	}
	Edit3->Text = FloatToStr(Calculate(outStr, arr));
}
//---------------------------------------------------------------------------

