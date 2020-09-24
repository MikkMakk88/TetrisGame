// #include "main.hpp"
#include "TetrominoClass.hpp"
#include "BoardClass.hpp"

// declarations
bool gameOver;
int score;


// definitions
#define width 20
#define height 40


int main()
{
    // setup();
    // draw();
    // input();
    // logic();
    // endwin();

    Tetrominoe t1('L', 0);
    t1.commitShape();
    t1.rotate();
    t1.commitShape();
    std::cout<<std::endl;
    int blockCoordinates[4][2];
    t1.getBlockCoordinates(blockCoordinates);


    Board board1(10, 10);
    board1.printSelf();
    board1.setTetrominoe(blockCoordinates);
    board1.printSelf();
    board1.removeRows(1);
    board1.printSelf();



    return 0;
}