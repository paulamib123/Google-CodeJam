#include <iostream>
using namespace std;

string incresingSubstring(string s, int n) { //ABBC
    int count = 1;
    string ans = "1 ";

    for (int i = 1; i < n; i++) {
       if (s[i - 1] < s[i]) {
           count++;
        } else {
           count = 1;
        }

       ans += to_string(count) + " ";
    }
    ans.pop_back();
    return ans;
}

int main(){
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string result;
        result = incresingSubstring(s, n);
        cout << "Case #" << c << ": " << result << endl;
    }
}