object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 667
  ClientWidth = 1021
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 626
    Top = 35
    Width = 96
    Height = 13
    Caption = 'Number of elements'
  end
  object Label2: TLabel
    Left = 626
    Top = 115
    Width = 47
    Height = 13
    Caption = 'Table size'
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 281
    Height = 417
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Memo2: TMemo
    Left = 336
    Top = 0
    Width = 281
    Height = 417
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 728
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 728
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit2'
  end
  object Memo3: TMemo
    Left = 0
    Top = 448
    Width = 617
    Height = 225
    Lines.Strings = (
      'Memo3')
    TabOrder = 4
  end
  object Button1: TButton
    Left = 728
    Top = 168
    Width = 121
    Height = 41
    Caption = 'Fill randomly'
    TabOrder = 5
    OnClick = Button1Click
  end
  object DeleteButton: TButton
    Left = 728
    Top = 224
    Width = 121
    Height = 41
    Caption = 'Delete'
    TabOrder = 6
    OnClick = DeleteButtonClick
  end
  object Button2: TButton
    Left = 728
    Top = 280
    Width = 121
    Height = 41
    Caption = 'Average'
    TabOrder = 7
    OnClick = Button2Click
  end
end
