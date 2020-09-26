#include <ncurses.h>
#include "TetrominoeClass.hpp"
#include "BoardClass.hpp"

enum eDirection {NONE, LEFT, RIGHT, UP, DOWN};
const int fps = 5;
bool tetronimoeExists = false;

void setup();
void draw(Board &board, Tetrominoe &tetrominoe);
void input(eDirection &dir, bool &gameOver);
void logic(Board &board, Tetrominoe &tetrominoe, eDirection dir, bool &gameOver);


void setup()
{
    initscr();                      // initialize ncurses
    cbreak();                       // character-at-a-time input? 
    noecho();                       // do not echo typed characters
    curs_set(0);                    // make cursor invisible
    nonl();                         // no newline
    intrflush(stdscr, false);       // prevents tty driver queue flush on interrupt key
    keypad(stdscr, true);          // enables ncurses to read the keypad from the terminal

}

void draw(Board &board, Tetrominoe &tetrominoe)
{
    clear();

    // get board information and draw board
    int width, height;
    width = board.getWidth();
    height = board.getHeight();

    std::vector< std::vector<int> > boardState(height, std::vector<int>(width, 0));
    board.getBoardState(boardState);

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
    
    // get tetrominoe information and draw tetrominoe
    int x, y;
    int blockCoordinates[4][2] = { 0 };
    tetrominoe.getBlockCoordinates(blockCoordinates);
    for(int i=0; i<4; i++)
    {
        x = blockCoordinates[i][0];
        y = blockCoordinates[i][1];
        mvprintw(x, y*2, "# ");
    }

    refresh();
}

void input(eDirection &dir, bool &gameOver)
{
    timeout(1000 / fps);            // set input blocking in ms
    int c = getch();
    switch(c)
    {
        case KEY_LEFT:  
            dir = LEFT;
            break;

        case KEY_RIGHT: 
            dir = RIGHT;
            break;

        case KEY_UP:    
            dir = UP;
            break;

        case KEY_DOWN:  
            dir = DOWN;
            break;

        // q pressed
        case 113:        
            gameOver = true;
            break;

        default:        
            dir = NONE;
            break;
    }
}

void logic(Board &board, Tetrominoe &tetrominoe, eDirection dir, bool &gameOver)
{
    switch(dir)
    {
        case LEFT:      
            tetrominoe.moveLeft();
            break;

        case RIGHT:
            tetrominoe.moveRight();
            break;

        case UP:
            tetrominoe.rotate();
            break;
        
        case DOWN:
            tetrominoe.moveDown();
            break;

        default:
            break;
    }

    bool result;
    int blockCoordinates[4][2];
    tetrominoe.getBlockCoordinates(blockCoordinates);
    result = board.checkCollision(blockCoordinates);
    if(!result)
    {
        tetrominoe.commitShape();
    }else
    {
        board.setTetrominoe(blockCoordinates);
        tetrominoe.newTetrominoe();
    }
    
}