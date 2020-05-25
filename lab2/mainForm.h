//---------------------------------------------------------------------------

#ifndef mainFormH
#define mainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *SaveButton;
	TComboBox *ComboBox;
	TMemo *MemoText;
	TButton *ShowButton;
	TButton *TopTen;
	TButton *Button1;
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall ShowButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TopTenClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);




private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
