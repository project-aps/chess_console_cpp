#ifndef QUEEN_H
#define QUEEN_H

#include "bishop.h"
#include "rook.h"
#include "board.h"
#include <iostream>

class Queen : public Piece
{
    public:
//////////////////////////////////////////////////////////////////////////////////////////
    //constructor
    Queen(){

    }


//////////////////////////////////////////////////////////////////////////////////////////
    // check is the move valid for this piece Queen 

    bool valid_move(int start_x, int start_y, int final_x, int final_y,Board board)
    {
        
        if (start_x == final_x && start_y == final_y)
        {
            return false;
        }

        Cell* src=board.get_cell_pointer(start_x,start_y);
        Cell* dest=board.get_cell_pointer(final_x,final_y);
        
        if ((dest->get_color() == src->get_color()) && (dest->get_color() != NONE))
        {
            //cout << "Cannot move to own piece. Try again\n";
            return false;
        }


        Bishop bishop;
        Rook rook;

        //returns if either bishop or rook can move at that position
        return (bishop.valid_move(start_x,start_y,final_x,final_y,board) || rook.valid_move(start_x,start_y,final_x,final_y,board));

    }
/////////////////////////////////////////////////////////////////////////////////////////////////

    
};

#endif