#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int impartialOffering(vector<int> arr, int n) 
{
    int ans = 0;
    unordered_map<int, int> count;
    unordered_set<int> unique;

    for (int ele: arr) {
        count[ele]++;
        unique.insert(ele);
    }

    vector<int> v(unique.begin(), unique.end());
    sort(v.begin(), v.end());

    for (auto ele: count) {
        int treat = find(v.begin(), v.end(), ele.first) - v.begin();
        //cout << treat << " * " << ele.second << endl;
        ans += treat * ele.second;
    }

    return ans;
}

int main(){
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int ele;
        for (int i = 0; i < n; i++) {
            cin >> ele;
            arr.push_back(ele);
        }
        int result;
        result = impartialOffering(arr, n);
        cout << "Case #" << c << ": " << result << endl;
    }
}
