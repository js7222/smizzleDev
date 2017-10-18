
#include "validator.h"

#include <array>
#include <iostream>

namespace
{
}

std::vector<std::vector<char>> solve(const std::vector<std::vector<char>>& matrix)
{
    

}

std::array<size_t, SUB_DIMENSION-1> otherRowColumns(size_t arg)
{
    std::array<size_t, SUB_DIMENSION-1> values;
    size_t square = arg/SUB_DIMENSION;
    size_t posInSquare = arg%SUB_DIMENSION;
    for (size_t i = 0; i!=SUB_DIMENSION; ++i)
    {
	size_t current = square*SUB_DIMENSION+i;
	if (posInSquare != current % SUB_DIMENSION)
	{
	    values[i]=current;
	}
	
    }
    return values;

}

bool isValid(const std::vector<std::vector<char>>& matrix)
{
    std::array<bool,DIMENSION> buf;

    for (int j=0; j!=DIMENSION; ++j)
    {
	buf.fill(false);
	for (int i=0; i!=DIMENSION; ++i)
	{
	    std::cout << matrix[j][i] << ",";
	    int value = matrix[j][i] - '1';
	    if (value >=0 && value <DIMENSION)
	    {

		if (buf[value])
		{
		    
		    return false;
		}
		buf[value] = true;
	    }
	}
	std::cout << std::endl;
    }
    
    for (int i=0; i!=DIMENSION; ++i)
    {
	buf.fill(false);
	for (int j=0; j!=DIMENSION; ++j)
	{
	    int value = matrix[j][i] - '1';
	    if (value >=0 && value <DIMENSION)
	    {
		if (buf[value])
		{
		    return false;
		}
		buf[value] = true;
	    }

	}

    }


    for (int l=0; l!=DIMENSION; l+=SUB_DIMENSION)
    {
	for (int k=0; k!=DIMENSION; k+=SUB_DIMENSION)
	{
	    buf.fill(false);
	    for (int i=0; i!=SUB_DIMENSION; ++i)
	    {
		for (int j=0; j!=SUB_DIMENSION; ++j)
		{
		    int value = matrix[j+l][i+k] - '1';
		    if (value >=0 && value <DIMENSION)
		    {
			if (buf[value])
			{
			    return false;
			}
			buf[value] = true;
		    }

		}
	    }

	}
    }
    
    return true;
}
