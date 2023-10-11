#include <iostream>
#include <windows.h>
using namespace std;

// function prototypes
void setup();
void draw();
void input();
void logic();
void ShowConsoleCursor(bool showFlag);

// map dimensions
const int width = 20;
const int height = 20;

// object coordinates and directions
int x, y;

// fruit position
int fruitX, fruitY;

// other
bool gameOver;
int score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

int main() 
{
    setup();
    while(!gameOver)
    {
        draw();
    }
    return 0;
}

void setup() 
{
    ShowConsoleCursor(false);
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw() 
{
    // clear the console
    system("clear");

    // draw the top wall
    for (int i = 0; i < width + 2; i++) 
    {
        cout << "#";
    }
    cout << endl;

    // draw side walls
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (j == 0 || j == width + 2 - 1)
            {
                cout << "#";
            } 
            else if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // draw the bottom wall
    for (int i = 0; i < width + 2; i++) 
    {
        cout << "#";
    }
    cout << endl;
    Sleep(33.34);
}

void input() 
{

}

void logic() 
{

}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}