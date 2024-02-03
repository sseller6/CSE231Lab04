/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   Delta possibleMoves[8] = {
                {-1,  2}, { 1,  2},
      {-2,  1},                    { 2,  1},
      
      {-2, -1},                    { 2, -1},
                {-1, -2}, { 1, -2}
   };
   for (int i = 0; i < 8; i++)
   {
      Delta d = possibleMoves[i];
      // Cannot move there if it's off the board
      Position dest = this->position + d;
      if (0 < dest.getCol() || dest.getCol() < 7)
      {
         if (0 < dest.getRow() || dest.getRow() < 7)
         {
            // or occupied by a pawn of same team
            if (board[dest].isWhite() != this->isWhite())
            {
               bool isCapture = board[dest].getType() != SPACE;
               Move move;
               moves.insert(Move(this->position,
                                 dest,
                                 move.MOVE,
                                 isCapture ? board[dest].getType() : SPACE));
            }
         }
      }
   }
}
