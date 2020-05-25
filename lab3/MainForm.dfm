object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 635
  ClientWidth = 1107
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = CreateForm
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 919
    Top = 356
    Width = 58
    Height = 13
    Caption = 'Destiantion:'
  end
  object Label2: TLabel
    Left = 919
    Top = 166
    Width = 28
    Height = 13
    Caption = 'Type:'
  end
  object Label3: TLabel
    Left = 917
    Top = 194
    Width = 58
    Height = 13
    Caption = 'Destination:'
  end
  object Label4: TLabel
    Left = 915
    Top = 228
    Width = 53
    Height = 13
    Caption = 'Departure:'
  end
  object ArrivalLabel: TLabel
    Left = 915
    Top = 260
    Width = 35
    Height = 13
    Caption = 'Arrival:'
  end
  object Label5: TLabel
    Left = 919
    Top = 139
    Width = 41
    Height = 13
    Caption = 'Number:'
    Color = clGray
    ParentColor = False
  end
  object Label6: TLabel
    Left = 919
    Top = 387
    Width = 26
    Height = 13
    Caption = 'Time:'
  end
  object Label7: TLabel
    Left = 919
    Top = 484
    Width = 58
    Height = 13
    Caption = 'Destiantion:'
  end
  object Label8: TLabel
    Left = 919
    Top = 578
    Width = 26
    Height = 13
    Caption = 'Time:'
  end
  object SaveButton: TButton
    Left = 936
    Top = 8
    Width = 153
    Height = 49
    Caption = 'Save'
    TabOrder = 0
    OnClick = SaveButtonClick
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 913
    Height = 641
    Color = clWhite
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object ShowButton: TButton
    Left = 936
    Top = 72
    Width = 153
    Height = 49
    Caption = 'Show'
    TabOrder = 2
    OnClick = ShowButtonClick
  end
  object DestinationMemo: TMemo
    Left = 983
    Top = 353
    Width = 118
    Height = 17
    Lines.Strings = (
      'DestinationMemo')
    TabOrder = 3
  end
  object BusCombo: TComboBox
    Left = 983
    Top = 136
    Width = 118
    Height = 21
    TabOrder = 4
    OnKeyPress = EnterPress
  end
  object TypeMemo: TMemo
    Left = 983
    Top = 163
    Width = 118
    Height = 22
    Lines.Strings = (
      'TypeMemo')
    TabOrder = 5
  end
  object DestMemo: TMemo
    Left = 981
    Top = 191
    Width = 118
    Height = 22
    Lines.Strings = (
      'DestinationMemo')
    TabOrder = 6
  end
  object DepartureComboHours: TComboBox
    Left = 981
    Top = 225
    Width = 55
    Height = 21
    TabOrder = 7
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23')
  end
  object DepartureComboMin: TComboBox
    Left = 1042
    Top = 225
    Width = 55
    Height = 21
    TabOrder = 8
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23'
      '24'
      '25'
      '26'
      '27'
      '28'
      '29'
      '30'
      '31'
      '32'
      '33'
      '34'
      '35'
      '36'
      '37'
      '38'
      '39'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49'
      '50'
      '51'
      '52'
      '53'
      '54'
      '55'
      '56'
      '57'
      '58'
      '59')
  end
  object ArrivalComboHours: TComboBox
    Left = 981
    Top = 257
    Width = 55
    Height = 21
    TabOrder = 9
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23')
  end
  object ArrivalComboMin: TComboBox
    Left = 1042
    Top = 257
    Width = 55
    Height = 21
    TabOrder = 10
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23'
      '24'
      '25'
      '26'
      '27'
      '28'
      '29'
      '30'
      '31'
      '32'
      '33'
      '34'
      '35'
      '36'
      '37'
      '38'
      '39'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49'
      '50'
      '51'
      '52'
      '53'
      '54'
      '55'
      '56'
      '57'
      '58'
      '59')
  end
  object Button1: TButton
    Left = 936
    Top = 296
    Width = 153
    Height = 51
    Caption = 'Destination and time'
    TabOrder = 11
    OnClick = Button1Click
  end
  object SortHours: TComboBox
    Left = 983
    Top = 384
    Width = 55
    Height = 21
    TabOrder = 12
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23')
  end
  object SortMins: TComboBox
    Left = 1044
    Top = 384
    Width = 55
    Height = 21
    TabOrder = 13
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23'
      '24'
      '25'
      '26'
      '27'
      '28'
      '29'
      '30'
      '31'
      '32'
      '33'
      '34'
      '35'
      '36'
      '37'
      '38'
      '39'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49'
      '50'
      '51'
      '52'
      '53'
      '54'
      '55'
      '56'
      '57'
      '58'
      '59')
  end
  object DestinationMemo2: TMemo
    Left = 983
    Top = 481
    Width = 118
    Height = 17
    Lines.Strings = (
      'DestinationMemo')
    TabOrder = 14
  end
  object DestPButton: TButton
    Left = 936
    Top = 429
    Width = 153
    Height = 46
    Caption = 'Destination'
    TabOrder = 15
    OnClick = DestPButtonClick
  end
  object Button2: TButton
    Left = 936
    Top = 520
    Width = 153
    Height = 49
    Caption = 'Show buses on road'
    TabOrder = 16
    OnClick = Button2Click
  end
  object ComboHours2: TComboBox
    Left = 983
    Top = 575
    Width = 55
    Height = 21
    TabOrder = 17
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23')
  end
  object ComboMins2: TComboBox
    Left = 1044
    Top = 575
    Width = 55
    Height = 21
    TabOrder = 18
    Text = '0'
    OnKeyPress = EnterPress
    Items.Strings = (
      '0'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23'
      '24'
      '25'
      '26'
      '27'
      '28'
      '29'
      '30'
      '31'
      '32'
      '33'
      '34'
      '35'
      '36'
      '37'
      '38'
      '39'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49'
      '50'
      '51'
      '52'
      '53'
      '54'
      '55'
      '56'
      '57'
      '58'
      '59')
  end
  object TimerControlButton: TButton
    Left = 1008
    Top = 602
    Width = 91
    Height = 25
    Caption = 'Start  / stop timer'
    TabOrder = 19
    OnClick = TimerControlButtonClick
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 920
    Top = 600
  end
end
