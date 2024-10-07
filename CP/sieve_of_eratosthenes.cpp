// SIEVE OF ERATOSTHENES

// For efficient prime number generation in O(nlog(logn)).

#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 1; i <= n; i++)
    {
        if (!isprime[i])
            continue;
        // if prime
        for (int j = i + i; j <= n; j += i)
        {
            isprime[j] = false;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << isprime[i] << "\n";
    }

    return 0;
}