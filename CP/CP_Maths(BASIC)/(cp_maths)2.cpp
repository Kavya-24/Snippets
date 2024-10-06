//  GCD-GREATEST COMMON DIVISIOR

//  FOR LCM = A*B/GCD(A,B)
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
    // cout<<"lcm :"<<a*b/(gcd(a,b))<<endl;
    return 0;
}