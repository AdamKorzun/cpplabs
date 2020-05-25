object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 678
  ClientWidth = 1010
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
  object SaveButton: TButton
    Left = 808
    Top = 472
    Width = 161
    Height = 49
    Caption = 'Save'
    TabOrder = 0
    OnClick = SaveButtonClick
  end
  object ComboBox: TComboBox
    Left = 808
    Top = 29
    Width = 161
    Height = 21
    TabOrder = 1
    Text = 'All'
  end
  object MemoText: TMemo
    Left = 0
    Top = 0
    Width = 769
    Height = 681
    HideSelection = False
    TabOrder = 2
  end
  object ShowButton: TButton
    Left = 808
    Top = 64
    Width = 161
    Height = 49
    Caption = 'Show'
    TabOrder = 3
    OnClick = ShowButtonClick
  end
  object TopTen: TButton
    Left = 808
    Top = 136
    Width = 161
    Height = 49
    Caption = 'Sort by goals'
    TabOrder = 4
    OnClick = TopTenClick
  end
  object Button1: TButton
    Left = 808
    Top = 208
    Width = 161
    Height = 49
    Caption = 'Sort by penalties'
    TabOrder = 5
    OnClick = Button1Click
  end
end
