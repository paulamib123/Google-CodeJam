#include <iostream>
#include <vector>
using namespace std;

int maxSumWithCornerKElements(vector<int> arr, int k)
{
    int currentSum = 0;
    int maxSum = 0;
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        currentSum += arr[i];
    }
    cout << "Current Sum is: " << currentSum << endl;

    for (int i = n - 1; i >= n - k; i--)
    {
        currentSum = currentSum + arr[i] - arr[i - (n - k)];
        cout << "Current Sum is: " << currentSum << endl;
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr;

    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(12);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(9);

    cout << maxSumWithCornerKElements(arr, 3) << endl;
}