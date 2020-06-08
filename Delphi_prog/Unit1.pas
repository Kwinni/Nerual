unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Grids, StdCtrls, ExtCtrls, ComCtrls, jpeg;

type
  TForm1 = class(TForm)
    pgc1: TPageControl;
    lbl1: TLabel;
    lbl2: TLabel;
    lbl3: TLabel;
    img1: TImage;
    lbl4: TLabel;
    lbl5: TLabel;
    strngrd1: TStringGrid;
    btn1: TButton;
    btn2: TButton;
    strngrd2: TStringGrid;
    btn3: TButton;
    btn4: TButton;
    btn5: TButton;
    trckbr1: TTrackBar;
    btn6: TButton;
    ts1: TTabSheet;
    ts2: TTabSheet;
    lbl6: TLabel;
    strngrd3: TStringGrid;
    img2: TImage;
    strngrd4: TStringGrid;
    btn7: TButton;
    btn8: TButton;
    btn9: TButton;
    btn10: TButton;
    btn11: TButton;
    strngrd5: TStringGrid;
    ts3: TTabSheet;
    img3: TImage;
    btn12: TButton;
    strngrd6: TStringGrid;
    img4: TImage;
    img5: TImage;
    strngrd7: TStringGrid;
    strngrd8: TStringGrid;
    strngrd9: TStringGrid;
    strngrd10: TStringGrid;
    lbl7: TLabel;
    lbl8: TLabel;
    lbl9: TLabel;
    lbl10: TLabel;
    procedure strngrd1DrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure FormCreate(Sender: TObject);
    procedure btn1Click(Sender: TObject);
    procedure btn2Click(Sender: TObject);
    procedure btn3Click(Sender: TObject);
    procedure btn4Click(Sender: TObject);
    procedure strngrd1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure strngrd1SelectCell(Sender: TObject; ACol, ARow: Integer;
      var CanSelect: Boolean);
    procedure btn5Click(Sender: TObject);
    procedure trckbr1Change(Sender: TObject);
    procedure btn6Click(Sender: TObject);
    procedure strngrd1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure strngrd3DrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure strngrd3SelectCell(Sender: TObject; ACol, ARow: Integer;
      var CanSelect: Boolean);
    procedure strngrd3MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure btn8Click(Sender: TObject);
    procedure btn9Click(Sender: TObject);
    procedure btn11Click(Sender: TObject);
    procedure btn12Click(Sender: TObject);
    procedure strngrd6DrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure strngrd7DrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure strngrd10DrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  hopf, hops  : array [0..20] of TStringGrid;//Масив таблиць для розрахунків
  hopz : array [0..1] of TStringGrid;         //Масив таблиць для розрахунків
  q,rr,ss,rrr,sss : integer;//кількість таблиць образів

implementation

{$R *.dfm}

procedure TForm1.strngrd1DrawCell(Sender: TObject; ACol, ARow: Integer;
  Rect: TRect; State: TGridDrawState);
begin
   if (strngrd1.Cells [Acol, Arow] = '-1') then
   StrnGrd1.Canvas.Brush.Color := clWhite
   else
   if  (strngrd1.Cells [Acol, Arow] = '1') then
   strngrd1.Canvas.Brush.Color := clBlack;
   strngrd1.Canvas.FillRect(Rect);
end;

procedure TForm1.FormCreate(Sender: TObject);
var i,j : Integer;
begin
  q :=-1;
  for i :=0 to strngrd1.ColCount-1 do
    for j :=0 to strngrd1.RowCount-1 do
      strngrd1.Cells[i,j] :='-1';

  for i :=0 to strngrd2.ColCount-1 do
    for j :=0 to strngrd2.RowCount-1 do
      strngrd2.Cells[i,j] :='0';

  for i :=0 to strngrd3.ColCount-1 do
    for j :=0 to strngrd3.RowCount-1 do
      strngrd3.Cells[i,j] :='-1';

end;

procedure TForm1.btn1Click(Sender: TObject);
var i,j : Integer;
begin
  q :=-1;
  for i :=0 to strngrd1.ColCount-1 do
    for j :=0 to strngrd1.RowCount-1 do
      strngrd1.Cells[i,j] :='-1';

  btn2.Enabled :=True;
  for i :=0 to q do
  begin
    hopf[i].Destroy;
    hops[i].Destroy;
  end;
  hopz[0].Destroy;
  hopz[1].Destroy;
  lbl4.Visible :=False;
  lbl5.Visible :=False;
end;

procedure TForm1.btn2Click(Sender: TObject);
var i,j,k,ii,jj,iii,jjj : Integer;
begin
  inc(q); //Додаємо нову таблицю до загальної кількості
  //Створення таблиці для розміщення контрольного образу
  hopf[q]                 :=TStringGrid.Create(Form1);
  hopf[q].Parent          :=Form1;
  hopf[q].Top             :=80;
  if q=0 then hopf[q].Left  :=340 else hopf[q].Left :=(q+1)*340;
  hopf[q].Width           :=45;
  hopf[q].Height          :=233;
  hopf[q].ColCount        :=1;
  hopf[q].RowCount        :=strngrd1.RowCount*strngrd1.ColCount;
  hopf[q].FixedRows       :=1;
  hopf[q].FixedCols       :=0;
  hopf[q].FixedRows       :=0;
  hopf[q].DefaultColWidth :=46;
  hopf[q].Visible         :=False;
  TStringGrid(hopf[q]).ScrollBars:=ssNone;
  //Вставлення в таблицю значень контрольного образу
  k :=-1;
  for i :=0 to strngrd1.RowCount-1 do
    for j :=0 to strngrd1.ColCount-1 do
    begin
      inc(k);
      hopf[q].Cells[0,k] :=strngrd1.Cells[j,i];
    end;

  hops[q]                 :=TStringGrid.Create(Form1);
  hops[q].Parent          :=Form1;
  hops[q].Top             :=340;
  if q=0 then hops[q].Left  :=340 else hops[q].Left :=(q+1)*340;
  hops[q].Width           :=241;
  hops[q].Height          :=233;
  hops[q].ColCount        :=strngrd1.RowCount*strngrd1.ColCount;//=45*45 Квадратна матриця
  hops[q].RowCount        :=strngrd1.RowCount*strngrd1.ColCount;//=45*45 Квадратна матриця
  hops[q].FixedRows       :=1;
  hops[q].FixedCols       :=0;
  hops[q].FixedRows       :=0;
  hops[q].DefaultColWidth :=46;
  hops[q].Visible         :=False;
  TStringGrid(hops[q]).ScrollBars:=ssNone;

  //Розрахунок матриці стовбецХрядок=45*45
  iii :=-1;
  for i :=0 to hopf[q].ColCount-1 do
    for j :=0 to hopf[q].RowCount-1 do
    begin
      inc(iii);
      jjj :=-1;
      for ii:=0 to hopf[q].ColCount-1 do
        for jj :=0 to hopf[q].RowCount-1 do
        begin
          inc(jjj);
          hops[q].Cells[jjj,iii] :=IntToStr(StrToInt(hopf[q].Cells[i,j])*StrToInt(hopf[q].Cells[ii,jj]));
        end;
    end;


  //Отримання результуючої матриці
  for i :=0 to strngrd1.RowCount*strngrd1.ColCount do
    for j :=0 to strngrd1.RowCount*strngrd1.ColCount do
      strngrd2.Cells[i,j] :='0';

  //Додавання матриць
  k :=-1;
  repeat
    inc(k);
    for i :=0 to strngrd1.RowCount*strngrd1.ColCount-1 do
      for j :=0 to strngrd1.RowCount*strngrd1.ColCount-1 do
        strngrd2.Cells[i,j] :=IntToStr(StrToInt(strngrd2.Cells[i,j])+StrToInt(hops[k].Cells[i,j]));
  until(k=q);

  //Обнулення діагоналі
  for i :=0 to strngrd1.RowCount*strngrd1.ColCount-1 do
    for j :=0 to strngrd1.RowCount*strngrd1.ColCount-1 do
      if i=j then strngrd2.Cells[i,j] :='0';

   ShowMessage('   Записано');
   lbl4.Visible :=True;
   lbl5.Visible :=True;
   lbl5.Caption :=IntToStr(q+1);
   
end;

procedure TForm1.btn3Click(Sender: TObject);
var i,j,k : Integer;
begin
  hopz[0]                 :=TStringGrid.Create(Form1);
  hopz[0].Parent          :=Form1;
  hopz[0].Top             :=80;
  hopz[0].Left            :=540;
  hopz[0].Width           :=45;
  hopz[0].Height          :=233;
  hopz[0].ColCount        :=1;
  hopz[0].RowCount        :=strngrd1.RowCount*strngrd1.ColCount;
  hopz[0].FixedRows       :=1;
  hopz[0].FixedCols       :=0;
  hopz[0].FixedRows       :=0;
  hopz[0].DefaultColWidth :=46;
  hopz[0].Visible         :=False;
//  TStringGrid(hopz[0]).ScrollBars:=ssNone;
  //копія для обчислень
  hopz[1]                 :=TStringGrid.Create(Form1);
  hopz[1].Parent          :=Form1;
  hopz[1].Top             :=80;
  hopz[1].Left            :=640;
  hopz[1].Width           :=45;
  hopz[1].Height          :=233;
  hopz[1].ColCount        :=1;
  hopz[1].RowCount        :=strngrd1.RowCount*strngrd1.ColCount;
  hopz[1].FixedRows       :=1;
  hopz[1].FixedCols       :=0;
  hopz[1].FixedRows       :=0;
  hopz[1].DefaultColWidth :=46;
  hopz[1].Visible         :=False;
  TStringGrid(hopz[1]).ScrollBars:=ssNone;

  //Вставлення в таблицю значень зіпсованого образу
  k :=-1;
  for i :=0 to strngrd1.RowCount-1 do
    for j :=0 to strngrd1.ColCount-1 do
    begin
      inc(k);
      hopz[0].Cells[0,k] :=strngrd1.Cells[j,i];
    end;
end;

procedure TForm1.btn4Click(Sender: TObject);
var i,j,k,m,s : Integer;
begin
  for s :=1 to 5 do
  begin
    //Множення матриці на зіпсований  вектор
    for j :=0 to strngrd2.RowCount-1 do
    begin
      m :=0;k :=0;
      for i :=0 to strngrd2.ColCount-1 do
      begin
        k :=StrToInt(strngrd2.Cells[i,j])*StrToint(hopz[0].Cells[0,i]);
        m :=m+k;
      end;
//      if j=199 then ShowMessage('111');
      hopz[1].Cells[0,j] :=IntToStr(m); //Запис в копію результату
    end;

    //Пропускання копії через функцію порогу і запис
    for j :=0 to hopz[0].RowCount-1 do
    begin
      if j=200 then
      begin
//        ShowMessage(hopz[0].Cells[0,j]);
//        ShowMessage(hopz[1].Cells[0,j]);
      end;
      if StrToInt(hopz[1].Cells[0,j])>=0 then hopz[0].Cells[0,j] :='1' else hopz[0].Cells[0,j] :='-1';
    end;
   btn1.Enabled :=False;
   btn2.Enabled :=False;
   btn5.Enabled :=False;
   btn3.Enabled :=False;
  end;

  //Відображення розпізнаного образу
  k :=-1;
  for i :=0 to strngrd1.RowCount-1 do
  begin
    for j :=0 to strngrd1.ColCount-1 do
    begin
      inc(k);
      strngrd1.Cells[j,i] :=hopz[0].Cells[0,k];
    end;
  end;

end;


procedure TForm1.strngrd1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if button =mbLeft then strngrd1.Cells[rr,ss] :='1';
  if button =mbRight then strngrd1.Cells[rr,ss] :='-1';
end;

procedure TForm1.strngrd1SelectCell(Sender: TObject; ACol, ARow: Integer;
  var CanSelect: Boolean);
begin
      rr :=ACol;ss :=ARow;
end;

procedure TForm1.btn5Click(Sender: TObject);
begin
  btn1.Enabled :=True;
  btn2.Enabled :=False;
  btn3.Enabled :=True;
  btn4.Enabled :=True;
  btn5.Enabled :=False;
end;

procedure TForm1.trckbr1Change(Sender: TObject);
begin
  if trckbr1.Position=0 then
  begin
    strngrd1.ColCount :=3;
    strngrd1.RowCount :=3;
    strngrd1.DefaultColWidth :=77;
    strngrd1.DefaultRowHeight :=75;
    strngrd2.RowCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.ColCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.DefaultColWidth :=77;
    strngrd2.DefaultRowHeight :=75;
  end else
  if trckbr1.Position=1 then
  begin
    strngrd1.ColCount :=5;
    strngrd1.RowCount :=9;
    strngrd1.DefaultColWidth :=46;
    strngrd1.DefaultRowHeight :=24;
    strngrd2.RowCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.ColCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.DefaultColWidth :=46;
    strngrd2.DefaultRowHeight :=24;
  end else
  if trckbr1.Position=2 then
  begin
    strngrd1.ColCount :=10;
    strngrd1.RowCount :=10;
    strngrd1.DefaultColWidth :=22;
    strngrd1.DefaultRowHeight :=22;
    strngrd2.RowCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.ColCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.DefaultColWidth :=22;
    strngrd2.DefaultRowHeight :=22;
  end else
  if trckbr1.Position=3 then
  begin
    strngrd1.ColCount :=20;
    strngrd1.RowCount :=20;
    strngrd1.DefaultColWidth :=10;
    strngrd1.DefaultRowHeight :=10;
    strngrd2.RowCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.ColCount :=strngrd1.ColCount*strngrd1.RowCount;
    strngrd2.DefaultColWidth :=10;
    strngrd2.DefaultRowHeight :=10;
  end;
  btn6.Enabled :=True;
end;

procedure TForm1.btn6Click(Sender: TObject);
var i,j : Integer;
begin
  trckbr1.Enabled :=False;
  q :=-1;
  for i :=0 to strngrd1.ColCount-1 do
    for j :=0 to strngrd1.RowCount-1 do
      strngrd1.Cells[i,j] :='-1';
  btn2.Enabled :=True;
  btn5.Enabled :=True;
  btn6.Enabled :=False;
  strngrd1.Enabled :=True;
end;

procedure TForm1.strngrd1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if button =mbLeft then strngrd1.Cells[rr,ss] :='1';
  if button =mbRight then strngrd1.Cells[rr,ss] :='-1';
end;

procedure TForm1.strngrd3DrawCell(Sender: TObject; ACol, ARow: Integer;
  Rect: TRect; State: TGridDrawState);
begin
   if (strngrd3.Cells [Acol, Arow] = '-1') then
   StrnGrd3.Canvas.Brush.Color := clWhite
   else
   if  (strngrd3.Cells [Acol, Arow] = '1') then
   strngrd3.Canvas.Brush.Color := clBlack;
   strngrd3.Canvas.FillRect(Rect);
end;

procedure TForm1.strngrd3SelectCell(Sender: TObject; ACol, ARow: Integer;
  var CanSelect: Boolean);
begin
  rrr :=ACol;sss :=ARow;
end;

procedure TForm1.strngrd3MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  if button =mbLeft then strngrd3.Cells[rrr,sss] :='1';
  if button =mbRight then strngrd3.Cells[rrr,sss] :='-1';
end;

procedure TForm1.btn8Click(Sender: TObject);
var i,j,k : Integer;
begin
  strngrd4.ColCount :=strngrd3.ColCount*strngrd3.RowCount;
  k :=-1;
  for i :=0 to strngrd3.ColCount-1 do
    for j :=0 to strngrd3.RowCount-1 do
    begin
      inc(k);
      strngrd4.Cells[k,strngrd4.RowCount-1] :=strngrd3.Cells[j,i];
    end;
   strngrd4.RowCount :=strngrd4.RowCount+1;
   btn9.Enabled :=True;
end;

procedure TForm1.btn9Click(Sender: TObject);
begin
   strngrd4.RowCount :=strngrd4.RowCount-1;
   btn8.Enabled  :=False;
   btn9.Enabled  :=False;
   btn10.Enabled :=True;
   btn11.Enabled :=True;
   //Ділення кожного елементу матриці strngrd4 на 2



end;

procedure TForm1.btn11Click(Sender: TObject);
var i,j : Integer;
      r : Real;
begin
  //Кількість рядків і колонок залежить від кількості нейронів мережі
  strngrd5.ColCount :=3;//Кількість нейронів першого шару
  strngrd5.RowCount :=3;//Кількість нейронів другого шару
  r :=1/strngrd4.RowCount;
  for i :=0 to strngrd5.ColCount-1 do
    for j:=0 to strngrd5.RowCount-1 do
      if i=j then strngrd5.Cells[i,j] :='1' else strngrd5.Cells[i,j] :=FloatToStr(-r);

      
end;

procedure TForm1.btn12Click(Sender: TObject);
var i,j,k,ii,jj : Integer;
    c           : Cardinal;
begin
  for i :=0 to strngrd6.ColCount-1 do
    for j :=0 to strngrd6.RowCount-1 do
      strngrd6.Cells[i,j] :='-1';
  for i :=0 to strngrd7.ColCount-1 do
    for j :=0 to strngrd7.RowCount-1 do
      strngrd7.Cells[i,j] :='-1';

  img3.Picture.LoadFromFile('cat.bmp');
  left:=5;
  top:=5;
  i :=0; k:=1; ii :=-1;
  repeat
    i :=i+left;
    ii :=ii+1;//розмір кроку по-горизонталі
    j :=0;
    jj :=-1;
    repeat
      j :=j+top;
      c:=Img3.Picture.Bitmap.Canvas.Pixels[i,j];
      jj :=jj+1;//розмір кроку по вертикалі
      if c>5000000 then strngrd6.Cells[ii,jj] :='-1'
                   else strngrd6.Cells[ii,jj] :='1';
    until(j>img3.Width);
  until(i>img3.Height);

  img4.Picture.LoadFromFile('mw.bmp');
  i :=0; k:=1; ii :=-1;
  repeat
    i :=i+left;
    ii :=ii+1;//розмір кроку по-горизонталі
    j :=0;
    jj :=-1;
    repeat
      j :=j+top;
      c:=Img4.Picture.Bitmap.Canvas.Pixels[i,j];
      jj :=jj+1;//розмір кроку по вертикалі
      if c>5000000 then
      begin
        strngrd7.Cells[ii,jj] :='-1';
      end
      else
      begin
        strngrd7.Cells[ii,jj] :='1';
      end;
    until(j>img4.Width);
  until(i>img4.Height);

  //Розміщення оцифрованих значень двох образів у двох стовпчихах матриці strngrd6
  //Кількість клітинок в обох матрицях однакова
  ii :=-1;jj :=0;
  for i :=0 to strngrd6.ColCount-1 do
    for j :=0 to strngrd6.RowCount-1 do
    begin
      inc(ii);
      strngrd8.Cells[jj,ii] :=strngrd6.Cells[j,i];
    end;
  ii :=-1;jj :=1;
  for i :=0 to strngrd7.ColCount-1 do
    for j :=0 to strngrd7.RowCount-1 do
    begin
      inc(ii);
      strngrd8.Cells[jj,ii] :=strngrd7.Cells[j,i];
    end;
  //Порожні клітинки матриці заповнюютьс значенням '-1'
  strngrd8.RowCount :=ii;
  for i :=0 to strngrd8.ColCount-1 do
    for j :=0 to strngrd8.RowCount-1 do
      if strngrd8.Cells[i,j]='' then strngrd8.Cells[i,j] :='-1';

  //Додавання матриць
  strngrd9.ColCount :=strngrd8.RowCount;
  strngrd9.RowCount :=strngrd8.RowCount;
  //Завантаження першої матриці
  for i :=0 to strngrd8.RowCount-1 do
    for j :=0 to strngrd8.RowCount-1 do
      strngrd9.Cells[i,j] :=strngrd8.Cells[0,j];
  //Додавання другої матриці до першої
  for i :=0 to strngrd8.RowCount-1 do
    for j :=0 to strngrd8.RowCount-1 do
      strngrd9.Cells[i,j] :=IntToStr(StrToInt(strngrd9.Cells[i,j])+StrToInt(strngrd8.Cells[0,j]));
  //Занулення діагоналі результуючої матриці
  for i :=0 to strngrd9.ColCount-1 do
    for j :=0 to strngrd9.RowCount-1 do
      if i=j then strngrd9.Cells[i,j] :='0';

  //Сканування матриці зіпсованого зразка
  img5.Picture.LoadFromFile('mwww.bmp');
  i :=0; k:=1; ii :=-1;
  repeat
    i :=i+left;
    ii :=ii+1;//розмір кроку по-горизонталі
    j :=0;
    jj :=-1;
    repeat
      j :=j+top;
      c:=Img5.Picture.Bitmap.Canvas.Pixels[i,j];
      jj :=jj+1;//розмір кроку по вертикалі
      if c>5000000 then
      begin
        strngrd10.Cells[ii,jj] :='-1';
      end
      else
      begin
        strngrd10.Cells[ii,jj] :='1';
      end;
    until(j>img5.Width);
  until(i>img5.Height);

  //Вектор зіпсованого зразка(третій стовпчик матриці strngnd8)
  ii :=-1;jj :=2;
  for i :=0 to strngrd10.ColCount-1 do
    for j :=0 to strngrd10.RowCount-1 do
    begin
      inc(ii);
      strngrd8.Cells[jj,ii] :=strngrd10.Cells[j,i];
    end;
  //Порожні клітинки матриці заповнюютьс значенням '-1'
  for i :=0 to strngrd8.ColCount-1 do
    for j :=0 to strngrd8.RowCount-1 do
      if strngrd8.Cells[i,j]='' then strngrd8.Cells[i,j] :='-1';

  //цикл 5 разів
  for ii :=1 to 2 do
  begin
    //Обнулення четвертого стовпчика
      for i :=0 to strngrd8.RowCount-1 do
        strngrd8.Cells[3,i] :='0';
    //Множення матриці на вектор зіпсованого зразка (четвертий стовпчик strngnd8)
    for i :=0 to strngrd9.ColCount-1 do
      for j :=0 to strngrd9.RowCount-1 do
        strngrd8.Cells[3,j] := IntToStr(StrToInt(strngrd8.Cells[3,j])+StrToInt(strngrd9.Cells[i,j])*StrToInt(strngrd8.Cells[2,j]));

    //Пропуск через фільтр
    for j :=0 to strngrd8.RowCount-1 do
      if StrToInt(strngrd8.Cells[3,j])>=0 then strngrd8.Cells[4,j] :='1' else strngrd8.Cells[4,j] :='-1';
    //Перезапис у третій стовпчик
    for i :=0 to strngrd8.RowCount-1 do
      strngrd8.Cells[2,i] :=strngrd8.Cells[4,i];
  end;
  //Підрахунок % неспівпадінь
  jj :=0;ii :=0;
  for i :=0 to strngrd8.RowCount-1 do
  begin
    if strngrd8.Cells[0,i]=strngrd8.Cells[2,i] then inc(jj);
    if strngrd8.Cells[1,i]=strngrd8.Cells[2,i] then inc(ii);
  end;
  if ii<=jj then
  begin
    lbl7.Visible :=True;
    lbl8.Visible :=False;
    lbl9.Caption :='Відсоток співпадіння   '+FloatToStr((jj/strngrd8.RowCount)*100)+'%'
  end else
  begin
    lbl7.Visible :=False;
    lbl8.Visible :=True;
    lbl9.Caption :='Відсоток співпадіння   '+FloatToStr((ii/strngrd8.RowCount)*100)+'%'
  end;
  lbl9.Visible :=True;

end;

procedure TForm1.strngrd6DrawCell(Sender: TObject; ACol, ARow: Integer;
  Rect: TRect; State: TGridDrawState);
begin
   if (strngrd6.Cells [Acol, Arow] = '-1') then StrnGrd6.Canvas.Brush.Color := clWhite else
   if  (strngrd6.Cells [Acol, Arow] = '1') then strngrd6.Canvas.Brush.Color := clBlack;
   strngrd6.Canvas.FillRect(Rect);
end;

procedure TForm1.strngrd7DrawCell(Sender: TObject; ACol, ARow: Integer;
  Rect: TRect; State: TGridDrawState);
begin
   if (strngrd7.Cells [Acol, Arow] = '-1') then StrnGrd7.Canvas.Brush.Color := clWhite else
   if  (strngrd7.Cells [Acol, Arow] = '1') then strngrd7.Canvas.Brush.Color := clBlack;
   strngrd7.Canvas.FillRect(Rect);
end;

procedure TForm1.strngrd10DrawCell(Sender: TObject; ACol, ARow: Integer;
  Rect: TRect; State: TGridDrawState);
begin
   if (strngrd10.Cells [Acol, Arow] = '-1') then StrnGrd10.Canvas.Brush.Color := clWhite else
   if  (strngrd10.Cells [Acol, Arow] = '1') then strngrd10.Canvas.Brush.Color := clBlack;
   strngrd10.Canvas.FillRect(Rect);
end;

end.
