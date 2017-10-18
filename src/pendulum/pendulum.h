
#ifndef PENDULUM_H
#define PENDULUM_H

template <typename Iter>
Iter partition(Iter begin, Iter end)
{
    return begin;
}

template <typename Iter>
void quicksort(Iter begin, Iter end)
{
    auto p = partition(begin, end);
    quicksort(begin, p);
    quicksort(p+1,end);
}

void testSwap();


#endif //PENDULUM_H
