#include <ncurses.h>
#include <cmath> // pow
#include "TetrominoeClass.hpp"
#include "BoardClass.hpp"


enum eDirection {NONE, LEFT, RIGHT, UP, DOWN};
int fps = 30;
bool tetronimoeExists = false;

void setup();
void draw(Board &board, Tetrominoe &tetrominoe, int score, bool debug);
void input(eDirection &dir, bool &gameOver);
void logic(Board &board, Tetrominoe &tetrominoe, eDirection dir, bool &gameOver, int &score, int &combo);


void setup()
{
    initscr();                      // initialize ncurses
    cbreak();                       // character-at-a-time input? 
    noecho();                       // do not echo typed characters
    curs_set(0);                    // make cursor invisible
    nonl();                         // no newline
    intrflush(stdscr, false);       // prevents tty driver queue flush on interrupt key
    keypad(stdscr, true);           // enables ncurses to read the keypad from the terminal

}

void draw(Board &board, Tetrominoe &tetrominoe, int score, bool debug)
{
    clear();

    // get board information and draw board
    int width, height;
    width = board.getWidth();
    height = board.getHeight();

    std::vector< std::vector<int> > boardState(height, std::vector<int>(width, 0));
    board.getBoardState(boardState);

    for(int i=0; i<height - 1; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(boardState[i][j])
            {
                mvprintw(i + 1, j*2 + 2, "# ");
            } else{
                mvprintw(i + 1, j*2 + 2, "  ");
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
        mvprintw(y + 1, x*2 + 2, "# ");
    }

    // draw Panel
    const int panelwidth = 2 * (width + 15);
    // first draw top and bottom of panel
    for(int i=0; i<panelwidth + 1; i++)
    {
        mvprintw(0, i, "#");                // top
        mvprintw(height, i, "#");           // bottom
    }
    // now sides and divider
    for(int i=0; i<height; i++)
    {
        mvprintw(i + 1, 0, "#");            // left side
        mvprintw(i + 1, width * 2 + 2, "#");        // divider
        mvprintw(i + 1, panelwidth, "#");   // right side
    }
    // draw score in panel
    mvprintw(height - 2, width*2 + 8, "Score: %d", score);


    // debug info
    if(debug)
    {
        // tetrominoe coordinates
        for(int i=0; i<4; i++)
        {
            x = blockCoordinates[i][0];
            y = blockCoordinates[i][1];
            mvprintw(height + 2 + i, 0, "x: %d", x);
            mvprintw(height + 2 + i, 5, ", y: %d", y);
        }
        // collision
        bool result = board.checkCollision(blockCoordinates);
        mvprintw(height + 2, 13, "Collision: %d", result);
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

void logic(Board &board, Tetrominoe &tetrominoe, eDirection dir, bool &gameOver, int &score, int &combo)
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
    bool tetrominoePlaced = false;
    int blockCoordinates[4][2];
    tetrominoe.getBlockCoordinates(blockCoordinates);
    result = board.checkCollision(blockCoordinates);
    if(result)
    {
        // if collision happened and last action was move down then set the block on the board
        if(dir == DOWN)
        {
            tetrominoe.revertShape();
            tetrominoe.getBlockCoordinates(blockCoordinates);
            board.setTetrominoe(blockCoordinates);
            tetrominoe.newTetrominoe();
            tetrominoePlaced = true;
        }
        else{
            tetrominoe.revertShape();
        }
    }
    // check if rows are full if tetrominoe was placed
    // if they are, delete them and increment score
    if(tetrominoePlaced)
    {
        int deletedNum;
        deletedNum = board.checkFullRows();
        if(deletedNum)
        {
            score += pow(2, deletedNum + combo);
            combo += deletedNum;
        }
        else
        {
            combo = 0;
        }
        
    }
}