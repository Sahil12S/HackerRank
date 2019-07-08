/**
 * Question description:
 * 
 * https://www.hackerrank.com/challenges/luck-balance/problem
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int luckBalance(int k, VVI &contests);

int main()
{
    VVI contests = {{5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0}};
    int k = 3;
    std::cout << '\n'
              << luckBalance(k, contests) << '\n';
    return 0;
}

int luckBalance(int k, VVI &contests)
{
    std::priority_queue<int, VI, std::greater<int>> pq;

    int totalLuck = 0;

    for (auto detail : contests)
    {
        if (detail[1])
        {
            if (k != 0 && pq.size() == k && detail[0] > pq.top())
            {
                totalLuck -= 2 * pq.top();
                pq.pop();
                totalLuck += detail[0];
                pq.push(detail[0]);
            }
            else if (pq.size() < k)
            {
                pq.push(detail[0]);
                totalLuck += detail[0];
            }
            else
            {
                totalLuck -= detail[0];
            }
        }
        else
        {
            totalLuck += detail[0];
        }
    }
    return totalLuck;
}