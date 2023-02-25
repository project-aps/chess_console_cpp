#ifndef PIECE_H
#define PIECE_H

#pragma once
#include<iostream>
#include "game.h"
enum Piece_type {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN,EMPTY};


class Piece{
    protected:
    // Piece_type piece_type;
    //Cell cell           //each piece has its position in board 
    //bool is_white;      // store piece is white or not
    //bool is_alive;      // store piece is alive or not
    


    public:

////////////////////////////////////////////////////////////////////////////

//calcualte difference in x and y directrion from start to end cell
    int diff_x(int start_x, int final_x)
    {
        return (final_x - start_x);
    }
    int diff_y(int start_y, int final_y)
    {
        return (final_y - start_y);
    }

  
////////////////////////////////////////////////////////////////////

    //set this piece can move or not
    

};
#endif
