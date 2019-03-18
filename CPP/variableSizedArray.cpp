/*
    Question link: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    int q;
    cin >> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (x > 0)
        {
            int t;
            cin >> t;
            vec[i].push_back(t);
            x--;
        }
    }
    for (int j = 0; j < q; j++)
    {
        int l, m;
        cin >> l;
        cin >> m;
        cout << vec[l][m] << endl;
    }
    // cout << x << endl;
    return 0;
}