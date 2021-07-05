#include <iostream>
#include <string>
using namespace std;

int irefutableOutcome(string s, char player) 
{
    int n = s.size();

    if (n == 0) return 0;

    if (n == 1) {
        int res = (player == s[0]) ? -1 : 2;
        return res;
    }

    if (s[0] == s[n - 1] && s[0] != player) return 1 + n;

    char nextPlayer = (player == 'I') ? 'O' : 'I';

    if (s[0] == s[n - 1] && s[0] == player) 
        return -max(irefutableOutcome(s.substr(1), nextPlayer), irefutableOutcome(s.substr(0, n - 1), nextPlayer));
    else if (s[0] == player)
        return -irefutableOutcome(s.substr(1), nextPlayer);
    else if (s[n - 1] == player)
        return -irefutableOutcome(s.substr(0, n - 1), nextPlayer);
}

int main(){
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        string s;
        cin >> s;
        string result;
        int ans = irefutableOutcome(s, 'I');
        if (ans < 0) {
            result = "I " + to_string(abs(ans));
        } else {
            result = "O " + to_string(ans); 
        }
        cout << "Case #" << c << ": " << result << endl;
    }
}