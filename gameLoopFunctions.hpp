#include <ncurses.h>
#include "TetrominoeClass.hpp"
#include "BoardClass.hpp"
#include <stdlib.h>
#include <time.h>

enum eDirection {NONE, LEFT, RIGHT, UP, DOWN};
bool gameOver = false;
const int fps = 30;
bool tetronimoeExists = false;

void setup();
void draw();
void input();
void logic();
char getRandomShape();


void setup()
{
    initscr();                      // initialize ncurses
    cbreak();                       // character-at-a-time input? 
    noecho();                       // do not echo typed characters
    curs_set(0);                    // make cursor invisible
    nonl();                         // no newline
    intrflush(stdscr, false);       // prevents tty driver queue flush on interrupt key
    keypad(stdscr, false);          // enables ncurses to read the keypad from the terminal

}

void draw(int blockCoordinates, std::vector< std::vector<int> > &boardState)
{
    // draw board
}

void input()
{
    eDirection dir;
    timeout(1000 / fps);             // set input blocking in ms
    int c = getch();
    switch(c)
    {
        case KEY_LEFT:  dir = LEFT;
        break;

        case KEY_RIGHT: dir = RIGHT;
        break;

        case KEY_UP:    dir = UP;
        break;

        case KEY_DOWN:  dir = DOWN;
        break;

        // q pressed
        case 81:        gameOver = true;
        break;

        default:        dir = NONE;
        break;
    }
    return dir;
}

void logic()
{
    if(!tetronimoeExists)
    {
        
    }
}

char getRandomShape()
{
    srand(time(NULL));
    int randint = rand() % 7;
    char outputShape;
    switch(randint)
    {
        case 0: outputShape = 'I';
            break;
        case 1: outputShape = 'O';
            break;
        case 2: outputShape = 'T';
            break;
        case 3: outputShape = 'L';
            break;
        case 4: outputShape = 'J';
            break;
        case 5: outputShape = 'S';
            break;
        case 6: outputShape = 'Z';
            break;
    }
    return outputShape;
}