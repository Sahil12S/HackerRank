/*
 * You'll be given an array of integers and you have to print the integers in the reverse order.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n / 2; i++)
    {
        std::swap(arr[i], arr[n - 1 - i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }

    cout << arr[n - 1] << endl;
    return 0;
}