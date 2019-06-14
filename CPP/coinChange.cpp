/**
 * You are working at the cash counter at a fun-fair,
 * and you have different types of coins available to you in infinite quantities.
 * The value of each coin is already given.
 * Can you determine the number of ways of making change for
 * a particular number of units using the given types of coins?
 */

#include <vector>
#include <iostream>

long getWays(long n, std::vector<long> c);

int main()
{
    long n = 10;
    std::vector<long> c = {2, 5, 3, 6};
    std::cout << getWays(n, c) << '\n';
    return 0;
}

long getWays(long n, std::vector<long> c)
{
    // sort(c.begin(), c.end());
    std::vector<long> num_coins(n + 1, 0);
    num_coins[0] = 1;

    for (long coin : c)
    {
        for (long i = coin; i <= n; i++)
        {
            num_coins[i] += num_coins[i - coin];
        }
    }
    return num_coins[n];
}