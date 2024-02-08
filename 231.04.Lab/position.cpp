/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <cstring>
#include <iostream>

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   return in;
}


// POSITION CORE
int Position::getCol() const
{
   if (isInvalid())
   {
      return -1;
   }
   int col = (int)colRow / 16;
   return col;
}

int Position::getRow() const
{
   if (isInvalid())
   {
      return -1;
   }
   int row = (int)colRow % 16;
   return row;
}

bool Position::isInvalid() const
{
   int col = (int)colRow / 16;
   int row = (int)colRow % 16;
   if (0 > col || col > 7 || 0 > row || row > 7)
      return true;
   return false;
}

bool Position::isValid() const
{
   int col = (int)colRow / 16;
   int row = (int)colRow % 16;
   if (0 <= col && col <= 7 && 0 <= row && row <= 7)
      return true;
   return false;
}

int Position::getLocation() const
{
   // Row is given by 0xf0. Col is given by 0x0f
   return (colRow % 16) * 8 + (colRow / 16);
}

void Position::setRow(int r)
{
   int col = colRow / 16;
   colRow = (uint8_t)(col * 16 + r);
}

void Position::setCol(int c)
{
   int row = colRow % 16;
   colRow = (uint8_t)(c * 16 + row);
}

void Position::set(int c, int r)
{
   colRow = (uint8_t)(c * 16 + r);
}

void Position::setLocation(int location)
{
   int col = location % 8;
   int row = location / 8;
   colRow = (uint8_t)(col * 16 + row);
}

// POSITION PIXELS
void Position::setXY(double x, double y)
{
   // TODO: is this where we worry about border resizing?
   
   // Fix y according to flippage
   double flipped_y = (8.0 * squareHeight + 2.0 * OFFSET_BOARD) - y;
   
   // Fix x and y according to border offset
   double real_x =         x - OFFSET_BOARD;
   double real_y = flipped_y - OFFSET_BOARD;
   
   // Scale back down to col and row
   int fix_x = real_x / squareWidth;
   int fix_y = real_y / squareHeight;
   
   // Set according to fixed values
   set(fix_x, fix_y);
}


// POSITION TEXT
Position::Position(const char * s)
{
   if ((s[0] < 'A' || s[0] > 'H') && (s[0] < 'a' || s[0] > 'h'))
      setInvalid();
   else if (s[1] < '1' || s[1] > '8')
      setInvalid();
   else
      set(s[0] - 'a', s[1] - '1');
//   int col = 16;
//   int row = 16;
//   char first = s[0];
//   char second = s[1];
//   // ASCII numbers: 48-55
//   int zeroChar = '0';
//   int sevenChar = '7';
//   // ASCII lowercase: 97-122 UPPERCASE: 65-90
//   if ((first >= 97 && first <= 104) || (first >= 65 && first <= 72))        // first is a valid letter
//   {
//      if (first >= 97)
//         first -= 32;
//      col = first - 65;
//      if (second >= zeroChar && second <= sevenChar)                                      // second is a valid number
//         row = second - (zeroChar + 1); // row starts at 1 visually
//   }
//   else if (first >= zeroChar && first <= sevenChar)                                      // first is a valid number
//   {
//      row = first - (zeroChar + 1); // row starts at 1 visually
//      if ((second >= 97 && second <= 104) || (second >= 65 && second <= 72)) // second is a valid letter
//      {
//         if (second >= 97)
//            second -= 32;
//         col = second - 65;
//      }
//   }
//   colRow = (uint8_t)(col * 16 + row);
}

// TODO: make less redundant
const Position & Position::operator = (const char * rhs)
{
   int col = 16;
   int row = 16;
   char first = rhs[0];
   char second = rhs[1];
   // ASCII numbers: 48-55
   int zeroChar = '0';
   int sevenChar = '7';
   // ASCII lowercase: 97-122 UPPERCASE: 65-90
   if ((first >= 97 && first <= 104) || (first >= 65 && first <= 72))        // first is a valid letter
   {
      if (first >= 97)
         first -= 32;
      col = first - 65;
      if (second >= zeroChar && second <= sevenChar)                                      // second is a valid number
         row = second - (zeroChar + 1); // row starts at 1 visually
   }
   else if (first >= zeroChar && first <= sevenChar)                                      // first is a valid number
   {
      row = first - (zeroChar + 1); // row starts at 1 visually
      if ((second >= 97 && second <= 104) || (second >= 65 && second <= 72)) // second is a valid letter
      {
         if (second >= 97)
            second -= 32;
         col = second - 65;
      }
   }
   this->colRow = (uint8_t)(col * 16 + row);
   return *this;
}

const Position & Position::operator = (const string & rhs)
{
   const char* char_rhs = rhs.c_str();
   int col = 16;
   int row = 16;
   char first = char_rhs[0];
   char second = char_rhs[1];
   // ASCII numbers: 48-55
   int zeroChar = '0';
   int sevenChar = '7';
   // ASCII lowercase: 97-122 UPPERCASE: 65-90
   if ((first >= 97 && first <= 104) || (first >= 65 && first <= 72))        // first is a valid letter
   {
      if (first >= 97)
         first -= 32;
      col = first - 65;
      if (second >= zeroChar && second <= sevenChar)                                      // second is a valid number
         row = second - (zeroChar + 1); // row starts at 1 visually
   }
   else if (first >= zeroChar && first <= sevenChar)                                      // first is a valid number
   {
      row = first - (zeroChar + 1); // row starts at 1 visually
      if ((second >= 97 && second <= 104) || (second >= 65 && second <= 72)) // second is a valid letter
      {
         if (second >= 97)
            second -= 32;
         col = second - 65;
      }
   }
   this->colRow = (uint8_t)(col * 16 + row);
   return *this;
}

// POSITION MOVE
const Position & Position::operator += (const Delta & rhs)
{
   if (isValid())
   {
      int adjustC = rhs.dCol;
      int adjustR = rhs.dRow;
      this->colRow += (adjustC * 16 + adjustR);
   }
   if (isInvalid())
   {
      this->colRow = 0xff;
   }
   return *this;
}

Position Position::operator+ (const Delta & rhs) const
{
   return Position(getCol() + rhs.dCol, getRow() + rhs.dRow);
}
