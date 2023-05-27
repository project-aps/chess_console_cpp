#ifndef BOARD_H
#define BOARD_H


#pragma once
//#include "cell.h"
//#include "piece.h"
#include "cell.h"
//#include "game.h"
#include "game_status.h"
#include<vector>
#include<iostream>

using namespace std;

//Game_staus game_staus=ACTIVE;

// starting value of array of x-axis and x-axis
const int start_x=1;
const int start_y=1;



// ending value of array of x-axis and x-axis
const int end_x=start_x+8;
const int end_y=start_x+8;

//Pawn level in y-axis
// while changing this value we also need to change the code of pawn class
const int white_pawn_start_y=start_y+1; //2
const int black_pawn_start_y=start_y+6; //7

// setting starting and ending postion 
const int starting_cell_x=start_x;
const int starting_cell_y=start_y;

const int ending_cell_x=start_x+7;
const int ending_cell_y=start_y+7;

class Board{

    //construct a cell of an array 8X8
    Cell cell[end_x][end_y];

    public:
    
    //constructor
    Board(){
        set_board_initially();
    }

//////////////////////////////////////////////////////////////////////////////////////
    void set_board_initially(){

    //setting pieces except pawn
        /*
            note:
                if we change the swap the white and black pieces go through pawn code
                    as pawn move forward only
                    for white pawn its cell->y-direction should increase by 1 as it moves forward
                    for black pawn its cell->y-direction should decrease by 1 as it moves forrward
                    
        */

        //white pieces
        cell[start_x+0][start_y+0].set_cell(ROOK,WHITE,start_x+0,start_y+0);
        cell[start_x+1][start_y+0].set_cell(KNIGHT,WHITE,start_x+1,start_y+0);
        cell[start_x+2][start_y+0].set_cell(BISHOP,WHITE,start_x+2,start_y+0);
        cell[start_x+3][start_y+0].set_cell(QUEEN,WHITE,start_x+3,start_y+0);
        cell[start_x+4][start_y+0].set_cell(KING,WHITE,start_x+4,start_y+0);
        cell[start_x+5][start_y+0].set_cell(BISHOP,WHITE,start_x+5,start_y+0);
        cell[start_x+6][start_y+0].set_cell(KNIGHT,WHITE,start_x+6,start_y+0);
        cell[start_x+7][start_y+0].set_cell(ROOK,WHITE,start_x+7,start_y+0);

        //black pieces
        cell[start_x+0][start_y+7].set_cell(ROOK,BLACK,start_x+0,start_y+7);
        cell[start_x+1][start_y+7].set_cell(KNIGHT,BLACK,start_x+1,start_y+7);
        cell[start_x+2][start_y+7].set_cell(BISHOP,BLACK,start_x+2,start_y+7);
        cell[start_x+3][start_y+7].set_cell(QUEEN,BLACK,start_x+3,start_y+7);
        cell[start_x+4][start_y+7].set_cell(KING,BLACK,start_x+4,start_y+7);
        cell[start_x+5][start_y+7].set_cell(BISHOP,BLACK,start_x+5,start_y+7);
        cell[start_x+6][start_y+7].set_cell(KNIGHT,BLACK,start_x+6,start_y+7);
        cell[start_x+7][start_y+7].set_cell(ROOK,BLACK,start_x+7,start_y+7);

    //setting pawn pieces
        for(int i=0;i<=7;i++){
            
                cell[start_x+i][start_y+1].set_cell(PAWN,WHITE,start_x+i,start_y+1);
                cell[start_x+i][start_y+6].set_cell(PAWN,BLACK,start_x+i,start_y+6);
            
        }

    // setting empty pieces in remaining vacant cell
        for(int i=0;i<=7;i++){
            for(int j=2;j<=5;j++){
                cell[start_x+i][start_y+j].set_cell(EMPTY,NONE,start_x+i,start_y+j);
                
            }
        }

    }
///////////////////////////////////////////////////////////////////////////////////////////

    void print_board(){
       

        cout<<endl;
        cout<<"   ------------------- WHITE SIDE -------------------   "<<endl;
        
        //printing upper index starting from 1 to 8
        cout<<"   ";
        for(int i=1;i<=8;i++){
          cout<<"   "<<char(i+96)<<"  ";  
        }
        cout<<endl;


        cout<<"   --------------------------------------------------\n";
        for(int j=start_y;j<=start_y+7;j++){
            
            //printing side index starting from 1 to 8    
            cout<<" "<<j<<" ";

            cout<<"| ";

            for(int i=start_x;i<=start_x+7;i++){

                
                cout<<" "<<get_color_first_character(i,j)<< get_piece_first_character(i,j)<<" ";
                cout<<" |";
            }
            //printing side index starting from 1 to 8
            cout<<" "<<j<<" ";

            cout<<endl;
            cout<<"   --------------------------------------------------\n";
        
        }
         //printing lower index starting from 1 to 8
         cout<<"    ";
        for(int i=1;i<=8;i++){
          cout<<"   "<<char(i+96)<<"  ";  
        }

        cout<<endl;
        cout<<"   ------------------- BLACK SIDE -------------------   "<<endl;
        
    }

///////////////////////////////////////////////////////////////////////////////////////////
    //return first character of COLOR
    char get_color_first_character(int i, int j){
        if(get_cell(i,j).get_color()==WHITE){
            return 'W';
        }
        if(get_cell(i,j).get_color()==BLACK){
            return 'B';
        }
        if(get_cell(i,j).get_color()==NONE){
            return ' ';
        }

    }

///////////////////////////////////////////////////////////////////////////////////////////
     //return first character of Piece_type
     char get_piece_first_character(int i, int j){
        if(get_cell(i,j).get_piece()==KING){
            return 'K';
        }
        if(get_cell(i,j).get_piece()==QUEEN){
            return 'Q';
        }
        if(get_cell(i,j).get_piece()==BISHOP){
            return 'B';
        }
        if(get_cell(i,j).get_piece()==KNIGHT){
            return 'N';
        }
        if(get_cell(i,j).get_piece()==ROOK){
            return 'R';
        }
        if(get_cell(i,j).get_piece()==PAWN){
            return 'P';
        }
        if(get_cell(i,j).get_piece()==EMPTY){
            return ' ';
        }
        

    }
    

//////////////////////////////////////////////////////////////////////////////////////

    //getter and setter of cell

    Cell get_cell(int pos_x, int pos_y){
        return cell[pos_x][pos_y];
    }

    void set_cell(Cell &cell_source,int pos_x, int pos_y){
        this->cell[pos_x][pos_y]=cell_source;
    }

//////////////////////////////////////////////////////////////////////////////////////

    //getter and setter of cell_pointer

    Cell* get_cell_pointer(int pos_x, int pos_y){
        return &(cell[pos_x][pos_y]);
    }

    void set_by_cell_pointer(Cell* cell_source,int pos_x, int pos_y){
        this->cell[pos_x][pos_y]=*cell_source;
    }

//////////////////////////////////////////////////////////////
};

#endif
