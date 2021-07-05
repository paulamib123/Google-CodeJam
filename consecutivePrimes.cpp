#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

int consecutivePrimes(int n) {
    int ans = -1;
    vector<int> primes;

    for (int i = 0; i < n; i++) {
        if (isPrime(i)) 
            primes.push_back(i);
    }

    for (int i = 0; i < primes.size() - 1; i++) {
           int product = 1;
           product = primes[i] * primes[i + 1];
           if (product <= n) {
               ans = max(ans, product);
           }
           
    }
    return ans;
}


int main(){
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        int result;
        cin >> n;
        result = consecutivePrimes(n);
        cout << "Case #" << c << ": " << result << endl;
    }
}