#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

#include "gtest/gtest.h"

#include "prints.h"
#include "Staircase.h"


TEST(Staircase, calc_staircase){
   int stairs[] = {1, 2, 3, 6, 6};
   int boxWidth = 1;
   int boxHeight = 1;
   int prevBoxHeight = 0;
   int bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 5);
   ASSERT_EQ(1, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 3;
   boxHeight = 1;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 5);
   ASSERT_EQ(3, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 1;
   boxHeight = 1;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 5);
   ASSERT_EQ(4, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 4;
   boxHeight = 3;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 5);
   ASSERT_EQ(6, bottom);
}

TEST(Staircase, calc_staircase_2){
   int stairs[] = {1, 2, 3};
   int boxWidth = 1;
   int boxHeight = 1;
   int prevBoxHeight = 0;
   int bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 3);
   ASSERT_EQ(1, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 3;
   boxHeight = 1;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 5);
   ASSERT_EQ(3, bottom);
}

TEST(Staircase, calc_staircase_3){
   int stairs[] = {1};
   int boxWidth = 1;
   int boxHeight = 2;
   int prevBoxHeight = 0;
   int bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 1);
   ASSERT_EQ(1, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 1;
   boxHeight = 10;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 1);
   ASSERT_EQ(3, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 1;
   boxHeight = 10;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 1);
   ASSERT_EQ(13, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 1;
   boxHeight = 10;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 1);
   ASSERT_EQ(23, bottom);

   prevBoxHeight = bottom + boxHeight;
   boxWidth = 1;
   boxHeight = 10;
   bottom = calc_staircase(boxWidth, boxHeight, prevBoxHeight, stairs, 1);
   ASSERT_EQ(33, bottom);
}

TEST(Staircase, staircase_solve){
   std::stringstream r(
"5\n"
"1 2 3 6 6\n"
"4\n"
"1 1\n"
"3 1\n"
"1 1\n"
"4 3\n"
);
   std::stringstream w;
   staircase_solve(r, w);
   ASSERT_EQ(
"1\n"
"3\n"
"4\n"
"6\n", w.str());
}

TEST(Staircase, staircase_solve_2){
   std::stringstream r;
   r << "1\n1000000000\n40\n";
   for(int i = 0; i < 40; ++i){
      r << "1 1000000000\n";
   }
   std::stringstream w;
   staircase_solve(r, w);
   std::stringstream expected;
   unsigned long long num = 1000000000;
   for(int i = 0; i < 40; ++i){
      expected << num << std::endl;
      num += 1000000000;
   }
   ASSERT_EQ(expected.str(), w.str());
}

