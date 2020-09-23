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

    Tetrominoe t1('L', 5);
    t1.commitShape();
    t1.printSelf();

    int blockCoordinates[4][2];
    for(int i=0; i<4; i++)
    {
        t1.rotate();
        t1.commitShape();
        t1.printSelf();
        t1.getBlockCoordinates(blockCoordinates);

        std::cout<<std::endl;
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<2; k++)
            {
                std::cout<<blockCoordinates[j][k]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }


    return 0;
}