#include "TXLib.h"

namespace Draw
{
void CircleSquarePers   (int x, int y, int scale, int handsUp);
void SquareEnemy  (int x, int y, int scale, int handsUp);
void TrianglePers  (int x, int y, int scale, int headRight);
void CircleLinePers (int x, int y, int scale, int handsUp, int legsUp);
void CircleLineEnemy (int x, int y, int scale, int handsUp, int legsUp);
void TriangleEnemy (int x, int y, int scale, int headRight);
void Background();
void Scene();
}

namespace Move
{
void CircleSquarePers  (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp);
void SquareEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp);
void TrianglePers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int headRight);
void TriangleEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int headRight);
void CircleLinePers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp, int legsUp);
void CircleLineEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int legsUp);
}



int main()
{
    txCreateWindow (800, 600);


    //Draw::CircleLinePers(100,100,10);
    Draw::Scene();

    return 0;
}



//������� ������ � ������� ������ ��������
namespace Draw
{
void CircleSquarePers (int x, int y, int scale, int handsUp)//handsUp ��������� �������� �� 0 �� 5(��� ������ �������� ��� ���� ����)
{
//100pix 20loops= 100/20=5pix/loop
    int lengthAdd = 0;

    txSetFillColor (TX_BLUE);
    txCircle    (x, y, scale);
    txSetFillColor (TX_GREEN);
    txLine      (x, y + scale, x, y + 1.5*scale);

    txRectangle (x - scale, y + 1.5*scale, x + scale, y + 5*scale);

    if (handsUp == 3 || handsUp == 4 || handsUp == 2 || handsUp == 1)
    {
       lengthAdd = 6;
    }
    txLine      (x - scale, y + 3 * scale, x - 1.6 * scale - lengthAdd * 0.3 * scale, y + (handsUp % 6) * scale);//hands
    txLine      (x + scale, y + 3 * scale, x + 1.6 * scale + lengthAdd * 0.3 * scale, y + (handsUp % 6) * scale);

    txLine      (x - 0.4 * scale, y + 5 * scale, x - 0.6 * scale, y + 8 * scale);
    txLine      (x + 0.4 * scale, y + 5 * scale, x + 0.6 * scale, y + 8 * scale);
}

void SquareEnemy (int x, int y, int scale, int handsUp)
{
    int lengthAdd = 0;

    txSetFillColor (TX_RED);
    txRectangle (x - 0.6*scale, y - 0.6 * scale, x + 0.6 * scale, y + 0.6 * scale);
    txLine      (x, y + 0.6 * scale, x, y + 1.5 * scale);

    txRectangle (x - scale, y + 1.5 * scale, x + scale, y + 5 * scale);

    if (handsUp == 3 || handsUp == 4 || handsUp == 2 || handsUp == 1)
    {
       lengthAdd = 6;
    }

    txLine      (x - scale, y + 3*scale, x - 1.6*scale - lengthAdd * 0.3 * scale, y + (handsUp % 6) * scale);
    txLine      (x + scale, y + 3*scale, x + 1.6*scale + lengthAdd * 0.3 * scale, y + (handsUp % 6) * scale);

    txLine      (x - 0.4*scale, y + 5*scale, x - 0.6*scale, y + 6.5*scale);
    txLine      (x + 0.4*scale, y + 5*scale, x + 0.6*scale, y + 6.5*scale);
}

void TrianglePers (int x, int y, int scale, int headRight)//headRight �������� �� ������� ������, 2- ��������, ������ ���� ���� ����� ������, ������ ���� ���� ������ ������
{
    int inclineL = 0;
    int inclineR = 0;
    if ((headRight % 6) > 2)
    {
        inclineL =   (headRight % 6) * 0.3 * scale;
        inclineR = - (headRight % 6) * 0.3 * scale;
    }

    if ((headRight % 6) < 2)
    {
        inclineL = - (headRight % 6) * 0.3 * scale;
        inclineR =   (headRight % 6) * 0.3 * scale;
    }

    txSetFillColour (TX_YELLOW);
    POINT pointsHead[3]=  { {x-(5*scale) - 2 * scale + ((headRight % 6) * scale), y - inclineL},
                            {x+(5*scale) - 2 * scale + ((headRight % 6) * scale), y - inclineR}, { x, y+4*scale} };
    txPolygon ( pointsHead, 3 );
    txLine (x, y+4*scale, x, y+6*scale);
    txSetFillColour (TX_MAGENTA);
    POINT pointsBody[3] = { { x, y+6*scale }, { x-3*scale, y+14*scale }, {x+3*scale, y+14*scale } };
    txPolygon ( pointsBody, 3 );
    txLine ( x-(1*scale) , y+14*scale, x-(2*scale), y+16*scale);
    txLine ( x+(1*scale) , y+14*scale, x+(2*scale), y+16*scale);


}

void TriangleEnemy (int x, int y, int scale, int headRight)
    {
        int inclineL = 0;
        int inclineR = 0;
        if ((headRight % 6) > 2)
        {
            inclineL =   (headRight % 6) * 0.3 * scale;
            inclineR = - (headRight % 6) * 0.3 * scale;
        }

        if ((headRight % 6) < 2)
        {
            inclineL = - (headRight % 6) * 0.3 * scale;
            inclineR =   (headRight % 6) * 0.3 * scale;
        }

        txSetFillColour (TX_GREY);
        POINT pointsHead[3]=  { {x - (4*scale) - 2 * scale + ((headRight % 6) * scale), y - inclineL}, {x + (6*scale) -  2 * scale + ((headRight % 6) * scale), y - inclineR},  { x, y+4*scale} };
        txPolygon ( pointsHead, 3 );
        txLine (x, y+4*scale, x, y+6*scale);
        txSetFillColour (TX_RED);
        POINT pointsBody[3] = { { x, y+6*scale }, { x-4*scale, y+14*scale }, {x+2*scale, y+14*scale } };
        txPolygon ( pointsBody, 3 );
        txLine ( x-(2*scale) , y+14*scale, x-(3*scale), y+16*scale);
        txLine ( x , y+14*scale, x+(1*scale), y+16*scale);
    }

void CircleLinePers (int x, int y, int scale, int handsUp, int legsUp)//�� ��������� handsUp-5, legsUp-2;
{
      int lengthAdd = 0;
      int legsLengthAdd = 0;

      txSetFillColour (TX_LIGHTCYAN);
      txCircle (x, y, scale);
      txSetColour (TX_ORANGE);
      txLine (x, y+scale, x, y+5*scale);

      if (handsUp == 3 || handsUp == 4 || handsUp == 2 || handsUp==1)
      {
           lengthAdd = 6;
      }

      if (legsUp % 3 < 2)
      {
          legsLengthAdd = 5;
      }

      txLine (x, y + 2 * scale, x - (1 * scale) - lengthAdd * 0.3 * scale, y + (handsUp % 6) * scale);
      txLine (x, y + 2 * scale, x + (1 * scale) + lengthAdd * 0.3 * scale, y + (handsUp % 6) * scale);

      txLine (x, y + 5 * scale, x - (1 * scale) - legsLengthAdd * 0.1 * scale, y + 6 * scale + (legsUp % 3) * scale);
      txLine (x, y + 5 * scale, x + (1 * scale) + legsLengthAdd * 0.1 * scale, y + 6 * scale + (legsUp % 3) * scale);
}

void CircleLineEnemy (int x, int y, int scale, int handsUp, int legsUp)// handsup-4, legsUp -2(default)
{
      int lenghtAdd = 0;
      int legsLengthAdd = 0;

      txSetFillColour (TX_RED);
      txCircle (x, y, scale);
      txSetColour (TX_PINK);
      txLine (x, y+scale, x, y+5*scale);

      if (handsUp == 3 || handsUp == 1 || handsUp == 0 || handsUp == 2)
      {
           lenghtAdd = 6;
      }

      if (legsUp % 3 < 2)
      {
          legsLengthAdd = 5;
      }

      txLine (x, y + (1 * scale), (x - (1 * scale) -( lenghtAdd * 0.3 * scale)), y + (handsUp % 5) * scale);
      txLine (x, y + (1 * scale), x + (1 * scale) + lenghtAdd * 0.3 * scale, y + (handsUp % 5) * scale);

      txLine (x, y + 5 * scale, x - (1 * scale) - legsLengthAdd * 0.1 * scale, y + 7 * scale);
      txLine (x, y + 5 * scale, x + (1 * scale) + legsLengthAdd * 0.1 * scale, y + 7 * scale);
}

void Background ()
{
    txSetFillColour (TX_WHITE);
    txClear ();
    txSetFillColour (RGB (150, 75, 0));
    txSetColour (TX_BLACK);
    //txSetColour (TX_PINK);
    txRectangle (0, 500, 800, 600);
    txSetFillColour (TX_WHITE);
    txRectangle (0, 0, 800, 500);
}

void Scene ()
{
    int xCircleSquarePers = 10;
    int ySquareEnemy = 790;

    Draw::Background();
    txTextOut (200, 100, "��� �������� ��������� �������");
    txSleep(5000);

    for (int t = 0; t < 90; t++)
    {
        xCircleSquarePers += 4 * t;
        ySquareEnemy -= 4*t;
        Draw::Background ();
        Draw::CircleSquarePers (10 + 4 * t, 420, 10, 5);
        Draw::SquareEnemy      (790 - 4 * t, 437, 10, 5);

        txSleep (100);
    }

    txTextOut (300, 390, "����� �����: ������!");
    txSleep (3000);

    Draw::Background ();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    txTextOut (400, 390, "����� ������: ����������, ��� ���� ����?");
    txSleep (3000);

    Draw::Background ();
    Draw::CircleSquarePers (350, 420, 10, 2);
    Draw::SquareEnemy      (400, 437, 10, 5);
    txTextOut (300, 390, "����� �����: �������, �� ������ �������� � �����?");
    txSleep (3000);


    Draw::Background ();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 4);
    txTextOut (300, 390, "����� ������: � �� ������, ������ ����� ������� ������?");
    txSleep (3000);

    for (int t = 0; t < 90; t++)
    {
        Draw::Background();
        Draw::CircleSquarePers (350, 420, 10, 5);
        Draw::SquareEnemy      (390, 437, 10, 5);
        Draw::TrianglePers  (10 + 3 * t, 370, 8, 1 + (t % 3));
        Draw::TriangleEnemy (790 - 3 * t, 370, 8, 1 + (t % 3));

        txSleep (100);
    }

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 2);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    txTextOut (200, 300, "���������������� ������: ������������!");
    txSleep (3000);

    for (int t = 0; t < 90; t++)
    {
        Draw::Background();
        Draw::CircleSquarePers (350, 420, 10, 5);
        Draw::SquareEnemy      (390, 437, 10, 5);
        Draw::TrianglePers   (250, 370, 8, 2);;
        Draw::TriangleEnemy  (500, 370, 8, 2);
        Draw::CircleLinePers  (10 + 2 * t,  420, 10, 5, t % 3);
        Draw::CircleLineEnemy (790 - 2 * t, 430, 10, 4, t % 3);

        txSleep (100);
    }

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 2, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (80, 350, "���������������� ������: ��� ����� ������ � ����� ��� ���?");
    txSleep (3000);

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ��. �������: ��� �����, ��� ������, � ����� ������");
    txSleep (3000);

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: �������� ���� � ��������");
    txSleep (3000);

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ���� �������, ��������");
    txSleep (3000);
    
    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ��������");
    txSleep (1000);

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ������ �����");
    txSleep (2000);

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 5);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 5);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ������ ������ �����");
    txSleep (2000);

    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� �����������, ��� ����������-������ ������");
    txSleep (3000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 2, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: �� ����������� ���� �����");
    txSleep (3000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ��������");
    txSleep (1000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 2, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ������ �����");
    txSleep (2000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 2, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ������ ������ �����");
    txSleep (2000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� �����������, ����� �� ����");
    txSleep (2000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: �� ����������� ���� ����� ����� �����");
    txSleep (3000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    //Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ��������");
    txSleep (1000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 2);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    //Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ������ �����");
    txSleep (2000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 2);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 5);
    //Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ������ ������ �����");
    txSleep (2000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    // Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� �����������, ��� �� ������� ��� ������ ��� ������ ���");
    txSleep (3000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 5);
    // Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: �� ����������� ���� ����� ������ �����");
    txSleep (3000);

    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    //Draw::TriangleEnemy (500, 370, 8, 2);
    // Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "�������: ����� ��������, ��� ������");
    txSleep (3000);

    Draw::Background();
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "���������� ������ ��������� �����");

    for ( int t = 0; t < 100; t++)
    {
        Draw::Background();
        txSetColour (TX_BLACK);
        txTextOut (300, 100, "����� �����: ���������������������, � �������, � ������!");
        Draw::SquareEnemy      (400, 437, 10, 5);
        Draw::TrianglePers  (250, 370, 8, t % 6);

        txSleep (100);
    }
}
}

namespace Move
{
void TrianglePers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int headRight)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::TrianglePers (currPosX, currPosY, scale, headRight);
       txSleep (100);
    }
}

void TriangleEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int headRight)
    {
        int vX = (finishX - startPosX)  / delta;
        int vY = (finishY - startPosY)  / delta;
        for (int t = 0; t < delta; t++)
        {
            int currPosX = startPosX + vX*t;
            int currPosY = startPosY+ vY*t;

            Draw::TriangleEnemy(currPosX, currPosY, scale, headRight);
            txSleep (100);
        }
    }

void CircleLinePers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp, int legsUp)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::CircleLinePers (currPosX, currPosY, scale, handsUp, legsUp);
       txSleep (100);
    }
}

void CircleLineEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp, int legsUp)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::CircleLineEnemy (currPosX, currPosY, scale, handsUp, legsUp);
       txSleep (100);
    }
}

void CircleSquarePers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {

       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       txClearConsole();
       Draw::CircleSquarePers (currPosX, currPosY, scale, handsUp);
       txSleep (100);
    }
}

void SquareEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::SquareEnemy (currPosX, currPosY, scale, handsUp);
       txSleep (100);
    }
}
}

