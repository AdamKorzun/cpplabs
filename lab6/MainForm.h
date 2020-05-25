//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TEdit *NumberOfEls;
	TMemo *Memo1;
	TTreeView *TreeView1;
	TButton *FillButton;
	TButton *PrintButton;
	TButton *BalanceButton;
	TEdit *FioAddEdit;
	TEdit *PassNumAddEdit;
	TButton *AddButton;
	TEdit *SearchNumberEdit;
	TButton *SearchButton;
	TButton *PrButton;
	TButton *ObrButton;
	TButton *VozrButton;
	TEdit *DeleteEdit;
	TButton *DeleteButton;
	TButton *Button1;
	void __fastcall NumberOfElsChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FillButtonClick(TObject *Sender);
	void __fastcall PrintButtonClick(TObject *Sender);
	void __fastcall BalanceButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall PrButtonClick(TObject *Sender);
	void __fastcall ObrButtonClick(TObject *Sender);
	void __fastcall VozrButtonClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
