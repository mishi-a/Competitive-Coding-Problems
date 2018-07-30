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
ll mod = 1e9+7;
ll arr[205] = {0};
ll dp[205][200][200];
ll solve(ll idx,ll p,ll q)
{
  ll ans = 0;
  if(idx > 200)
    return 0;
  if(dp[idx][p][q]!=-1) return dp[idx][p][q];
  else
  {
    ll mov = min(p,q);
    for(ll i=0;i<=mov;i++)
    {
      if(i==0)
       ans = solve(idx+1,q,arr[idx])%mod,ans%=mod;
      else
       ans = 1 + ans + solve(idx+1,q-i,arr[idx]+i)%mod,ans%=mod;
    }
  }
  return (dp[idx][p][q] = ans%mod);
}

int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
  memset(dp,-1,sizeof(dp));
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++)
      cin >> arr[i];
    if(n==1)
      cout << "1" << endl;
    if(n>=2)
    {
      cout << (1 + solve(2,arr[0],arr[1]))%mod << endl;
    }
    memset(arr,0,sizeof(arr));
  }
}

