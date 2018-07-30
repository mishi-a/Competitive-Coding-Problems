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
ll n,m,d;
ll dp[105];
ll solve(ll tot)
{
  ll ans=0;
  if(tot == 0)
    return 1;
  if(tot < 0)
    return 0;
  if(dp[tot]!=-1)
    return dp[tot];
  else
  { 
    for(ll i=1;i<=m;i++)
    {
      ans = (ans%MOD + solve(tot-i)%MOD)%MOD;
    }
    return (dp[tot] = (ans%MOD));
  } 
}

int main()
{
  sync;
  ll n;
  cin >> n >> m >> d;
  memset(dp,-1,sizeof(dp));
  ll ans = solve(n);
  m=d-1;
  memset(dp,-1,sizeof(dp));
  ans = (ans+MOD - solve(n))%MOD;
  cout << ans << endl;
}

