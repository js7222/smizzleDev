
#include <forward.h>
#include <utility>
#include <iostream>
#include <vector>

class ForwardTest {
    
};

void callForwardTest(const std::vector<ForwardTest>&)
{
    std::cout << "callForwardTest(const std::vector<ForwardTest>&)" << std::endl;
}


void callForwardTest(std::vector<ForwardTest>&)
{
    std::cout << "callForwardTest(std::vector<ForwardTest>&)" << std::endl;
}

void callForwardTest(std::vector<ForwardTest>&&)
{
    std::cout << "callForwardTest(std::vector<ForwardTest>&&)" << std::endl;
}

void callForwardTest(const std::vector<ForwardTest>&&)
{
    std::cout << "callForwardTest(const std::vector<ForwardTest>&&)" << std::endl;
}


void runAll()
{
    callForwardTest(std::vector<ForwardTest>());
    std::vector<ForwardTest> forwardTest;
    callForwardTest(std::forward<std::vector<ForwardTest>>(forwardTest));
    callForwardTest(forwardTest);
    const std::vector<ForwardTest> constForwardTest;
    callForwardTest(constForwardTest);
}
