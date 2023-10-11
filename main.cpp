#include <iostream>
using namespace std;

// function prototypes
void setup();
void draw();
void input();
void logic();

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
    
}

void input() 
{

}

void logic() 
{

}