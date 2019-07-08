/**
 * Question description:
 * 
 * https://www.hackerrank.com/challenges/grid-challenge/problem
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VS = std::vector<std::string>;
using VVS = std::vector<VS>;

std::string gridChallenge(VS &grid);

int main()
{
    VS grid = {"ebacd", "fghij", "olmkn", "trpqs", "xywuv"};
    std::cout << gridChallenge(grid) << '\n';
    return 0;
}

std::string gridChallenge(VS &grid)
{
    int n = grid.size();
    std::sort(std::begin(grid[0]), std::end(grid[0]));
    FORI(1, n)
    {
        std::sort(std::begin(grid[i]), std::end(grid[i]));
        FORJ(0, n)
        {
            if (grid[i - 1][j] > grid[i][j])
            {
                return "NO";
            }
        }
    }
    return "YES";
}