object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 767
  ClientWidth = 1112
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 0
    Top = 0
    Width = 393
    Height = 769
    ItemHeight = 13
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 448
    Top = 56
    Width = 209
    Height = 505
    ColCount = 2
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
  end
  object NumberOfEls: TEdit
    Left = 448
    Top = 5
    Width = 129
    Height = 21
    TabOrder = 2
    Text = 'NumberOfEls'
    OnChange = NumberOfElsChange
  end
  object DeleteButton: TButton
    Left = 448
    Top = 576
    Width = 97
    Height = 49
    Caption = 'Delete queue'
    TabOrder = 3
    OnClick = DeleteButtonClick
  end
  object FillButton: TButton
    Left = 448
    Top = 640
    Width = 97
    Height = 49
    Caption = 'Fill queue'
    TabOrder = 4
    OnClick = FillButtonClick
  end
  object DrawButton: TButton
    Left = 560
    Top = 576
    Width = 97
    Height = 49
    Caption = 'Draw'
    TabOrder = 5
    OnClick = DrawButtonClick
  end
  object AddElementEdit: TEdit
    Left = 696
    Top = 56
    Width = 121
    Height = 21
    TabOrder = 6
    Text = 'AddElementEdit'
  end
  object AddButton: TButton
    Left = 696
    Top = 96
    Width = 121
    Height = 49
    Caption = 'Add'
    TabOrder = 7
    OnClick = AddButtonClick
  end
  object DeleteFirstButton: TButton
    Left = 560
    Top = 640
    Width = 97
    Height = 49
    Caption = 'Delete first'
    TabOrder = 8
    OnClick = DeleteFirstButtonClick
  end
  object SwapButton: TButton
    Left = 696
    Top = 240
    Width = 121
    Height = 49
    Caption = 'Swap min max'
    TabOrder = 9
    OnClick = SwapButtonClick
  end
end
