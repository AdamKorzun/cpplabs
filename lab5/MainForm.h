//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TStringGrid *StringGrid1;
	TEdit *NumberOfEls;
	TButton *DeleteButton;
	TButton *FillButton;
	TButton *DrawButton;
	TEdit *AddElementEdit;
	TButton *AddButton;
	TButton *DeleteFirstButton;
	TButton *SwapButton;
	void __fastcall NumberOfElsChange(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall FillButtonClick(TObject *Sender);
	void __fastcall DrawButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall DeleteFirstButtonClick(TObject *Sender);
	void __fastcall SwapButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
