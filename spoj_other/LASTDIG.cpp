/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>

#define endl '\n'
#define ll long long

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
   ll a,b;
   cin >> a >> b;
   cout << power(a,b,10) << endl;
  }
}

