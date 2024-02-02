/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;

/************************************************
 * PIECE : NON-DEFAULT CONSTRUCTORS
 ***********************************************/
Piece::Piece(const Position& pos, bool isWhite)
{
	position = pos;
	fWhite = isWhite;

	nMoves = 0;
	lastMove = 0;
}

Piece::Piece(int c, int r, bool isWhite)
{
	position = Position(c, r);
	fWhite = isWhite;

	nMoves = 0;
	lastMove = 0;
}

Piece::Piece(const Piece& piece)
{
	nMoves = piece.nMoves;
	fWhite = piece.fWhite;
	position = piece.position;
	lastMove = piece.lastMove;
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{

   return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

