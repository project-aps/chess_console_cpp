#ifndef KNIGHT_ABC
#define KNIGHT_ABC

//#include "piece.h"
#include "board.h"
#include <iostream>

class Knight : public Piece
{

public:

//////////////////////////////////////////////////////////////////////////////////////////
    //constructor
    Knight(){};

//////////////////////////////////////////////////////////////////////////////////////////
    // check is the move valid for this piece Knight

    bool valid_move(int start_x, int start_y, int final_x, int final_y,Board board)
    {


        int x = abs(diff_x(start_x, final_x));
        int y = abs(diff_y(start_y, final_y));

        

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


        if (x * y == 2)
        {
            return true;
        }
        else
        {
            
            return false;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////
};
#endif
