/***********************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
   : promote(INVALID),
     capture(INVALID),
     moveType(MOVE_ERROR),
     isWhite(false)
{
}

/***************************************************
 * MOVE : NON-DEFAULT CONSTRUCTOR (move)
 ***************************************************/
Move::Move(const char* input)
{
   assignMove(input);
   isWhite = false;
}

/***************************************************
 * MOVE : ASSIGN A MOVE
 ***************************************************/
void Move::assignMove(const char * input)
{
   char s_char[3] = {input[0], input[1], '\0'};
   source = Position(s_char);
   
   char d_char[3] = {input[2], input[3], '\0'};
   dest = Position(d_char);
   
   promote = SPACE;
   switch (input[4])
   {
   case 'c':
      moveType = CASTLE_KING;
      capture = SPACE;
      break;
   case 'C':
      moveType = CASTLE_QUEEN;
      capture = SPACE;
      break;
   case 'E':
      moveType = ENPASSANT;
      capture = PAWN;
      break;
   case 'q':
      moveType = MOVE;
      capture = QUEEN;
      break;
   case 'b':
      moveType = MOVE;
      capture = BISHOP;
      break;
   case 'n':
      moveType = MOVE;
      capture = KNIGHT;
      break;
   case 'r':
      moveType = MOVE;
      capture = ROOK;
      break;
   case 'p':
      moveType = MOVE;
      capture = PAWN;
      break;
   default:
      moveType = MOVE;
      capture = SPACE;
   }
   text = (string)input;
}

/***************************************************
 * MOVE : LETTER FROM PIECE TYPE
 ***************************************************/
Move::Move(const Position source, const Position destination, const MoveType moveType, const PieceType capture)
{
   this->source = source;
   dest = destination;
   this->moveType = moveType;
   this->capture = capture;
   
   promote = SPACE;
   isWhite = false;
   
   // ASCII for lowercase -> 97-122
   // ASCII for numbers   -> 48-55
   char colSrc = source.getCol() + 97;
   char rowSrc = source.getRow() + 49;
   char colDst = destination.getCol() + 97;
   char rowDst = destination.getRow() + 49;
   
   char suffix = 'i';
   
   switch (moveType)
   {
   case ENPASSANT:
      suffix = 'E';
      break;
   case CASTLE_KING:
      suffix = 'c';
      break;
   case CASTLE_QUEEN:
      suffix = 'C';
      break;
   default:
      switch (capture)
      {
         case QUEEN:
            suffix = 'q';
            break;
         case ROOK:
            suffix = 'r';
            break;
         case BISHOP:
            suffix = 'b';
            break;
         case KNIGHT:
            suffix = 'n';
            break;
         case PAWN:
            suffix = 'p';
            break;
      }
   }
   
   if (suffix != 'i')
      text = {colSrc, rowSrc, colDst, rowDst, suffix};
   else
      text = {colSrc, rowSrc, colDst, rowDst};
}

/***************************************************
 * MOVE : OPERATOR<
 ***************************************************/
bool Move::operator< (const Move &rhs) const
{
   return this->dest.getLocation() < rhs.dest.getLocation();
}

/***************************************************
 * MOVE : LETTER FROM PIECE TYPE
 ***************************************************/
char Move::letterFromPieceType(PieceType pt) const
{
   char letter;
   switch (pt)
   {
   case INVALID:
      letter = 'i';
      break;
   case SPACE:
      letter = ' ';
      break;
   case KING:
      letter = 'k';
      break;
   case QUEEN:
      letter = 'q';
      break;
   case ROOK:
      letter = 'r';
      break;
   case BISHOP:
      letter = 'b';
      break;
   case KNIGHT:
      letter = 'n';
      break;
   case PAWN:
      letter = 'p';
      break;
   }
   return letter;
}

/***************************************************
 * MOVE : PIECE TYPE FROM LETTER
 ***************************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{
   PieceType pt;
   switch (letter)
   {
   case 'i':
      pt = INVALID;
      break;
   case ' ':
      pt = SPACE;
      break;
   case 'k':
      pt = KING;
      break;
   case 'q':
      pt = QUEEN;
      break;
   case 'r':
      pt = ROOK;
      break;
   case 'b':
      pt = BISHOP;
      break;
   case 'n':
      pt = KNIGHT;
      break;
   case 'p':
      pt = PAWN;
      break;
   default:
      pt = INVALID;
   }
   return pt;
}
