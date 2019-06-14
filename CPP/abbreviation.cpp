/**
 * You can perform the following operations on the string, :
 * 
 * Capitalize zero or more of 's lowercase letters.
 * Delete all of the remaining lowercase letters in .
 * Given two strings, a and b,
 * determine if it's possible to make equal to as described.
 * If so, print YES on a new line. Otherwise, print NO.
 */
#include <iostream>
#include <string>
#include <vector>

std::string abbreviation(std::string a, std::string b);

int main()
{
    std::string a = "daBcd";
    std::string b = "ABC";
    std::cout << abbreviation(a, b) << '\n';
    return 0;
}

std::string abbreviation(std::string a, std::string b)
{
    // To store if we can move ahead from our current position
    // dp[i][j] tells if it's a valid state to move ahead
    std::vector<std::vector<bool>> dp(a.size() + 1, std::vector<bool>(b.size() + 1, false));

    dp[0][0] = true;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            if (dp[i][j])
            {
                // Either the character is upper case or we can make it upper case
                // To match with character in 'b'
                if (j < b.length() && toupper(a[i]) == b[j])
                {
                    dp[i + 1][j + 1] = true;
                }

                // If it's in lower case, we can remove it
                if (islower(a[i]))
                {
                    dp[i + 1][j] = true;
                }
            }
        }
    }

    if (dp[a.length()][b.length()])
    {
        return "YES";
    }
    return "NO";
}