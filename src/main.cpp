//
//  main.cpp
//
//  C++ Source File
//
//  Created by Austin Jackson,
//  Last modified on March 4, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "PotentDraw_private.h"
#include "Brushes.h"

using namespace std;

int keyTimer;
int currentColor = 0;
int currentBrush = 0;
int maxBrushes = 2;
char version[30] = VER_STRING;
char currentKey;
bool canDraw = false;
bool isWindows = true; //CHANGE FOR THE COMPILED OS

POINT mouse;

void drawHUD();
void clearCanvas();
void pause();

int main()
{
    cout<<"Version: "<<version<<endl;
    cout<<"Make sure that the incoming window is put in the top-left corner!"<<endl;
    cout<<"Controls:"<<endl;
    cout<<"    SPACEBAR = Toggle drawing ON or OFF"<<endl;
    cout<<"    UP ARROW = Change brush"<<endl;
    cout<<"    DOWN ARROW = Change brush"<<endl;
    cout<<"    LEFT ARROW = Change drawing color"<<endl;
    cout<<"    RIGHT ARROW = Change drawing color"<<endl;
    cout<<"    ESCAPE = Clear your canvas"<<endl;
    pause();
    initwindow(800,800,"PotentDraw");
    clearCanvas();
    outstreamxy(0,15);

    for(;;)
    {
		if(kbhit())
		{
            currentKey = getch();
            keyTimer = 1;
        }
        if(currentKey == KEY_ESC && keyTimer > 0)
        {
            cout<<"(KEY_ESC)"<<endl;
            clearCanvas();
        }
        else if(currentKey == KEY_SPACEBAR && keyTimer > 0)
        {
            cout<<"(KEY_SPACEBAR)"<<endl;
            if(canDraw == false)
            {
                canDraw = true;
            }
            else if(canDraw == true)
            {
                canDraw = false;
            }
        }
        else if(currentKey == KEY_UP && keyTimer > 0)
        {
            cout<<"(KEY_UP)"<<endl;
            if(currentBrush > 0)
            {
                currentBrush--;
            }
        }
        else if(currentKey == KEY_DOWN && keyTimer > 0)
        {
            cout<<"(KEY_DOWN)"<<endl;
            if(currentBrush < maxBrushes)
            {
                currentBrush++;
            }
        }
        else if(currentKey == KEY_LEFT && keyTimer > 0)
        {
            cout<<"(KEY_LEFT)"<<endl;
            if(currentColor > 0)
            {
                currentColor--;
            }
            setcolor(currentColor);
            setfillstyle(1,currentColor);
        }
        else if(currentKey == KEY_RIGHT && keyTimer > 0)
        {
            cout<<"(KEY_RIGHT)"<<endl;
            if(currentColor < 15)
            {
                currentColor++;
            }
            setcolor(currentColor);
            setfillstyle(1,currentColor);
        }
        if(GetCursorPos(&mouse))
        {
            cout<<"("<<mouse.x<<","<<mouse.y<<")"<<endl;
            if(canDraw == true)
            {
                if(currentBrush == 0)
                {
                    drawPixel(mouse.x,mouse.y);
                }
                else if(currentBrush == 1)
                {
                    drawCircle(mouse.x,mouse.y);
                }
                else if(currentBrush == 2)
                {
                    drawFilledCircle(mouse.x,mouse.y);
                }
            }
        }
        keyTimer--;
        drawHUD();
    }
    cout<<"\nTerminating..."<<endl;
    bgiout<<"\nTerminating..."<<endl;
    delay(1000);
	return 0;
}

void drawHUD()
{
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(0,0,"Current Color: ");
    rectangle(100,2,110,12);
    setcolor(currentColor);
    setfillstyle(1,currentColor);
    bar(101,3,110,12);
    
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(0,15,"Drawing: ");
    rectangle(100,19,110,30);
    if(canDraw == true)
    {
        setcolor(10);
        setfillstyle(1,10);
    }
    else if(canDraw == false)
    {
        setcolor(12);
        setfillstyle(1,4);
    }
    else
    {
        setcolor(14);
        setfillstyle(1,14);
    }
    bar(101,20,110,30);
    
    
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(0,32,"Brush: ");
    setcolor(currentColor);
    setfillstyle(1,currentColor);
    if(currentBrush == 0)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,35,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawPixel(100,40);
    }
    else if(currentBrush == 1)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,35,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawCircle(100,40);
    }
    else if(currentBrush == 2)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,35,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledCircle(100,40);
    }
}

void clearCanvas()
{
    cleardevice();
    setfillstyle(1,15);
    bar(0,0,800,800);
    setfillstyle(1,currentColor);
}

void pause()
{
    if(isWindows == true)
    {
        system("PAUSE");
    }
    else if(isWindows == false)
    {
		cout<<"Press any key to continue . . ."<<endl;
		getchar();
    }
}
