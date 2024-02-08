/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything that's not empty
   if (fFree)
      free();
   else
   {
      board[1][0] = new Knight(1, 0, false);
      board[6][0] = new Knight(6, 0, false);
      board[1][7] = new Knight(1, 7, true);
      board[6][7] = new Knight(6, 7, true);
      for (int r = 0; r < 8; r++)
      {
         for (int c = 0; c < 8; c++)
         {
            if (!board[c][r])
               board[c][r] = new Space(c, r);
         }
      }
      
   }
}

// we really REALLY need to delete this.
Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   return *board[pos.getCol()][pos.getRow()];
}
Piece& Board::operator [] (const Position& pos)
{
   return *board[pos.getCol()][pos.getRow()];
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   pgout->drawBoard();
   pgout->drawHover(posHover);
   pgout->drawSelected(posSelect);
   for (int r = 0; r < 8; r++)
   {
      for (int c = 0; c < 8; c++)
      {
         Piece * piece = board[c][r];
         switch (piece->getType())
         {
            case PAWN:
               pgout->drawPawn(Position(c, r), !piece->isWhite());
               break;
            case ROOK:
               pgout->drawRook(Position(c, r), !piece->isWhite());
               break;
            case KNIGHT:
               pgout->drawKnight(Position(c, r), !piece->isWhite());
               break;
            case BISHOP:
               pgout->drawBishop(Position(c, r), !piece->isWhite());
               break;
            case QUEEN:
               pgout->drawQueen(Position(c, r), !piece->isWhite());
               break;
            case KING:
               pgout->drawKing(Position(c, r), !piece->isWhite());
               break;
         }
      }
   }
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   if (noreset)
      free();
   else
      reset();
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   Position src = move.getSource();
   Position des = move.getDestination();
   
   int srcCol = src.getCol();
   int srcRow = src.getRow();
   int desCol = des.getCol();
   int desRow = des.getRow();
   
   Piece * pieceMove = board[srcCol][srcRow];
   Piece * pieceDest = board[desCol][desRow];
   
   // If only move
   if (move.getMoveType() == move.MOVE && !move.isCapture())
   {
      board[desCol][desRow] = pieceMove;
      board[srcCol][srcRow] = pieceDest;
   }
   
   // If capture
   else if (move.isCapture())
   {
      Piece * replace = new Space(srcCol, srcRow);
      board[desCol][desRow] = pieceMove;
      board[srcCol][srcRow] = replace;
   }
   
   numMoves++;
   
   // TODO: write ENPASSANT and PROMOTE
}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}
