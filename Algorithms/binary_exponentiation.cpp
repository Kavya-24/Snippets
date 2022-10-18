#include<bits/stdc++.h>

using namespace std;
typedef long long int  ll;

template <class T>
class Algebra{
    public:
        // Iterative Approach
        static T binExpIterative(T a,T b)  //a^b  
        {
            T ans=1;
            do{
                if (b & 1) // 'b' is odd
                    ans*=a;
                b>>=1;     //b/=2
                a*=a;   //a^2
            }while(b!=0);
            return ans;
        }
        //Recursive Approach
        static T   binExpRecursive(T a, T b) //a^b
        {
            if(b<1)
                return 1;
            if (b & 1) // 'b' is odd
                return a * binExpRecursive(a * a, b / 2);
            else
                return binExpRecursive(a * a, b / 2);
        };
        
        static T modExponentiation(T a,T b,T c)   // (a^b)%c
        {
            T ans=1;
            do{
                if(b&1)
                    ans=(ans*a)%c;
                b >>= 1; // b/=2
                a=a*a%c;
            }while(b!=0);
            return ans;
        }
};


int main()
{
    ll   a=603,b=1109;
    cout<<Algebra<ll>::binExpIterative(a,b)<<endl;

    cout << Algebra<ll>::binExpRecursive(a, b) << endl;

    cout << Algebra<ll>::modExponentiation(a, b,2881) << endl;
}
