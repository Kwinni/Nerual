//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <math>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int count = 0; //Кількість рядків StringGrid5
int AACol, AARow;//Глобальні змінні
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PageControl1Change(TObject *Sender)
{

//Витирання сітки в матриці мережі Гопфілда
if (PageControl1->ActivePageIndex == 3)
   {
    StringGrid3->RowCount = 0;
    StringGrid3->ColCount = 0;
   }
//Кінець витирання сітки в матриці мережі Гопфілда

//Малювання ліній
Image1->Canvas->Pen->Width = 3; //товщина
Image1->Canvas->MoveTo(440,200);//початок відмальовування
Image1->Canvas->LineTo(670,200);//кінець відмальовування

Image1->Canvas->MoveTo(100,100);//початок відмальовування
Image1->Canvas->LineTo(400,200);//кінець відмальовування

Image1->Canvas->MoveTo(100,200);//початок відмальовування
Image1->Canvas->LineTo(300,200);//кінець відмальовування

Image1->Canvas->MoveTo(367,40);//початок відмальовування
Image1->Canvas->LineTo(367,200);//кінець відмальовування

Image1->Canvas->MoveTo(100,300);//початок відмальовування
Image1->Canvas->LineTo(400,200);//кінець відмальовування
//Кінець малювання ліній

//Малювання кола
   int radius = 70;
   int posX = 370;
   int posY= 200;
   Image1->Canvas->Pen->Width = 3;
   Image1->Canvas->Ellipse(TRect(posX-radius, posY-radius, posX+radius, posY+radius));
   ReleaseDC(Handle, Canvas->Handle);
//Кінець малювання кола



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 if (Button1->Caption == "Стоп")
 {
    Timer1->Enabled = false;
    Timer2->Enabled = false;
    Button1->Caption = "Старт";
 } else
 {
    Timer1->Enabled = true;
    Timer2->Enabled = false;
    Button1->Caption = "Стоп";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Малювання ліній
Image1->Canvas->Pen->Width = 3; //товщина
Image1->Canvas->MoveTo(440,200);//початок відмальовування
Image1->Canvas->LineTo(670,200);//кінець відмальовування

Image1->Canvas->MoveTo(100,100);//початок відмальовування
Image1->Canvas->LineTo(400,200);//кінець відмальовування

Image1->Canvas->MoveTo(100,200);//початок відмальовування
Image1->Canvas->LineTo(300,200);//кінець відмальовування

Image1->Canvas->MoveTo(367,40);//початок відмальовування
Image1->Canvas->LineTo(367,200);//кінець відмальовування

Image1->Canvas->MoveTo(100,300);//початок відмальовування
Image1->Canvas->LineTo(400,200);//кінець відмальовування
//Кінець малювання ліній

//Малювання кола
   int radius = 70;
   int posX = 370;
   int posY= 200;
   Image1->Canvas->Pen->Width = 3;
   Image1->Canvas->Ellipse(TRect(posX-radius, posY-radius, posX+radius, posY+radius));
   ReleaseDC(Handle, Canvas->Handle);
//Кінець малювання кола

//Введення даних для прогнозування

  StringGrid1->Cells[0][0] = "     Номер";
  StringGrid2->Cells[0][0] = "   №";

  for (int i = 1; i < 13; i++) {
  StringGrid1->Cells[0][i] = "        "+IntToStr(i);
  }

  for (int i = 1; i < 13; i++) {
  StringGrid2->Cells[0][i] = "   "+IntToStr(i);
  }

 //Заповнення таблиці 1
  StringGrid1->Cells[1][0] = "       x1";
  StringGrid1->Cells[2][0] = "       x2";
  StringGrid1->Cells[3][0] = "       x3";

  StringGrid1->Cells[1][1] = "1,59";
  StringGrid1->Cells[2][1] = "5,78";
  StringGrid1->Cells[3][1] = "0,48";

  StringGrid1->Cells[1][2] = "5,78";
  StringGrid1->Cells[2][2] = "0,48";
  StringGrid1->Cells[3][2] = "5,28";

  StringGrid1->Cells[1][3] = "0,48";
  StringGrid1->Cells[2][3] = "5,28";
  StringGrid1->Cells[3][3] = "1,35";

  StringGrid1->Cells[1][4] = "5,28";
  StringGrid1->Cells[2][4] = "1,35";
  StringGrid1->Cells[3][4] = "5,91";

  StringGrid1->Cells[1][5] = "1,35";
  StringGrid1->Cells[2][5] = "5,91";
  StringGrid1->Cells[3][5] = "0,77";

  StringGrid1->Cells[1][6] = "5,91";
  StringGrid1->Cells[2][6] = "0,77";
  StringGrid1->Cells[3][6] = "5,25";

  StringGrid1->Cells[1][7] = "0,77";
  StringGrid1->Cells[2][7] = "5,25";
  StringGrid1->Cells[3][7] = "1,37";

  StringGrid1->Cells[1][8] = "5,25";
  StringGrid1->Cells[2][8] = "1,37";
  StringGrid1->Cells[3][8] = "4,42";

  StringGrid1->Cells[1][9] = "1,37";
  StringGrid1->Cells[2][9] = "4,42";
  StringGrid1->Cells[3][9] = "0,26";

  StringGrid1->Cells[1][10] = "4,42";
  StringGrid1->Cells[2][10] = "0,26";
  StringGrid1->Cells[3][10] = "4,21";

  StringGrid1->Cells[1][11] = "0,26";
  StringGrid1->Cells[2][11] = "4,21";
  StringGrid1->Cells[3][11] = "1,9";

  StringGrid1->Cells[1][12] = "4,21";
  StringGrid1->Cells[2][12] = "1,9";
  StringGrid1->Cells[3][12] = "4,08";

//Заповнення таблиці 2

  StringGrid2->Cells[1][0] = "  W1";
  StringGrid2->Cells[2][0] = "  W2";
  StringGrid2->Cells[3][0] = "  W3";
  StringGrid2->Cells[4][0] = "  x1";
  StringGrid2->Cells[5][0] = "  x2";
  StringGrid2->Cells[6][0] = "  x3";
  StringGrid2->Cells[7][0] = "   S";

//Перенесення даних х1,х2,х3 до таблиці 2 (StringGrid2)

     for (int i = 1; i < 13; i++) {
        for (int j=1; j<4; j++)
        {
          StringGrid2->Cells[j][i] = "0";
        }
                                   }

  for (int i = 1; i < 13; i++) {
  StringGrid2->Cells[4][i] = StringGrid1->Cells[1][i];
  StringGrid2->Cells[5][i] = StringGrid1->Cells[2][i];
  StringGrid2->Cells[6][i] = StringGrid1->Cells[3][i];

  }

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
 }
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   if (Button3->Caption == "Таблиця")
   {
     Chart1->Visible = false;Chart2->Visible = false;StringGrid2->Visible = true;
     Button3->Caption = "Графік тренованих значень";
     Chart1->SeriesList->Series[0]->AddXY(-1,-15,"",clBtnFace);
     for (int i = 1; i < 12; i++) {
       Chart1->SeriesList->Series[0]->AddXY(StrToInt(StringGrid1->Cells[0][i]),StrToFloat(StringGrid2->Cells[9][i]),"",clRed);
     }
     Chart1->SeriesList->Series[0]->AddXY(13,30,"",clBtnFace);
   } else
   if (Button3->Caption == "Графік тренованих значень")
   {
     Chart1->Visible = true;Chart2->Visible = false;StringGrid2->Visible = false;
     Button3->Caption = "Таблиця";
   }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
  float dw1,dw2,dw3,ddw;
//Тут починається тіло циклу для розрахунку ваг
 for (int ii=1; ii<3; ii++) {
   if (ii>1) {//ShowMessage(IntToStr(ii));
     for (int i = 1; i < 13; i++) {
        for (int j=1; j<4; j++)
        {
           if (j == 1) {ddw = dw1;}
           if (j == 2) {ddw = dw2;}
           if (j == 3) {ddw = dw3;}
           StringGrid2->Cells[j][i] = FloatToStr(StrToFloat(StringGrid2->Cells[j][i])+ddw);
        }
     }
   }

//Розрахунок S StringGrid2
  for (int i = 1; i < 13; i++) {
    StringGrid2->Cells[7][i] = FloatToStr(StrToFloat(StringGrid2->Cells[1][i])*StrToFloat(StringGrid2->Cells[4][i])+
    StrToFloat(StringGrid2->Cells[2][i])*StrToFloat(StringGrid2->Cells[5][i])+
    StrToFloat(StringGrid2->Cells[3][i])*StrToFloat(StringGrid2->Cells[6][i]));
  }
//Кінець розрахунку S
//Розрахунок Yi
  StringGrid2->Cells[8][0] = "   Yi";
  double t;
  for (int i = 1; i < 13; i++) {
    t = StrToFloat(StringGrid2->Cells[7][i]);
    StringGrid2->Cells[8][i] = FloatToStr(1/(1+exp(-t))*10);
  }
//Кінець розрахунку Yi
//Вставка y
  StringGrid2->Cells[9][0] = "   y";
  StringGrid2->Cells[6][13] = "1,4";
  for (int i = 1; i < 13; i++) {
    StringGrid2->Cells[9][i] = StringGrid2->Cells[6][i+1];
  }
//Кінець вставки y
//Вставка (Yi-y)^2
  StringGrid2->Cells[10][0] = "(Yi-y)";
  float tt,ttt;
  for (int i = 1; i < 13; i++) {  //Цикл до 12
    tt = StrToFloat(StringGrid2->Cells[8][i]);
    ttt = StrToFloat(StringGrid2->Cells[9][i]);
    tt = tt-ttt;
    tt = pow(tt,2);
    StringGrid2->Cells[10][i] = FloatToStr(tt);
  }
//Кінець вставки (Yi-y)^2
//Розрахунок Е
  StringGrid2->Cells[11][0] = "    Е";
  tt = 0;
  for (int i = 1; i < 13; i++) {
    tt = tt+StrToFloat(StringGrid2->Cells[10][i]);
  }
  for (int i = 1; i < 13; i++) {
    StringGrid2->Cells[11][i] = FloatToStr(tt);
  }
  if (ii == 1) {StringGrid2->Cells[11][13] = StringGrid2->Cells[11][12];}
  else {StringGrid2->Cells[11][13] = FloatToStr(StrToFloat(StringGrid2->Cells[11][13])-StrToFloat(StringGrid2->Cells[11][12]));}
//  ShowMessage(StringGrid2->Cells[11][13]);
//Кінець розрахунку Е
//Розрахунок E1, E2, E3
  StringGrid2->Cells[12][0] = " E1";
  StringGrid2->Cells[13][0] = " E2";
  StringGrid2->Cells[14][0] = " E3";
  t,tt,ttt = 0;
  float x1,x2,x3,r,rr,v;
  for (int i = 1; i < 13; i++) {
    t = StrToFloat(StringGrid2->Cells[8][i]);  //Yi
    tt = StrToFloat(StringGrid2->Cells[9][i]);  //y
    ttt = StrToFloat(StringGrid2->Cells[7][i]); //S
    x1 = StrToFloat(StringGrid2->Cells[4][i]); //x1
    x2 = StrToFloat(StringGrid2->Cells[5][i]); //x2
    x3 = StrToFloat(StringGrid2->Cells[6][i]); //x3
    r = 1+exp(-ttt);
    rr = ((t-tt)*exp(-ttt))/(pow(r,2));
    StringGrid2->Cells[12][i] = FloatToStr(rr*x1);
    StringGrid2->Cells[13][i] = FloatToStr(rr*x2);
    StringGrid2->Cells[14][i] = FloatToStr(rr*x3);
  }
//Кінець розрахунку Е1, E2, E3
//Розрахунок dw1, dw2. dw3
    StringGrid2->Cells[15][0] = "  v";//Відображення v
    StringGrid2->Cells[16][0] = " dw1";
    StringGrid2->Cells[17][0] = " dw2";
    StringGrid2->Cells[18][0] = " dw3";
  v = 0.1;
  for (int i = 1; i < 13; i++) {
    StringGrid2->Cells[15][i] = FloatToStr(v);
    StringGrid2->Cells[16][i] = FloatToStr(StrToFloat(StringGrid2->Cells[12][i])*v*(-1));
    StringGrid2->Cells[17][i] = FloatToStr(StrToFloat(StringGrid2->Cells[13][i])*v*(-1));
    StringGrid2->Cells[18][i] = FloatToStr(StrToFloat(StringGrid2->Cells[14][i])*v*(-1));
  }
//Додавання
  t = 0; tt = 0; ttt = 0;
  for (int i = 1; i < 13; i++) {
    t = t+StrToFloat(StringGrid2->Cells[16][i]);
    tt = tt+StrToFloat(StringGrid2->Cells[17][i]);
    ttt = ttt+StrToFloat(StringGrid2->Cells[18][i]);
  }
  StringGrid2->Cells[16][13] = FloatToStr(t/12);//Використовується при додаванні
  StringGrid2->Cells[17][13] = FloatToStr(tt/12);//Використовується при додаванні
  StringGrid2->Cells[18][13] = FloatToStr(ttt/12);//Використовується при додаванні
//Закінчення розрахунку dw1, dw2. dw3
//Додавання w1+dw1/w2+dw2/w3+dw3
  dw1 = StrToFloat(StringGrid2->Cells[16][13]);
  dw2 = StrToFloat(StringGrid2->Cells[17][13]);
  dw3 = StrToFloat(StringGrid2->Cells[18][13]);
 }
 Button3->Enabled = true;
 Button4->Enabled = true; 
 Chart1->SeriesList->Series[0]->AddXY(-1,-15,"",clBtnFace);
 for (int i = 1; i < 12; i++) {
   Chart1->SeriesList->Series[0]->AddXY(StrToInt(StringGrid1->Cells[0][i]),StrToFloat(StringGrid2->Cells[9][i]),"",clRed);
 }

 for (int i = 1; i < 12; i++) {
   Chart1->SeriesList->Series[1]->Clear();
 }
 for (int i = 1; i < 12; i++) {
   Chart1->SeriesList->Series[1]->AddXY(StrToInt(StringGrid1->Cells[0][i]),StrToFloat(StringGrid2->Cells[10][i]),"",clGreen);
 }
 Chart1->SeriesList->Series[0]->AddXY(13,30,"",clBtnFace);
 count = count+1;
 Chart2->SeriesList->Series[0]->AddXY(count,StrToFloat(StringGrid2->Cells[11][13]),"",clRed);
//Закінчення тіла циклу

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   count = count+1;
   StringGrid2->Visible = false;
   Chart1->Visible = false;
   Chart2->Visible = true;
   Chart2->SeriesList->Series[0]->AddXY(count,StrToFloat(StringGrid2->Cells[11][13]),"",clRed);
//Закінчення тіла циклу
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  Image1->Canvas->Pen->Color = clBlack;
  //Малювання ліній
  Image1->Canvas->Pen->Width = 3; //товщина
  Image1->Canvas->MoveTo(440,200);//початок відмальовування
  Image1->Canvas->LineTo(670,200);//кінець відмальовування

  Image1->Canvas->MoveTo(100,100);//початок відмальовування
  Image1->Canvas->LineTo(400,200);//кінець відмальовування

  Image1->Canvas->MoveTo(100,200);//початок відмальовування
  Image1->Canvas->LineTo(300,200);//кінець відмальовування

  Image1->Canvas->MoveTo(367,40);//початок відмальовування
  Image1->Canvas->LineTo(367,200);//кінець відмальовування

  Image1->Canvas->MoveTo(100,300);//початок відмальовування
  Image1->Canvas->LineTo(400,200);//кінець відмальовування
//Кінець малювання ліній
   Image1->Canvas->Brush->Color = clBlack;
//Малювання кола
   int radius = 70;
   int posX = 370;
   int posY= 200;
   Image1->Canvas->Pen->Width = 3;
   Image1->Canvas->Ellipse(TRect(posX-radius, posY-radius, posX+radius, posY+radius));
   ReleaseDC(Handle, Canvas->Handle);
//Кінець малювання кола

  Timer1->Enabled = false;
  Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{

   Image1->Canvas->Pen->Color = clBlue;
   Image1->Canvas->MoveTo(440,200);//початок відмальовування
   Image1->Canvas->LineTo(670,200);//кінець відмальовування

   Image1->Canvas->Pen->Color = clRed;
   Image1->Canvas->MoveTo(100,100);//початок відмальовування
   Image1->Canvas->LineTo(400,200);//кінець відмальовування

   Image1->Canvas->MoveTo(100,200);//початок відмальовування
   Image1->Canvas->LineTo(300,200);//кінець відмальовування

   Image1->Canvas->MoveTo(367,40);//початок відмальовування
   Image1->Canvas->LineTo(367,200);//кінець відмальовування

   Image1->Canvas->MoveTo(100,300);//початок відмальовування
   Image1->Canvas->LineTo(400,200);//кінець відмальовування

   Image1->Canvas->Brush->Color = clBlue;
   int radius = 70;
   int posX = 370;
   int posY= 200;
   Image1->Canvas->Pen->Width = 3;
   Image1->Canvas->Ellipse(TRect(posX-radius, posY-radius, posX+radius, posY+radius));
   ReleaseDC(Handle, Canvas->Handle);

Timer1->Enabled = true;
Timer2->Enabled = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PageControl1Changing(TObject *Sender,
      bool &AllowChange)
{
//   ShowMessage("111");
/*   if (PageControl1->ActivePageIndex == 3)
   {
    StringGrid3->RowCount = 0;
    StringGrid3->ColCount = 0;
   }
   */
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
if (TrackBar1->Position > 0) {Button5->Enabled = true;}  else {Button5->Enabled = false;} 
if (TrackBar1->Position == 0) {
    StringGrid3->ColCount = 0;
    StringGrid3->RowCount = 0;
  } else
  if (TrackBar1->Position == 1) {
    StringGrid3->ColCount = 3;
    StringGrid3->RowCount = 3;
    StringGrid3->DefaultColWidth = 110;
    StringGrid3->DefaultRowHeight = 110;
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        StringGrid3->Cells[i][j] = "-1";
      }
    }
  } else
  if (TrackBar1->Position == 2) {
    StringGrid3->ColCount = 10;
    StringGrid3->RowCount = 10;
    StringGrid3->DefaultColWidth = 32;
    StringGrid3->DefaultRowHeight = 32;
    for (int i = 0; i < 31; i++)
    {
      for (int j = 0; j < 31; j++)
      {
        StringGrid3->Cells[i][j] = "-1";
      }
    }
  } else
  if (TrackBar1->Position == 3) {
    StringGrid3->ColCount = 65;
    StringGrid3->RowCount = 65;
    StringGrid3->DefaultColWidth = 4;
    StringGrid3->DefaultRowHeight = 4;
    for (int i = 0; i < 64; i++)
    {
      for (int j = 0; j < 64; j++)
      {
        StringGrid3->Cells[i][j] = "-1";
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  if ((TrackBar1->Position > 0) && (Button5->Caption == "Вибрати масштаб"))
  {
    count = -1;//Кількість рядків StringGrid5
    Button5->Enabled = false;
    TrackBar1->Enabled = false;
    if (TrackBar1->Position == 1)
    {
      StringGrid5->ColCount = 9;
    } else
    if (TrackBar1->Position == 2)
    {
      StringGrid5->ColCount = 100;
    } else
    if (TrackBar1->Position == 3)
    {
      StringGrid5->ColCount = 4225;
    }
    Button6->Enabled = true;
    StringGrid3->Enabled = true;

  }  else  if  (Button5->Caption == "Розпізнати")
  {
  //Розпізнавання
  //Фільтрування
    for (int j=0; j<10; j++)//Повторити 5 разів
    {
      for (int i=0; i<StringGrid4->RowCount; i++)
      {
         if (StrToInt(StringGrid4->Cells[0][i])>=0) {StringGrid6->Cells[0][i] ="1";}
         else {StringGrid6->Cells[0][i] ="-1";}
      }
      //Знову множення вже з новим StringGrid6
      for (int i=0; i<StringGrid7->RowCount; i++)
      {
        StringGrid4->Cells[0][i] = "0";
        for (int j=0; j<StringGrid7->ColCount; j++)
        {
          StringGrid4->Cells[0][i] = IntToStr(StrToInt(StringGrid4->Cells[0][i])+StrToInt(StringGrid7->Cells[j][i])*StrToInt(StringGrid6->Cells[0][j]));
        }
      }
    }
    
  //Фільтрування
      for (int i=0; i<StringGrid4->RowCount; i++)
      {
         if (StrToInt(StringGrid4->Cells[0][i])>=0) {StringGrid6->Cells[0][i] ="1";}
         else {StringGrid6->Cells[0][i] ="-1";}
      }
   //Відображення результату
      int j = -1;
      int k =0;
      for (int i=0; i<StringGrid6->RowCount; i++)
      {
         j =j+1;
         if (j>2)
         {
           j = 0;
           k = k+1;
          }
         StringGrid3->Cells[j][k] = StringGrid6->Cells[0][i];
      }
   //ShowMessage("111");
  }

}
//---------------------------------------------------------------------------














void __fastcall TForm1::Button7Click(TObject *Sender)
{
   Button5->Caption = "Розпізнати";
   Button6->Caption = "Зіпсувати";
   Button7->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
   if (Button6->Caption == "Записати образ")
   {
      Button7->Enabled = true;
      //Запис образу до матриці StringGrid5
      count = count+1;//Додавання нового рядка до StringGrid5
      if (count>0) {StringGrid5->RowCount = StringGrid5->RowCount+1;}
      int j=-1; int k = 0;
      for (int i=0; i<StringGrid5->ColCount; i++)
      {
        j = j+1;
        if (j>StringGrid3->ColCount-1){j = 0; k =k+1;}
        StringGrid5->Cells[i][count] = StringGrid3->Cells[j][k];
      }
      //Розрахунок матриці StringGrid4
      //StringGrid5 - горизонтальний вектор
      //StringGrid5 - вертикальний вектор
      //StringGrid7 - сума матриць
      StringGrid4->ColCount = StringGrid5->ColCount;
      StringGrid4->RowCount = StringGrid5->ColCount;
      StringGrid6->RowCount = StringGrid5->ColCount;
      StringGrid7->ColCount = StringGrid5->ColCount;
      StringGrid7->RowCount = StringGrid5->ColCount;

      for (int i=0; i<StringGrid5->ColCount; i++)
      {
        StringGrid6->Cells[0][i] = StringGrid5->Cells[i][count];
      }
      //Множення матрицью Результат до StringGrid4
      for (int i=0; i<StringGrid4->ColCount; i++)
      {
         for (int j=0; j<StringGrid4->RowCount; j++)
         {
           StringGrid4->Cells[i][j] = IntToStr(StrToInt(StringGrid5->Cells[i][count])*StrToInt(StringGrid6->Cells[0][j]));
         }
      }
      if (count==0)
      {
        //Заповнення StringGrid7 нулями
        for (int i=0; i<StringGrid7->ColCount; i++)
        {
           for (int j=0; j<StringGrid7->RowCount; j++)
           {
             StringGrid7->Cells[i][j] = "0";
           }
        }
      }
      //Додавання до StringGrid7 нової матриці StringGrid4
      for (int i=0; i<StringGrid7->ColCount; i++)
      {
         for (int j=0; j<StringGrid7->RowCount; j++)
         {
           if (i!=j) {StringGrid7->Cells[i][j] = IntToStr(StrToInt(StringGrid7->Cells[i][j])+StrToInt(StringGrid4->Cells[i][j]));}
         }
      }
    ShowMessage("Образ записаний");
   } else//Зміна назви кнопки "Зіпсувати"
   {
     Button5->Enabled = true;
     Button6->Enabled = false;

     //Запис зіпсованого образу до StringGrid6
      int j=-1; int k = 0;
      for (int i=0; i<StringGrid6->RowCount; i++)
      {
        j = j+1;
        if (j>StringGrid3->ColCount-1){j = 0; k =k+1;}
        StringGrid6->Cells[0][i] = StringGrid3->Cells[j][k];
      }
      //StringGrid4 створення однієї колонки
      StringGrid4->ColCount = 1;
      //Множення StringGrid6 на StringGrid7. Результат до StringGrid4.
      for (int i=0; i<StringGrid7->RowCount; i++)
      {
        StringGrid4->Cells[0][i] = "0";
        for (int j=0; j<StringGrid7->ColCount; j++)
        {
          StringGrid4->Cells[0][i] = IntToStr(StrToInt(StringGrid4->Cells[0][i])+StrToInt(StringGrid7->Cells[j][i])*StrToInt(StringGrid6->Cells[0][j]));
        }
      }
      
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  extern int AACol, AARow;
   if ( Button == mbLeft ) StringGrid3->Cells[AACol][AARow] = "1"; else
   if ( Button == mbRight ) StringGrid3->Cells[AACol][AARow] = "-1";
}
//---------------------------------------------------------------------------








void __fastcall TForm1::StringGrid3SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
 AACol = ACol; AARow = ARow;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
 TStringGrid *p=(TStringGrid*)Sender;
 if (p->Cells[ACol][ARow]=="-1") {
  p->Canvas->Brush->Color=clRed;
 } else {
  p->Canvas->Brush->Color=clGreen;
 }
 p->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------


