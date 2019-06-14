/**
 * Alice is a kindergarten teacher. She wants to give some candies to the children in her class.
 * All the children sit in a line and each of them has a rating score according to his or her performance in the class.
 * Alice wants to give at least 1 candy to each child. If two children sit next to each other,
 * then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.
 *
 * For example, assume her students' ratings are [4, 6, 4, 5, 6, 2].
 * She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1].
 * She must buy a minimum of 10 candies.
 */

#include <iostream>
#include <vector>

long candies(int n, std::vector<int> arr);

int main()
{
    int n = 10;
    std::vector<int> arr = {2, 4, 2, 6, 1, 7, 8, 9, 2, 1};
    std::cout << candies(n, arr) << '\n';
    return 0;
}

long candies(int n, std::vector<int> arr)
{
    std::vector<int> dp(n);
    dp[0] = 1;

    // Go forward
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }

    // Go backward
    for (int j = n - 2; j >= 0; j--)
    {
        if (arr[j] > arr[j + 1])
        {
            dp[j] = std::max(dp[j], dp[j + 1] + 1);
        }
    }

    long sum = 0;
    for (auto val : dp)
    {
        sum += static_cast<long>(val);
    }
    return sum;
}