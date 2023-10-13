#include <iostream>
#include <windows.h>
#include <conio.h>
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
        input();
        logic();
    }
    return 0;
}

void setup() 
{
    // initial settings
    gameOver = false;
    dir = STOP;
    score = 0;

    // position the snake at the center of the map
    x = width / 2;
    y = height / 2;

    // randomly position the fruit on the map
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void draw() 
{
    // hide the console cursor
    ShowConsoleCursor(false);
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
            // draw the left and right walls
            if (j == 0 || j == width + 2 - 1)
            {
                cout << "#";
            } 
            // draw the snake's head
            else if (i == y && j == x)
            {
                cout << "O";
            }
            // draw the fruit
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            // draw the empty space
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
    ShowConsoleCursor(true);
}

void input() 
{
    if (_kbhit())
    {
        switch (_getch())
        {
            // move left
            case 'a':
                dir = LEFT;
                break;
            // move right
            case 'd':
                dir = RIGHT;
                break;
            // move up
            case 'w':
                dir = UP;
                break;
            // move down
            case 's':
                dir = DOWN;
                break;
            // stop the game
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void logic() 
{
    // changes coordinates according to the direction
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    // terminate the game is the snake's head is out of map's bounds
    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }

    // if fruit is eaten
    if (x == fruitX && y == fruitY)
    {
        // increase the score
        score += 10;

        // randomly position the fruit on the map
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}