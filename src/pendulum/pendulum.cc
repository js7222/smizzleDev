
#include <pendulum.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


void testSwap()
{
    std::vector<uint32_t> nums{1,2,3,4,5,6};
    std::iter_swap(nums.begin(), nums.begin()+4);

    std::copy(nums.begin(),nums.end(),std::ostream_iterator<uint32_t>(std::cout,","));

}


