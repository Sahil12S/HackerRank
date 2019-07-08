/**
 * Question description:
 * 
 * https://www.hackerrank.com/challenges/marcs-cakewalk/problem
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;

long marcsCakeWalk(VI &calorie);

int main()
{
    // VI calorie = {7, 4, 9, 6}; // 79
    VI calorie = {1, 3, 2}; // 11
    std::cout << marcsCakeWalk(calorie) << '\n';
    return 0;
}

long marcsCakeWalk(VI &calorie)
{
    if (calorie.empty())
    {
        return 0;
    }
    std::sort(std::begin(calorie), std::end(calorie), std::greater<int>());

    long distance = 0;

    long powOfTwo = 1;

    for (auto cal : calorie)
    {
        distance += static_cast<long>(powOfTwo) * static_cast<long>(cal);
        powOfTwo *= 2;
    }

    return distance;
}