#include "TXLib.h"

namespace Draw
{
void drawPers   (int x, int y, int scale);
void drawEnemy  (int x, int y, int scale);
void draw2Pers  (int x, int y, int scale);
void draw3Pers  (int x, int y, int scale);
void draw3Enemy (int x, int y, int scale);
void draw2Enemy (int x, int y, int scale);
void drawBackground();
void drawScene();
}

namespace Move
{
void movePers  (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta);
void moveEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta);
void move2Pers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta);
void move2Enemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta);
void move3Pers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta);
}



int main()
{
    txCreateWindow (800, 600);

    //drawPers (320, 120, 5);
    //drawPers (420, 220, 10);

    //drawEnemy (100, 200, 4);

    //moveEnemy (300, 400, 200, 300, 8, 100);
    //movePers (500, 300, 700, 200, 10, 100);


    Draw::draw2Pers (300, 300, 5);
    //draw2Enemy (200, 200, 5);
    //move2Enemy (500, 300, 700, 200, 10, 100);
    Draw::draw3Pers (100, 100, 10);
    Draw::draw3Enemy (400, 400, 10);
    Draw::drawScene();

    return 0;
}



//Сделать радиус к функции дельту удаление
namespace Draw
{
void drawPers (int x, int y, int scale)
{
//100pix 20loops= 100/20=5pix/loop

    txSetFillColor (TX_BLUE);
    txCircle    (x, y, scale);
    txSetFillColor (TX_GREEN);
    txLine      (x, y + scale, x, y + 1.5*scale);

    txRectangle (x - scale, y + 1.5*scale, x + scale, y + 5*scale);

    txLine      (x - scale, y + 3*scale, x - 1.6*scale, y + 5*scale);
    txLine      (x + scale, y + 3*scale, x + 1.6*scale, y + 5*scale);

    txLine      (x - 0.4*scale, y + 5*scale, x - 0.6*scale, y + 8*scale);
    txLine      (x + 0.4*scale, y + 5*scale, x + 0.6*scale, y + 8*scale);
}

void drawEnemy (int x, int y, int scale)
{
    txSetFillColor (TX_RED);
    txRectangle (x - 0.6*scale, y - 0.6*scale, x + 0.6*scale, y + 0.6*scale);
    txLine      (x, y + 0.6*scale, x, y + 1.5*scale);

    txRectangle (x - scale, y + 1.5*scale, x + scale, y + 5*scale);

    txLine      (x - scale, y + 3*scale, x - 1.6*scale, y + 5*scale);
    txLine      (x + scale, y + 3*scale, x + 1.6*scale, y + 5*scale);

    txLine      (x - 0.4*scale, y + 5*scale, x - 0.6*scale, y + 6.5*scale);
    txLine      (x + 0.4*scale, y + 5*scale, x + 0.6*scale, y + 6.5*scale);
}

void draw2Pers (int x, int y, int scale)
{
    txSetFillColour (TX_YELLOW);
    POINT pointsHead[3]=  { {x-(0,5*scale), y}, {x+(0,5*scale), y},  { x, y+4*scale} };
    txPolygon ( pointsHead, 3 );
    txLine (x, y+4*scale, x, y+6*scale);
    txSetFillColour (TX_MAGENTA);
    POINT pointsBody[3] = { { x, y+6*scale }, { x-3*scale, y+14*scale }, {x+3*scale, y+14*scale } };
    txPolygon ( pointsBody, 3 );
    txLine ( x-(0,1*scale) , y+14*scale, x-(0,2*scale), y+16*scale);
    txLine ( x+(0,1*scale) , y+14*scale, x+(0,2*scale), y+16*scale);


}

void draw2Enemy (int x, int y, int scale)
    {
        txSetFillColour (TX_GREY);
        POINT pointsHead[3]=  { {x-(0,4*scale), y}, {x+(0,6*scale), y},  { x, y+4*scale} };
        txPolygon ( pointsHead, 3 );
        txLine (x, y+4*scale, x, y+6*scale);
        txSetFillColour (TX_RED);
        POINT pointsBody[3] = { { x, y+6*scale }, { x-4*scale, y+14*scale }, {x+2*scale, y+14*scale } };
        txPolygon ( pointsBody, 3 );
        txLine ( x-(0,2*scale) , y+14*scale, x-(0,3*scale), y+16*scale);
        txLine ( x , y+14*scale, x+(0,1*scale), y+16*scale);
    }

void draw3Pers (int x, int y, int scale)
{
      txSetFillColour (TX_LIGHTCYAN);
      txCircle (x, y, scale);
      txSetColour (TX_BLUE);
      txLine (x, y+scale, x, y+5*scale);

      txLine (x, y+2*scale, x-(0,1*scale), y+5*scale);
      txLine (x, y+2*scale, x+(0,1*scale), y+5*scale);

      txLine (x, y+5*scale, x-(0,1*scale), y+8*scale);
      txLine (x, y+5*scale, x+(0,1*scale), y+8*scale);
}

void draw3Enemy (int x, int y, int scale)
{
      txSetFillColour (TX_RED);
      txCircle (x, y, scale);
      txSetColour (TX_GREY);
      txLine (x, y+scale, x, y+5*scale);

      txLine (x, y+(0,1*scale), x-(0,1*scale), y+4*scale);
      txLine (x, y+(0,1*scale), x+(0,1*scale), y+4*scale);

      txLine (x, y+5*scale, x-(0,1*scale), y+7*scale);
      txLine (x, y+5*scale, x+(0,1*scale), y+7*scale);
}

void drawBackground ()
{
    txSetFillColour (TX_BLACK);
    txClear ();
    txSetColour (TX_RED);
    txLine (0, 300, 900, 300);
    txLine (0, 400, 900, 200);
    txLine (0, 200, 900, 400);
}

void drawScene ()
{
    for (int t = 0; t < 100; t++)
    {
        Draw::drawBackground();
        Draw::draw3Pers (100 + 2 * t, 100, 10);
        Draw::draw3Enemy (200 + 2 * t, 300, 10);
        Draw::draw2Pers (400 - 2 * t, 400 - 50 * (t % 4), 10 + t % 4);

        txSleep (100);
    }
}

}

namespace Move
{
void move2Pers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::draw2Pers (currPosX, currPosY, scale);
       txSleep (100);
    }
}

void move2Enemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta)
    {
        int vX = (finishX - startPosX)  / delta;
        int vY = (finishY - startPosY)  / delta;
        for (int t = 0; t < delta; t++)
        {
            int currPosX = startPosX + vX*t;
            int currPosY = startPosY+ vY*t;

            Draw::draw2Enemy(currPosX, currPosY, scale);
            txSleep (100);
        }
    }

void move3Pers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::draw3Pers (currPosX, currPosY, scale);
       txSleep (100);
    }
}

void move3Enemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::draw3Enemy (currPosX, currPosY, scale);
       txSleep (100);
    }
}

void movePers (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {

       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       txClearConsole();
       Draw::drawPers (currPosX, currPosY, scale);
       txSleep (100);
    }
}

void moveEnemy (int startPosX, int startPosY, int finishX, int finishY, int scale, int delta)
{
    int vX = (finishX - startPosX)  / delta;
    int vY = (finishY - startPosY)  / delta;
    for (int t = 0; t < delta; t++)
    {
       int currPosX = startPosX + vX*t;
       int currPosY = startPosY+ vY*t;
       Draw::drawEnemy (currPosX, currPosY, scale);
       txSleep (100);
    }
}
}
