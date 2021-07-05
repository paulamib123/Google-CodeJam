#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int moonsAndUmbrellas(string s, int x, int y)
{
    char nearest;
    int cost = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '?')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == 'C' || s[j] == 'J')
                {
                    nearest = s[j];
                    break;
                }
            }
            s[i] = nearest;
        }
    }
    if (s[0] == '?')
        s[0] = s[1];

    cout << "String now is: " << s << endl;

    for (int i = 0; i < s.size() - 1; i++)
    {
        string set = "";
        set = set + s[i] + s[i + 1];
        cout << set << " ";
        if (set == "CJ")
            cost += x;
        if (set == "JC")
            cost += y;
    }

    cout << endl;

    return cost;
}

int main()
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int result;
        result = moonsAndUmbrellas(s, x, y);
        cout << "Case #" << c << ": " << result << endl;
    }
}