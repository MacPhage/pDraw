//
//  main.cpp
//
//  C++ Source File
//
//  Created by Austin Jackson,
//  Last modified on March 6, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "PotentDraw_private.h"
#include "Brushes.h"

using namespace std;

int keyTimer;
int currentColor = 0;
int currentBrush = 0;
int maxBrushes = 12;
int windowX = 800;
int windowY = 800;
int A=100,B,C,D; //RMVs
char version[30] = VER_STRING;
char currentKey;
bool canDraw = false;
bool isWindows = true; //CHANGE FOR THE COMPILED OS

POINT mouse;

void setup();
void drawHUD();
void clearCanvas();
void drawHelp();
void pause();

int main()
{
    setup();
    cout<<"Version: "<<version<<endl;
    cout<<"pDraw programmed by Austin Jackson in C++"<<endl;
    cout<<"Find future updates at: srchub.org/u/mac  OR  srchub.org/p/pdraw"<<endl;
    cout<<"Last updated: Thursday, March 6, 2014.\n"<<endl;
    cout<<"INSTRUCTIONS:"<<endl;
    cout<<" - Make sure that the incoming window is put in the top-left corner!"<<endl;
    cout<<" - Make sure that the graphics window is selected when trying to draw!"<<endl;
    cout<<"CONTROLS:"<<endl;
    cout<<"    SPACEBAR = Toggle drawing ON or OFF"<<endl;
    cout<<"    UP ARROW = Change brush"<<endl;
    cout<<"    DOWN ARROW = Change brush"<<endl;
    cout<<"    LEFT ARROW = Change drawing color"<<endl;
    cout<<"    RIGHT ARROW = Change drawing color"<<endl;
    cout<<"    ESCAPE = Clear your canvas"<<endl;
    pause();
    initwindow(windowX,windowY,"PotentDraw");
    clearCanvas(); //Prepares the black canvas for drawing on
    setcolor(0);
    setfillstyle(1,0);

    for(;;) //Foreverloop that updates everything
    {
		if(kbhit()) //If the user pressed a key
		{
            currentKey = getch(); //Get the current key and assign it to currentKey
            keyTimer = 1; //Resets the keyTimer variable to prevent a key from being pressed twice
        }
        if(currentKey == KEY_ESC && keyTimer > 0) //If the user pressed ESC, clear the canvas
        {
            cout<<"(KEY_ESC)"<<endl;
            clearCanvas();
        }
        else if(currentKey == KEY_SPACEBAR && keyTimer > 0) //If the user pressed SPACEBAR, toggle canDraw
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
        else if(currentKey == KEY_UP && keyTimer > 0) //If the user pressed UP, cycle down a brush
        {
            cout<<"(KEY_UP)"<<endl;
            if(currentBrush > 0)
            {
                currentBrush--;
            }
        }
        else if(currentKey == KEY_DOWN && keyTimer > 0) //If the user pressed DOWN, cycle up a brush
        {
            cout<<"(KEY_DOWN)"<<endl;
            if(currentBrush < maxBrushes)
            {
                currentBrush++;
            }
        }
        else if(currentKey == KEY_LEFT && keyTimer > 0) //If the user pressed LEFT, cycle down a color
        {
            cout<<"(KEY_LEFT)"<<endl;
            if(currentColor > 0)
            {
                currentColor--;
            }
            setcolor(currentColor);
            setfillstyle(1,currentColor);
        }
        else if(currentKey == KEY_RIGHT && keyTimer > 0) //If the user pressed RIGHT, cycle up a color
        {
            cout<<"(KEY_RIGHT)"<<endl;
            if(currentColor < 15)
            {
                currentColor++;
            }
            setcolor(currentColor);
            setfillstyle(1,currentColor);
        }
        if(GetCursorPos(&mouse)) //If GetCursorPos() returns anything, log the coordinates in the console.
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
                    drawCircle(mouse.x,mouse.y,3);
                }
                else if(currentBrush == 2)
                {
                    drawFilledCircle(mouse.x,mouse.y,3);
                }
                else if(currentBrush == 3)
                {
                    drawCircle(mouse.x,mouse.y,5);
                }
                else if(currentBrush == 4)
                {
                    drawFilledCircle(mouse.x,mouse.y,5);
                }
                else if(currentBrush == 5)
                {
                    drawCircle(mouse.x,mouse.y,7);
                }
                else if(currentBrush == 6)
                {
                    drawFilledCircle(mouse.x,mouse.y,7);
                }
                else if(currentBrush == 7)
                {
                    drawSquare(mouse.x,mouse.y,3);
                }
                else if(currentBrush == 8)
                {
                    drawFilledSquare(mouse.x,mouse.y,3);
                }
                else if(currentBrush == 9)
                {
                    drawSquare(mouse.x,mouse.y,5);
                }
                else if(currentBrush == 10)
                {
                    drawFilledSquare(mouse.x,mouse.y,5);
                }
                else if(currentBrush == 11)
                {
                    drawSquare(mouse.x,mouse.y,7);
                }
                else if(currentBrush == 12)
                {
                    drawFilledSquare(mouse.x,mouse.y,7);
                }
            }
        }
        keyTimer--;
        drawHUD();
        if(A > 0)
        {
            drawHelp();
        }
    }
    cout<<"\nTerminating..."<<endl;
    bgiout<<"\nTerminating..."<<endl;
    delay(1000);
	return 0;
}

void drawHUD()
{
    //Selected color partition
    
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(0,0,"Current Color: ");
    rectangle(100,2,110,12);
    setcolor(currentColor);
    setfillstyle(1,currentColor);
    bar(101,3,110,12);
    
    //Enabled or disabled drawing partition
    
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
        setcolor(4);
        setfillstyle(1,4);
    }
    else
    {
        setcolor(14);
        setfillstyle(1,14);
    }
    bar(101,20,110,30);
    
    //Selected brush HUD partition
    
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(0,32,"Brush: ");
    setcolor(currentColor);
    setfillstyle(1,currentColor);
    if(currentBrush == 0)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawPixel(100,40);
    }
    else if(currentBrush == 1)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawCircle(100,40,3);
    }
    else if(currentBrush == 2)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledCircle(100,40,3);
    }
    else if(currentBrush == 3)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawCircle(100,40,5);
    }
    else if(currentBrush == 4)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledCircle(100,40,5);
    }
    else if(currentBrush == 5)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawCircle(100,40,7);
    }
    else if(currentBrush == 6)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledCircle(100,40,7);
    }
    else if(currentBrush == 7)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawSquare(100,40,3);
    }
    else if(currentBrush == 8)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledSquare(100,40,3);
    }
    else if(currentBrush == 9)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawSquare(100,40,5);
    }
    else if(currentBrush == 10)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledSquare(100,40,5);
    }
    else if(currentBrush == 11)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawSquare(100,40,7);
    }
    else if(currentBrush == 12)
    {
        setcolor(15);
        setfillstyle(1,15);
        bar(90,32,140,80);
        setcolor(currentColor);
        setfillstyle(1,currentColor);
        drawFilledSquare(100,40,7);
    }
}

void clearCanvas()
{
    cleardevice();
    setfillstyle(1,15);
    bar(0,0,windowX,windowY);
    setfillstyle(1,currentColor);
}

void drawHelp()
{
    setcolor(15);
    setfillstyle(1,15);
    outstreamxy(0,windowY-200);
    bgiout<<" pDraw programmed by Austin Jackson in C++ with WinBGIm "<<endl;
    bgiout<<" Available at srchub.org/p/pdraw "<<endl;
    bgiout<<" INSTRUCTIONS: "<<endl;
    bgiout<<"  - Make sure that the window is put in the top-left corner! "<<endl;
    bgiout<<"  - Make sure that the graphics window is selected when trying to draw! "<<endl;
    bgiout<<" CONTROLS: "<<endl;
    bgiout<<"  - SPACEBAR = Toggle drawing ON or OFF "<<endl;
    bgiout<<"  - UP ARROW = Change brush "<<endl;
    bgiout<<"  - DOWN ARROW = Change brush "<<endl;
    bgiout<<"  - LEFT ARROW = Change drawing color "<<endl;
    bgiout<<"  - RIGHT ARROW = Change drawing color "<<endl;
    bgiout<<"  - ESCAPE = Clear your canvas, and TO GET RID OF THIS "<<endl;
    setcolor(currentColor);
    A--;
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

void setup()
{
    initwindow(400,250,"Select me!");
    setcolor(15);
    setfillstyle(1,15);
    outtextxy(0,0,"Please move your cursor to the location where");
    outtextxy(0,20,"the bottom-right corner of the window should be.");
    outtextxy(0,40,"The incoming graphics window will need to be in the");
    outtextxy(0,60,"top-left corner of your screen regardless.");
    outtextxy(0,80,"Once you have picked a spot, press SPACEBAR.");
    outtextxy(0,120,"Waiting...");
    setcolor(currentColor);
    setfillstyle(1,currentColor);
    
    bool setupComplete = false;
    while(setupComplete == false)
    {
		if(kbhit()) //If the user pressed a key
		{
            currentKey = getch(); //Get the current key and assign it to currentKey
            keyTimer = 1; //Resets the keyTimer variable to prevent a key from being pressed twice
        }
        if(GetCursorPos(&mouse)) //If GetCursorPos() returns anything, log the coordinates in the console.
        {
            windowX = mouse.x;
            windowY = mouse.y;
        }
        if(currentKey == KEY_SPACEBAR && keyTimer > 0) //If the user pressed ESC, clear the canvas
        {
            setupComplete = true;
        }
    }
    if(windowX < 800)
    {
        windowX = 800;
    }
    if(windowY < 700)
    {
        windowY = 700;
    }
    closegraph();
    currentKey = 0;
}
