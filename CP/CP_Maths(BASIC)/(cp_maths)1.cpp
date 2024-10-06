//FIND THE NUMBER OF THE DIVISIOR

//Time complexity is sqrt(n)
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int div = 0;
    for (int i = 1; i * i <= n; i++) // all the divisor of a number is equally distributed across the srt(n) of the n ;
    {
        if (n % i == 0)
        {
            div++;
            if (i != n / i) // const time complexity
            {
                div++;
            }
        }
    }
    cout << "No Of Divisor::" << div << "\n";
    if (div == 2)
    {
        cout << n << "is prime no" << "\n";
    }
    else
        cout << "composite No " << "\n";

    return 0;
}

// NO OF THE DIVISORS FORM THE 1 to n
// time complexity is o(n sqrt(n))
#include <iostream>
using namespace std;
int countdivisior(int n)
{
    int div = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            div++;
            if (i != n / i)
            {
                div++;
            }
        }
    }
    return div;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int divisors = countdivisior(i);
        cout << "no of divisors of" << i << ": " << divisors << "\n";
    }
    return 0;
}

// 0(nlog(n))
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> divcount(n + 1, 0);
    for (int i = 1; i <= n; i++) // will count for given no -- how many of the numbers it is divisor of
    {
        for (int j = i; j <= n; j += i)
        {
            divcount[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << divcount[i] << "\n";
    }
    return 0;
}