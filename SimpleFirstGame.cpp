#include "TXLib.h"

namespace Draw
{
void CircleSquarePers(int x, int y, int scale, int handsUp);
void SquareEnemy     (int x, int y, int scale, int handsUp);
void TrianglePers    (int x, int y, int scale, int headRight);
void CircleLinePers  (int x, int y, int scale, int handsUp, int legsUp);
void CircleLineEnemy (int x, int y, int scale, int handsUp, int legsUp);
void TriangleEnemy   (int x, int y, int scale, int headRight);
void Background();
void Scene();
void DrawText (const char text[]);
void DrawPersons2     (int handsUp1, int handsUp2, const char text[]);
void DrawPersons4     (int handsUpCircleSquarePers, int handsUpSquareEmemy, 
                       int inclineTrianglePers, int inclineTriangleEnemy,
                       const char text[]);
void DrawPersons6     (int handsUpCircleSquarePers, int handsUpSquareEmemy, 
                       int inclineTrianglePers, int inclineTriangleEnemy, 
                       int handsUpCircleLinePers, int handsUpCircleLineEnemy,
                       const char text[]);
void DrawPersonsGame6 (int handsUpCircleSquarePers, int handsUpSquareEmemy, 
                       int inclineTrianglePers, int inclineTriangleEnemy, 
                       int handsUpCircleLinePers, int handsUpCircleLineEnemy,
                       const char text[],
                       bool drawCircleSquarePers,
                       bool drawSquareEnemy,
                       bool drawTrianglePers,
                       bool drawTriangleEnemy,
                       bool drawCircleLinePers,
                       bool drawCircleLineEnemy);
void FinishScene      (const char text[]);
}

namespace Move
{
void MoveSquare      (int circleSquareY, int squareEnemyY, int v, int scale, int incline = 5);
void MoveTriangle    (int trianglePersY, int triangleEnemyY, int v, int scale, int incline = 5);
void MoveCircleLine  (int cicleLinePersY, int circleLineEnemyY, int v, int scale, int handsUpPers, int handsUpEnemy);
void CircleSquarePers(int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp);
void SquareEnemy     (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp);
void TrianglePers    (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int headRight);
void TriangleEnemy   (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int headRight);
void CircleLinePers  (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp, int legsUp);
void CircleLineEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta, int handsUp, int legsUp);
}

/*
0
1
2
3
4
8
11
13
16
17

43210
58046 (10) = 5 * 10^4 + 8 * 10^3 + 0 * 10^2 +  4 * 10^1 + 6 * 10^0 = 50000 + 8000 + 40 + 6
  -    ==        ==         ==    -    ==          ==         ==   
       v         ^^         ^^
        \________|___________|_____>>>>

42310
11001 (2) = 1 * 2^4 + 1 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0

2-5 8-5 16-5
/////////////////////////////////////////////////////////////
543210
110110 (2) = 1 * 2^5 + 1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 1 * 2^1 + 1 * 2^0

6543210
1100001 (2) = 1 * 2^6 + 1 * 2^5 + 0 * 2^4 + 0 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0

76543210
10000011 (2) = 1 * 2^7 + 0 * 2^6 + 0 * 2^5 + 0 * 2^4 + 0 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0

43210
10011 (2) = 1 * 2^4 + 0 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0

543210
101111 (2) = 1 * 2^5 + 0 * 2^4 + 1 * 2^3 + 1 * 2^2 + 1 * 2^1 + 1 * 2^0
////////////////////////////////////////////////////////////

543210
723414 (8) = 7 * 8^5 + 2 * 8^4 + 3 * 8^3 + 4 * 8^2 + 1 * 8^1 + 4 * 8^0

43210
33547 (8) = 3 * 8^4 + 3 * 8^3 + 5 * 8^2 + 4 * 8^1 + 7 * 8^0

43210
55761 (8) = 5 * 8^4 + 5 * 8^3 + 7 * 8^2 + 6 * 8^1 + 1 * 8^0

3210
7770 (8) = 7 * 8^3 + 7 * 8^2 + 7 * 8^1 + 0 * 8^0

43210
66321 (8) = 6 * 8^4 + 6 * 8^3 + 3 * 8^2 + 2 * 8^1 + 1 * 8^0
/////////////////////////////////////////////////////////////

43210
abcde (16) = 10 * 16^4 + 11 * 16^3 + 12 * 16^2 + 13 * 16^1 + 14 * 16^0

3210
f790 (16) = 15 * 16^3 + 7 * 16^2 + 9 * 16^1 + 0 * 16^0

43210
a36e1 (16) = 10 * 16^4 + 3 * 16^3 + 6 * 16^2 + 14 * 16^1 + 1 * 16^0

43210
fa524 (16) = 15 * 16^4 +10 * 16^3 + 5 * 16^2 + 2 * 16^1 + 4 * 16^0

543210
e3789c (16) = 14 * 16^4 + 3 * 16^4 + 7 * 16^3 + 8 * 16^2 + 9 * 16^1 + 12 * 16^0

*/

int main()
{
    txCreateWindow (800, 600);

    Draw::Scene();
    //                                               Cs S Tp Te Clp Cle
     //Draw::DrawPersonsGame6 (5, 5, 2, 2, 5, 4, "HI!", 1, 0, 1, 0, 0, 1);
     //Draw::DrawPersonsGame6 (5, 5, 2, 2, 5, 4, " ",   1, 0, 1, 1, 1, 0);

    return 0;
}



//Сделать радиус к функции дельту удаление
namespace Draw
{
void CircleSquarePers (int x, int y, int scale, int handsUp)//handsUp принимает значения от 0 до 5(чем больше значение чем ниже руки)
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

void TrianglePers (int x, int y, int scale, int headRight)//headRight отчечает за качание головы, 2- середина, меньше двух вниз левой частью, больше двух вниз правой частью
{
    int inclineL = 0;
    int inclineR = 0;
    if ((headRight % 6) > 2)
    {
        inclineL =   ROUND ((headRight % 6) * 0.3 * scale);
        inclineR = ROUND (- (headRight % 6) * 0.3 * scale);
    }

    if ((headRight % 6) < 2)
    {
        inclineL = ROUND (- (headRight % 6) * 0.3 * scale);
        inclineR = ROUND (  (headRight % 6) * 0.3 * scale);
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
            inclineL =   ROUND ((headRight % 6) * 0.3 * scale);
            inclineR = ROUND (- (headRight % 6) * 0.3 * scale);
        }

        if ((headRight % 6) < 2)
        {
            inclineL = ROUND (- (headRight % 6) * 0.3 * scale);
            inclineR =   ROUND ((headRight % 6) * 0.3 * scale);
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

void CircleLinePers (int x, int y, int scale, int handsUp, int legsUp)//по умолчанию handsUp-5, legsUp-2;
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
   
    Draw::Background();
    Draw::DrawText ("Это короткий маленький мультик");

    Move::MoveSquare (420, 437, 4, 10);

    Draw::DrawPersons2 (2, 5, "Игрок слева: Привет!");

    Draw::DrawPersons2 (5, 5, "Игрок справа: Здравствуй, как твои дела?");

    Draw::DrawPersons2 (2, 5, "Игрок слева: Отлично, не хочешь поиграть в мафию?");

    Draw::DrawPersons2 (5, 4, "Игрок справа: Я не против, только давай позовем других?");

   /* for (int t = 0; t < 90; t++)
    {
        Draw::Background();
        Draw::CircleSquarePers (350, 420, 10, 5);
        Draw::SquareEnemy      (390, 437, 10, 5);
        Draw::TrianglePers  (10 + 3 * t, 370, 8, 1 + (t % 3));
        Draw::TriangleEnemy (790 - 3 * t, 370, 8, 1 + (t % 3));

        txSleep (100);
    }
    */
    Move::MoveTriangle (370, 370, 3, 8);

    Draw::DrawPersons4 (2, 5, 2, 2, "Присоединившиеся игроки: Здравствуйте!");
    /*
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
    */
    Move::MoveCircleLine (420, 430, 2, 10, 5, 4);
    
    Draw::DrawPersons6 (5, 5, 2, 2, 2, 4, "Присоединившиеся игроки: Так будем играть в мафию или нет?");

    Draw::DrawPersons6 (5, 5, 2, 2, 5, 4, "Ведущий: Да. Правила: две мафии, три мирных, а также доктор"); 

    Draw::DrawPersons6 (5, 5, 2, 2, 5, 4, "Ведущий: Получаем роли и начинаем");

    Draw::DrawPersons6 (5, 5, 2, 2, 5, 4, "Ведущий: Роли розданы, начинаем");

    Draw::DrawPersons6 (5, 5, 2, 2, 5, 4, "Ведущий: Город засыпает");

    Draw::DrawPersons6 (1, 5, 2, 2, 5, 4, "Ведущий: Мафия делает выбор");

    Draw::DrawPersons6 (5, 5, 2, 5, 5, 4,"Ведущий: Доктор делает выбор");
    /*
    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    //                                                                                                    Cs S Tp Te Clp Cle
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 5, 4, "Ведущий: Город просыпается, без центрально-левого игрока", 1, 1, 1, 1, 1, 1);
    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    Draw::CircleLineEnemy (600, 430, 10, 2, 2);
    txSetColour (TX_BLACK);
     */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 5, 2, "Ведущий: На голосовании убит игрок", 0, 1, 1, 1, 1, 1);

    Draw::DrawPersonsGame6 (1, 5, 2, 2, 5, 4, "Ведущий: Город засыпает", 0, 1, 1, 1, 1, 0);
    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 2, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 2, 4, "Ведущий: Мафия делает выбор", 0, 1, 1, 1, 1, 0);
    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 2, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 2, 4, "Ведущий: Доктор делает выбор", 0, 1, 1, 1, 1, 0);
    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 5, 4, "Ведущий: Город просыпается, никто не умер", 0, 1, 1, 1, 1, 0);
    /**
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 4);
    Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 2, 4, "Ведущий: На голосование убит самый левый игрок", 0, 1, 1, 1, 1, 0);

    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    //Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 5, 4, "Ведущий: Город засыпает", 0, 1, 1, 1, 0, 0);

    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 2);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    //Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 2, 2, 2, 5, 4, "Ведущий: Мафия делает выбор", 0, 1, 1, 1, 0, 0);
    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 2);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 5);
    //Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 5, 5, 4, "Ведущий: Доктор делает выбор,", 0, 1, 1, 1, 0, 0);

    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 2);
    // Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 2, 5, 4, "Ведущий: Город просыпается, как не странно без потерь уже второй раз", 0, 1, 1, 1, 0, 0);

    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    Draw::TriangleEnemy (500, 370, 8, 5);
    // Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 5, 5, 4, "Ведущий: На голосовании убит самый правый игрок", 0, 1, 1, 1, 0, 0);

    /*
    Draw::Background();
    //Draw::CircleSquarePers (350, 420, 10, 1);
    Draw::SquareEnemy      (400, 437, 10, 5);
    Draw::TrianglePers  (250, 370, 8, 2);
    //Draw::TriangleEnemy (500, 370, 8, 2);
    // Draw::CircleLinePers  (150, 420, 10, 5, 2);
    //Draw::CircleLineEnemy (600, 430, 10, 4, 2);
    txSetColour (TX_BLACK);
    */
    Draw::DrawPersonsGame6 (1, 5, 2, 5, 5, 4, "Ведущий: Мафия выйграла, так бывает", 0, 1, 1, 0, 0, 0);

   /* for ( int t = 0; t < 100; t++)
    {
        Draw::Background();
        txSetColour (TX_BLACK);
        txTextOut (300, 100, "Левый игрок: Еееееееееееееееееееее, я выйграл, я крутой!");
        Draw::SquareEnemy      (400, 437, 10, 5);
        Draw::TrianglePers  (250, 370, 8, t % 6);

        txSleep (100);
    }
    */
    Draw::FinishScene ("Левый игрок: Еееееееееееееееееееее, я выйграл, я крутой!");

    Draw::Background();
    txSetColour (TX_BLACK);
    txTextOut (300, 100, "Мультфильм сделан Богомолом Сашей");
}

void DrawText (const char text[])
{
    txSetTextAlign ();
    txTextOut (txGetExtentX()/2, txGetExtentX()/4, text);
    txSleep (3000);
}

void DrawPersons2 (int handsUp1, int handsUp2, const char text[])
{
    Draw::Background ();
    Draw::CircleSquarePers (350, 420, 10, handsUp1);
    Draw::SquareEnemy      (400, 437, 10, handsUp2);
    Draw::DrawText (text);
}

void DrawPersons4 (int handsUpCircleSquarePers, int handsUpSquareEmemy, 
                   int inclineTrianglePers, int inclineTriangleEnemy, 
                   const char text[])
{
    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, handsUpCircleSquarePers);
    Draw::SquareEnemy      (400, 437, 10, handsUpSquareEmemy);
    Draw::TrianglePers  (250, 370, 8, inclineTrianglePers);
    Draw::TriangleEnemy (500, 370, 8, inclineTriangleEnemy);
    Draw::DrawText (text);
}

void DrawPersons6 (int handsUpCircleSquarePers, int handsUpSquareEmemy, 
                   int inclineTrianglePers, int inclineTriangleEnemy, 
                   int handsUpCircleLinePers, int handsUpCircleLineEnemy,
                   const char text[])
{
    Draw::Background();
    Draw::CircleSquarePers (350, 420, 10, handsUpCircleSquarePers);
    Draw::SquareEnemy      (400, 437, 10, handsUpSquareEmemy);
    Draw::TrianglePers  (250, 370, 8, inclineTrianglePers);
    Draw::TriangleEnemy (500, 370, 8, inclineTriangleEnemy);
    Draw::CircleLinePers  (150, 420, 10, handsUpCircleLinePers, 2);
    Draw::CircleLineEnemy (600, 430, 10, handsUpCircleLineEnemy, 2);
    txSetColour (TX_BLACK);
    Draw::DrawText (text);
}

void DrawPersonsGame6 (int handsUpCircleSquarePers, int handsUpSquareEmemy, 
                       int inclineTrianglePers, int inclineTriangleEnemy, 
                       int handsUpCircleLinePers, int handsUpCircleLineEnemy,
                       const char text[],
                       bool drawCircleSquarePers,
                       bool drawSquareEnemy,
                       bool drawTrianglePers,
                       bool drawTriangleEnemy,
                       bool drawCircleLinePers,
                       bool drawCircleLineEnemy)
{


    Draw::Background();

    if (drawCircleSquarePers) Draw::CircleSquarePers (350, 420, 10, handsUpCircleSquarePers);

    if (drawSquareEnemy)      Draw::SquareEnemy      (400, 437, 10, handsUpSquareEmemy);

    if (drawTrianglePers)     Draw::TrianglePers     (250, 370, 8, inclineTrianglePers);    

    if (drawTriangleEnemy)    Draw::TriangleEnemy    (500, 370, 8, inclineTriangleEnemy);

    if (drawCircleLinePers)   Draw::CircleLinePers   (150, 420, 10, handsUpCircleLinePers, 2);

    if (drawCircleLineEnemy)  Draw::CircleLineEnemy  (600, 430, 10, handsUpCircleLineEnemy, 2);

    txSetColour (TX_BLACK);
    Draw::DrawText (text);

}

void FinishScene (const char text[])
{
    for ( int t = 0; t < 100; t++)
    {
        Draw::Background();
        txSetColour (TX_BLACK);
        txTextOut (300, 100, text);
        Draw::SquareEnemy      (400, 437, 10, 5);
        Draw::TrianglePers  (250, 370, 8, t % 6);

        txSleep (100);
    }
}
}

namespace Move
{
void MoveSquare (int circleSquareY,
                 int squareEnemyY, 
                 int v, int scale, int incline)
{
    for (int t = 0; t < 90; t++)
    {
        Draw::Background ();
        Draw::CircleSquarePers (10  + v * t, circleSquareY, scale, incline);
        Draw::SquareEnemy      (790 - v * t, squareEnemyY, scale, incline);

        txSleep (100);
    }
}

void MoveTriangle (int trianglePersY, int triangleEnemyY, int v, int scale, int incline)
{
     for (int t = 0; t < 90; t++)
    {
        Draw::Background();
        Draw::CircleSquarePers (350, 420, 10, incline);
        Draw::SquareEnemy      (390, 437, 10, incline);
        Draw::TrianglePers  (10 + v * t, trianglePersY, scale, 1 + (t % 3));
        Draw::TriangleEnemy (790 - v * t, triangleEnemyY, scale, 1 + (t % 3));

        txSleep (100);
    }
}

void MoveCircleLine (int cicleLinePersY, int circleLineEnemyY, int v, int scale, int handsUpPers, int handsUpEnemy)
{
    for (int t = 0; t < 90; t++)
    {
        Draw::Background();
        Draw::CircleSquarePers (350, 420, 10, 5);
        Draw::SquareEnemy      (390, 437, 10, 5);
        Draw::TrianglePers   (250, 370, 8, 2);;
        Draw::TriangleEnemy  (500, 370, 8, 2);
        Draw::CircleLinePers  (10 + v * t,  cicleLinePersY, scale, handsUpPers, t % 3);
        Draw::CircleLineEnemy (790 - v * t, circleLineEnemyY, scale, handsUpEnemy, t % 3);

        txSleep (100);
    }
}
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

