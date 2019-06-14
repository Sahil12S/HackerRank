/**
 * Given an array of integers,
 * find the subset of non-adjacent elements with the maximum sum.
 * Calculate the sum of that subset.
 */

#include <iostream>
#include <vector>

int maxSubsetSum(std::vector<int> arr);

int main()
{
    std::vector<int> arr = {3, 7, 4, 6, 5};
    std::cout << maxSubsetSum(arr) << '\n';
    return 0;
}

int maxSubsetSum(std::vector<int> arr)
{
    if (arr.size() == 0)
    {
        return 0;
    }
    std::vector<int> dp(arr.size());
    dp[0] = std::max(0, arr[0]);
    if (arr.size() == 1)
    {
        return dp[0];
    }

    dp[1] = std::max(dp[0], arr[1]);

    for (int i = 2; i < arr.size(); i++)
    {
        dp[i] = std::max(arr[i], arr[i] + dp[i - 2]);
        dp[i] = std::max(dp[i], dp[i - 1]);
    }
    return dp[arr.size() - 1];
}