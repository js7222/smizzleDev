// File: mytest.cpp

#include <numeric>
#include <array>

#include "gtest/gtest.h"


#include <pendulum/pendulum.h>
#include <sudoku/validator.h>

TEST(Pendulum, swap)
{
    std::vector<uint32_t> nums{1,2,3,4,5,6};
    //quicksort(std::begin(nums), std::end(nums));

    testSwap();
}

TEST(Sudoku, validator)
{
    std::vector<std::vector<char>> values =
	{{{'.','.','.','.','.','.','.','.','.'},
	  {'.','.','.','3','.','.','5','.','.'},
	  {'.','.','.','.','.','.','.','.','.'},
	  {'.','.','.','8','.','.','.','.','.'},
	  {'.','.','.','.','2','1','6','.','.'},
	  {'.','.','.','.','.','.','.','.','.'},
	  {'.','.','.','.','.','.','1','.','.'},
	  {'.','.','.','.','.','.','.','.','7'},
	  {'.','.','.','.','.','.','.','4','.'}}};

    ASSERT_TRUE(isValid(values));

}

TEST(Sudoku,otherColumnRow)
{
    std::array<size_t,2> expected = {{0,1}};
    ASSERT_EQ(otherRowColumns(2),expected);
}

TEST(Sudoku, solver)
{
    std::vector<std::vector<char>> values =
	{{{'5','3','.','.','7','.','.','.','.'},
	  {'6','.','.','1','9','5','.','.','.'},
	  {'.','9','8','.','.','.','.','6','.'},
	  {'8','.','.','.','6','.','.','.','3'},
	  {'4','.','.','8','.','3','.','.','1'},
	  {'7','.','.','.','2','.','.','.','6'},
	  {'.','6','.','.','.','.','2','8','.'},
	  {'.','.','.','4','1','9','.','.','5'},
	  {'.','.','.','.','8','.','.','7','9'}}};

    
}
