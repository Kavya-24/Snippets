// exponent and power a^b

#include <iostream>
using namespace std;
int pow(int a, long long int b)
{
    if (b == 0)
    {
        return 1;
    }
    int half = pow(a, b / 2);
    int ans;
    if (b % 2 == 0)
    {
        ans = 1LL * half * half;
    }
    else
    {
        ans = 1LL * half * half;
        ans = 1LL * ans * a;
    }
    return ans;
}
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << pow(a, b);
    return 0;
}