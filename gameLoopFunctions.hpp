#include <ncurses.h>
#include "TetrominoeClass.hpp"
#include "BoardClass.hpp"

enum eDirection {NONE, LEFT, RIGHT, UP, DOWN};
bool gameOver = false;
const int fps = 30;
bool tetronimoeExists = false;

void setup();
void draw();
eDirection input();
void logic();


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

void draw(int width, int height, std::vector< std::vector<int> > &boardState, int blockCoordinates[][2])
{
    clear();

    // draw board
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(boardState[i][j])
            {
                mvprintw(i, j*2, "# ");
            } else{
                mvprintw(i, j*2, ". ");
            }
        }
    }
    // draw tetrominoe
    int x, y;
    for(int i=0; i<4; i++)
    {
        x = blockCoordinates[i][0];
        y = blockCoordinates[i][1];
        mvprintw(x, y*2, "# ");
    }

    refresh();
}

eDirection input()
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