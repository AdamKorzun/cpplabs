object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 720
  ClientWidth = 1116
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 0
    Top = 40
    Width = 137
    Height = 553
    ColCount = 2
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object NumberOfEls: TEdit
    Left = 0
    Top = 8
    Width = 137
    Height = 21
    TabOrder = 1
    Text = 'NumberOfEls'
    OnChange = NumberOfElsChange
  end
  object Memo1: TMemo
    Left = 440
    Top = 40
    Width = 185
    Height = 553
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object TreeView1: TTreeView
    Left = 168
    Top = 40
    Width = 234
    Height = 553
    Indent = 19
    TabOrder = 3
  end
  object FillButton: TButton
    Left = 0
    Top = 607
    Width = 137
    Height = 42
    Caption = 'Fill'
    TabOrder = 4
    OnClick = FillButtonClick
  end
  object PrintButton: TButton
    Left = 168
    Top = 607
    Width = 113
    Height = 42
    Caption = 'Print'
    TabOrder = 5
    OnClick = PrintButtonClick
  end
  object BalanceButton: TButton
    Left = 296
    Top = 607
    Width = 106
    Height = 42
    Caption = 'Balance'
    TabOrder = 6
    OnClick = BalanceButtonClick
  end
  object FioAddEdit: TEdit
    Left = 704
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 7
    Text = 'FioAddEdit'
  end
  object PassNumAddEdit: TEdit
    Left = 704
    Top = 77
    Width = 121
    Height = 21
    TabOrder = 8
    Text = 'Edit1'
  end
  object AddButton: TButton
    Left = 704
    Top = 104
    Width = 121
    Height = 49
    Caption = 'Add'
    TabOrder = 9
    OnClick = AddButtonClick
  end
  object SearchNumberEdit: TEdit
    Left = 704
    Top = 237
    Width = 121
    Height = 21
    TabOrder = 10
    Text = 'Edit1'
  end
  object SearchButton: TButton
    Left = 704
    Top = 272
    Width = 121
    Height = 49
    Caption = 'Search'
    TabOrder = 11
    OnClick = SearchButtonClick
  end
  object PrButton: TButton
    Left = 704
    Top = 368
    Width = 121
    Height = 49
    Caption = #1055#1088#1103#1084#1086#1081
    TabOrder = 12
    OnClick = PrButtonClick
  end
  object ObrButton: TButton
    Left = 704
    Top = 432
    Width = 121
    Height = 49
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081
    TabOrder = 13
    OnClick = ObrButtonClick
  end
  object VozrButton: TButton
    Left = 704
    Top = 496
    Width = 121
    Height = 49
    Caption = #1042#1086#1079#1088'. '#1082#1083#1102#1095#1072
    TabOrder = 14
    OnClick = VozrButtonClick
  end
  object DeleteEdit: TEdit
    Left = 440
    Top = 607
    Width = 185
    Height = 21
    TabOrder = 15
    Text = 'DeleteEdit'
  end
  object DeleteButton: TButton
    Left = 440
    Top = 624
    Width = 185
    Height = 25
    Caption = 'Delete'
    TabOrder = 16
    OnClick = DeleteButtonClick
  end
  object Button1: TButton
    Left = 936
    Top = 104
    Width = 105
    Height = 49
    Caption = 'Average'
    TabOrder = 17
    OnClick = Button1Click
  end
end
