#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <stdio.h>
#include <inttypes.h>

inline int64_t calc_staircase(int boxWidth, int boxHeight, int64_t prevBoxHeight, int* stairs, int numStairs){
   int64_t bottom = prevBoxHeight;
   int stair = (boxWidth > numStairs) ? numStairs - 1 : boxWidth - 1;
   bottom = (bottom < static_cast<int64_t>(stairs[stair])) ? static_cast<int64_t>(stairs[stair]) : bottom;
   return bottom;
}

void staircase_solve_cpp(std::istream& in, std::ostream& out){
   //turn off synchronization with C I/O
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

   int64_t bottom = 0;
   for(int i = 0; i < numBoxes; ++i){
      int w, h;
      in >> w >> h;
      bottom = calc_staircase(w, h, bottom, stairs, numStairs);
      out << bottom << "\n";
      bottom += h;
   }
}

void staircase_solve(std::istream& in, std::ostream& out){
   int numStairs;
   scanf("%d", &numStairs);

   int stairs[100000];
   for(int i = 0; i < numStairs; ++i){
      scanf("%d", &stairs[i]);
   }

   int numBoxes;
   scanf("%d", &numBoxes);

   int64_t bottom = 0;
   for(int i = 0; i < numBoxes; ++i){
      int w, h;
      scanf("%d %d", &w, &h);
      bottom = calc_staircase(w, h, bottom, stairs, numStairs);
      printf("%ld\n", bottom);
      bottom += h;
   }
}
