/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // Default Constructor
   Move();

   // We can work with a single input
   Move(const char* input);
   void assignMove(const char * input);
   
   // Or we can take in separate values
   Move(const Position source, const Position destination, const MoveType moveType=MOVE, const PieceType capture=SPACE);
   
   // Getters
   Position getSource() const { return source.getLocation(); }
   Position getDestination() const { return dest.getLocation(); }
   PieceType getPromote() const { return promote; }
   PieceType getCapture() const { return capture; }
   MoveType getMoveType() const { return moveType; }
   bool getIsWhite() const { return isWhite; }
   string getText() const { return text; }
   
   bool isCapture() const { return capture != SPACE && capture != INVALID; }
   
   bool operator< (const Move& rhs) const;

private:
   char letterFromPieceType(PieceType pt) const;
   PieceType pieceTypeFromLetter(char letter) const;



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


