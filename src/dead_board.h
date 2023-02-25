#ifndef DEAD_BOARD_H
#define DEAD_BOARD_H

#include "cell.h"
#include "color.h"

#include <vector>
#include <iostream>
using namespace std;

class Dead_Board
{

    Color color_dead_board;
    vector<Cell> cell;

public:
//////////////////////////////////////////////////////////
    // constructor

    Dead_Board() {
        this->color_dead_board=NONE;
    }

    Dead_Board(Color color)
    {
        this->color_dead_board = color;
    }

//////////////////////////////////////////////////////////////////////////
    // getter and setter of color_dead_board
    void set_color_dead_board(Color color)
    {
        this->color_dead_board = color;
    }

    Color get_color_dead_board()
    {
        return this->color_dead_board;
    }
//////////////////////////////////////////////////////////////////////////

    // settter of cell having its type vector

    void set_cell_dead_board(Piece_type p, Color piece_color)
    {
        if (piece_color == this->color_dead_board)
        {
            Cell c1(p, piece_color);
            cell.push_back(c1);
        }
    }

/////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

    // settter of cell having its type vector template

    void set_cell_dead_board(Piece_type p, Color piece_color,int x,int y)
    {
        if (piece_color == this->color_dead_board)
        {
            Cell c1(p, piece_color,x,y);
            cell.push_back(c1);
        }
    }
///////////////////////////////////////////////////////////////////
    //pop out the last element of the vector template of Cell type

    void pop_back_of_dead_board(Color color){
        if(this->color_dead_board==color){
            cell.pop_back();
        }
        else{}
    }
///////////////////////////////////////////////////////////////////
    void print_dead_board()
    {
        vector <Cell>::iterator itr;
        int count=0;
        cout<<endl;
        cout<<"DEAD BOARD: ";
        if(this->color_dead_board==WHITE){
        cout<<"WHITE"<<endl;
        }

        if(this->color_dead_board==BLACK){
        cout<<"BLACK"<<endl;
        }
    
        cout<<"-----------------------------------------\n";
        for (itr = cell.begin(); itr != cell.end(); itr++)
        {
            if(count%8==0){
                if(count ==0){
                   cout<<"| " ;
                }
                else{
                    cout <<endl;
                    cout<<"| " ;
                    
                }
            }
            cout <<get_color_first_character_dead_board(itr)<<get_piece_first_character_dead_board(itr) << " | ";
            count++;
        }
         
        cout << endl;
        
        cout<<"-----------------------------------------\n";
        cout<<"TOTAL DEAD PIECES: "<<count<<endl;
    }

///////////////////////////////////////////////////////////////////////////////////////////
    //return first character of COLOR
    char get_color_first_character_dead_board(vector <Cell> :: iterator itr){
        if(itr->get_color()==WHITE){
            return 'W';
        }
        if(itr->get_color()==BLACK){
            return 'B';
        }
        if(itr->get_color()==NONE){
            return ' ';
        }

    }

///////////////////////////////////////////////////////////////////////////////////////////
     //return first character of Piece_type
     char get_piece_first_character_dead_board(vector <Cell> :: iterator itr){
        if(itr->get_piece()==KING){
            return 'K';
        }
        if(itr->get_piece()==QUEEN){
            return 'Q';
        }
        if(itr->get_piece()==BISHOP){
            return 'B';
        }
        if(itr->get_piece()==KNIGHT){
            return 'N';
        }
        if(itr->get_piece()==ROOK){
            return 'R';
        }
        if(itr->get_piece()==PAWN){
            return 'P';
        }
        if(itr->get_piece()==EMPTY){
            return ' ';
        }
        

    }
    

//////////////////////////////////////////////////////////////////////////////////////

};

#endif
