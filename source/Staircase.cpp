#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

#include "prints.h"

inline unsigned long long calc_staircase(int boxWidth, int boxHeight, unsigned long long prevBoxHeight, int* stairs, int numStairs){
   unsigned long long bottom = prevBoxHeight;
   int stair = (boxWidth > numStairs) ? numStairs - 1 : boxWidth - 1;
   bottom = (bottom < static_cast<unsigned long long>(stairs[stair])) ? static_cast<unsigned long long>(stairs[stair]) : bottom;
   return bottom;
}

void staircase_solve(std::istream& in, std::ostream& out){
   // turn off synchronization with C I/O
   std::ios_base::sync_with_stdio(false);
   
   std::string line;
   int numStairs;
   in >> numStairs;
   std::getline(in, line);
   int stairs[100000];
   std::getline(in, line);
   std::stringstream stairin(line);
   for(int i = 0; i < numStairs; ++i){
      stairin >> stairs[i];
   }

   int numBoxes;
   in >> numBoxes;
   std::getline(in, line);
   unsigned long long bottom = 0;
   for(int i = 0; i < numBoxes; ++i){
      int w, h;
      in >> w >> h;
      bottom = calc_staircase(w, h, bottom, stairs, numStairs);
      out << bottom << std::endl;
      bottom += h;
   }
}
