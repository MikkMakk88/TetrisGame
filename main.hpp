#include <ncurses.h>

const int fps = 30;


void setup();
void draw();
void input();
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

void draw()
{

}

void input()
{
    timeout(1000 / fps);             // set input blocking in ms
    int c = getch();
    switch(c)
    {
        case KEY_LEFT:
        break;

        case KEY_RIGHT:
        break;

        case KEY_UP:
        break;

        case KEY_DOWN:
        break;

        case 81:
        break;

        default:
        break;
    }
}

void logic()
{

}