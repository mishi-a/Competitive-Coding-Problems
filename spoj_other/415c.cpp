#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
#define mod 1000000007
using namespace std;
vector <ll > v;

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % mod;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}

int main()
{
  sync;
  ll n,x;
  cin >> n;
  for(ll i=0;i<n;i++)
  {
    cin >> x;
    v.pb(x);
  }
  sort(v.begin(),v.end());
  ll res = 0;
  for(ll i = n-1;i>=0 ;i--)
  {
    ll plus = (power (2,i)-1)%mod;
    ll minus = (power (2,n-1-i)-1)%mod;
    res = (res%mod + ((v[i]%mod)*(plus - minus+mod)%mod)%mod)%mod;
  }
  cout << res%mod << endl;
}
