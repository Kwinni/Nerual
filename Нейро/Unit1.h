//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Grids.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TButton *Button1;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TImage *Image10;
        TImage *Image11;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TStringGrid *StringGrid1;
        TStringGrid *StringGrid2;
        TButton *Button2;
        TChart *Chart1;
        TButton *Button3;
        TPointSeries *Series1;
        TButton *Button4;
        TPointSeries *Series2;
        TChart *Chart2;
        TLineSeries *Series3;
        TTimer *Timer1;
        TTimer *Timer2;
        TImage *Image12;
        TStringGrid *StringGrid3;
        TStringGrid *StringGrid4;
        TTrackBar *TrackBar1;
        TButton *Button5;
        TStringGrid *StringGrid5;
        TImage *Image13;
        TButton *Button6;
        TButton *Button7;
        TStringGrid *StringGrid6;
        TStringGrid *StringGrid7;
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall PageControl1Changing(TObject *Sender,
          bool &AllowChange);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall StringGrid3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall StringGrid3SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid3DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
