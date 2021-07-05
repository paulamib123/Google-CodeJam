#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int goodnessScore(int n, string s, int score)
{
    int good = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            good++;
        }
    }
    if (good == score)
        return 0;
    return abs(good - score);
}

int main()
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int res;
        res = goodnessScore(n, s, k);
        cout << "Case #" << c << ": " << res << endl;
    }
    cout << -7 % 2;
}
