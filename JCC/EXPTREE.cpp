/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second
#define MOD 1000000007
#define MOD1 1000000009
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
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
*/
using namespace std;
ll hcf(ll n1, ll n2)
{
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else 
       return n1;
}
ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % MOD;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % MOD;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD;  
    }
    return res%MOD;
}
ll power1(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % MOD1;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % MOD1;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD1;  
    }
    return res%MOD1;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    ll n;
    cin >> n;
    n--;
    ll x = hcf(n,4*n-2);
    ll a = n/x;
    ll b = (4*n-2)/x;
    x = hcf(n+1,b);
    ll c = (n+1)/x;
    b = b/x;
    //cout << a <<" " <<   b <<" " <<  c <<" " <<  endl;
    ll ans = (((((a%MOD)*(c%MOD))%MOD)%MOD)*((power(b,MOD-2))%MOD))%MOD;
    ll ans1 = (((((a%MOD1)*(c%MOD1))%MOD1)%MOD1)*((power1(b,MOD1-2))%MOD1))%MOD1;
    
    cout << ans << " " << ans1 << endl;
  }
}

