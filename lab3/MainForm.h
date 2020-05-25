//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *SaveButton;
	TButton *ShowButton;
	TMemo *DestinationMemo;
	TMemo *Memo1;
	TComboBox *BusCombo;
	TMemo *TypeMemo;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TMemo *DestMemo;
	TLabel *Label4;
	TComboBox *DepartureComboHours;
	TComboBox *DepartureComboMin;
	TLabel *ArrivalLabel;
	TComboBox *ArrivalComboHours;
	TComboBox *ArrivalComboMin;
	TLabel *Label5;
	TButton *Button1;
	TLabel *Label6;
	TComboBox *SortHours;
	TComboBox *SortMins;
	TMemo *DestinationMemo2;
	TLabel *Label7;
	TButton *DestPButton;
	TButton *Button2;
	TLabel *Label8;
	TComboBox *ComboHours2;
	TComboBox *ComboMins2;
	TTimer *Timer1;
	TButton *TimerControlButton;
	void __fastcall EnterPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall ShowButtonClick(TObject *Sender);
	void __fastcall CreateForm(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

	void __fastcall DestPButtonClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall TimerControlButtonClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
