#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int reversort(vector<int> &arr, int n)
{
    int minimumValIndex = 0;
    int minimumVal = 0;
    int cost = 0;

    for (int i = 0; i < n - 1; i++)
    {
        minimumValIndex = i;
        minimumVal = arr[i];
        for (int j = i; j < n; j++)
        {
            if (minimumVal > arr[j])
            {
                minimumVal = arr[j];
                minimumValIndex = j;
            }
        }

        cost += (minimumValIndex - i + 1);
        reverse(arr.begin() + i, arr.begin() + minimumValIndex + 1);
    }
    return cost;
}

int main()
{
    int t;
    cin >> t;

    for (int c = 1; c <= t; c++)
    {
        int n;
        cin >> n;
        int val;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            arr.push_back(val);
        }
        int result = reversort(arr, n);
        cout << "Case #" << c << ": " << result << endl;
    }
}