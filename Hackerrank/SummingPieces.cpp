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
ll n;
vector <ll> v;
vector <ll> csum;
ll dp[1000005] ;
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
    return res;
}
ll solve(int start)
{
  ll ans = 0;
  if(start >= n)
    return 0;
  if(dp[start]!=-1)
      return dp[start];
  else
  {
    for(ll i=start;i<n;i++)
    {
      ans = ans + (csum[i]-csum[start-1])*(i-start+1)*(i== n-1 ? 1 : power(2,(n-start)-(i-start+2))) ;
      if(ans > MOD)
        ans = ans % MOD;
      ans = ans + solve(i+1);
      if(ans > MOD)
        ans = ans % MOD;
    }
  }
  return (dp[start] = ans%MOD);
}
int main()
{
  sync;
  cin >> n;
  memset(dp,-1,sizeof(dp));
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
    i==0 ? csum.pb(a) : csum.pb(csum[i-1]+a);
  }
  ll ans = 0;
  for(int i=0;i<n;i++)
  {
    ans = ans + csum[i]*(i+1)*(i== n-1 ? 1 : power(2,n-(i+2)));
    if(ans > MOD)
        ans = ans % MOD;
    ans = ans + solve(i+1);
    if(ans > MOD)
        ans = ans % MOD;
    //cout << ans << endl;
  }
  cout << ans%MOD << endl;
}

