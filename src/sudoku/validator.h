#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>
#include <array>

const size_t DIMENSION = 9;
const size_t SUB_DIMENSION = 3;

bool isValid(const std::vector<std::vector<char>>& matrix);
std::array<size_t, SUB_DIMENSION-1> otherRowColumns(size_t arg);

#endif //VALIDATOR_H
