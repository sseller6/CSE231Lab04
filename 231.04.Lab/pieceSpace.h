/***********************************************************************
 * Header File:
 *    SPACE
 * Author:
 *    <your name here> 
 * Summary:
 *    The space
 ************************************************************************/

#pragma once

#include "piece.h"

class TestSpace;

 /***************************************************
  * SPACES
  * A space is a trivial piece
  ***************************************************/
class Space : public Piece
{
   friend TestSpace;
public:
   Space(int c, int r) : Piece(9, 9)   {               }
   ~Space()                            {               }
   PieceType getType()           const { return ROOK;  }
   void display(ogstream* pgout) const {               }
};