#include "tetrominoeShapes.hpp"
#include <cstring>      // for memcpy
#include <iostream>
#include <stdlib.h>     // for rand() & srand()
#include <time.h>       // for time()


class Tetrominoe
{
        int x, y;
        int newX, newY;
        int spawnX, spawnY;
        int shape[4][4];
        int newShape[4][4];
        char getRandomShape();

    public:
        Tetrominoe(int spawnXIn, int spawnYIn);
        void newTetrominoe();
        void rotate();
        void moveLeft();
        void moveRight();
        void moveDown();
        void getBlockCoordinates(int arr[][2], bool collisionDetect);
        void commitShape();
        void printSelf();
};

// definitions for Tetrominoe methods
Tetrominoe::Tetrominoe(int spawnXIn, int spawnYIn)
{
    // x & y represent the upper left corner of the shape.
    srand(time(NULL));
    spawnX = spawnXIn;
    spawnY = spawnYIn;
    newTetrominoe();
}

char Tetrominoe::getRandomShape()
{
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

void Tetrominoe::newTetrominoe()
{
    newX = spawnX;
    newY = spawnY;

    char shapeChar = getRandomShape();

    int * selectedShape;
    switch(shapeChar)
    {
        case 'I':   selectedShape = &I[0][0];
            break;
        case 'O':   selectedShape = &O[0][0];
            break;
        case 'T':   selectedShape = &T[0][0];
            break;
        case 'J':   selectedShape = &J[0][0];
            break;
        case 'L':   selectedShape = &L[0][0];
            break;
        case 'S':   selectedShape = &S[0][0];
            break;
        case 'Z':   selectedShape = &Z[0][0];
            break;
    }
    std::memcpy(newShape, selectedShape, 4*4*sizeof(int));
    commitShape();
}

void Tetrominoe::rotate()
{
    int tempShape[4][4] = {0};
    for(int row=0; row<4; row++)
    {
        for(int column=0; column<4; column++)
        {
            if(shape[row][column] == 1)
            {
                tempShape[column][3 - row] = 1;
            }
        }
    }
    std::memcpy(newShape, tempShape, 4*4 * sizeof(int));
}

void Tetrominoe::moveLeft()
{
    newX = x;
    newX--;
}

void Tetrominoe::moveRight()
{
    newX = x;
    newX++;
}

void Tetrominoe::moveDown()
{
    newY = y;
    newY++;
}

// arr[4][2]
void Tetrominoe::getBlockCoordinates(int arr[][2], bool collisionDetect)
{
    int offsetX, offsetY;
    int cnt = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(shape[i][j] == 1)
            {
                offsetX = j;
                offsetY = i;
                if(collisionDetect)
                {
                    arr[cnt][0] = newX + offsetX;
                    arr[cnt][1] = newY + offsetY;
                }else
                {
                    arr[cnt][0] = x + offsetX;
                    arr[cnt][1] = y + offsetY;
                }
                cnt++;
            }
        }
    }
}

// commit newShape to shape. 
// Use after checking for collisions to confirm
void Tetrominoe::commitShape()
{
    std::memcpy(shape, newShape, 16*sizeof(int));
    x = newX;
    y = newY;
}

void Tetrominoe::printSelf()
{
    std::cout<<"x: "<<x<<", y: "<<y<<std::endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(shape[i][j] == 1)
            {
                std::cout<<"# ";
            }else
            {
                std::cout<<". ";
            }
        }
        std::cout<<std::endl;
    }
}