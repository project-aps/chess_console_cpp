#ifndef CELL_H
#define CELL_H

#pragma once
#include "piece.h"
#include "color.h"


class Cell{
    
    Piece_type piece;
    Color piece_color;
    int x;
    int y;
    
    
    public:

////////////////////////////////////////////////////////////////    
    
    //default constructor
     Cell (){
        
     }

    //constructor    
    Cell(Piece_type p,Color piece_color,int x,int y){
        
        this->set_piece(p); 
        this->set_pos_x(x);
        this->set_pos_y(y);
        this->set_color(piece_color);
        
    }

        Cell(Piece_type p,Color piece_color){
        
        this->set_piece(p); 
        this->set_pos_x(0);
        this->set_pos_y(0);
        this->set_color(piece_color);
        
    }

   // //destructor
   // ~Cell(){
   //     
   // }
       
////////////////////////////////////////////////////////////////

    //setter of cell as per need  -> we can call setter anywhere but constructor is called when initialzing only
     void set_cell(Piece_type p,Color piece_color,int x,int y){
        this->set_piece(p); 
        this->set_pos_x(x);
        this->set_pos_y(y);
        this->set_color(piece_color);
        
    }

///////////////////////////////////////////////////////////////  
 
    //getter of x 
    int get_pos_x(){
        return this->x;
    }

    //setter of x
    void set_pos_x(int x){
        this->x=x;
    }

////////////////////////////////////////////////////////////////
    //getter of y
    int get_pos_y(){
        return this->y;
    }

    //setter of y
    void set_pos_y(int y){
        this->y=y;
    }
////////////////////////////////////////////////////////////////
    //setter of piece
     void set_piece(Piece_type p){
        this->piece=p;
    }

    //getter of piece
    Piece_type get_piece(){
        return this->piece;
    }

////////////////////////////////////////////////////////////////    

    //setter of piece_color
    void set_color(Color piece_color){
        this->piece_color=piece_color;
    }

    //getter of piece_color
    Color get_color(){
        return this->piece_color;
    }

////////////////////////////////////////////////////////////////  
    


////////////////////////////////////////////////////////////////    

};

#endif
    
  