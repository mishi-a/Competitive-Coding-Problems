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


const int mod = 998244353;
ll dp[5005];
ll dp1[5005][5005];
ll fact(ll n)
{
  if(n==0)
    return dp[0]=1;
  else
  {
    return dp[n] = (n%mod*fact(n-1)%mod)%mod; 
  }
}

ll pre(ll n,ll r)
{
  if(n<r || n==0)
    return 0;
  if(n==r || r==0)
    return 1;   
  if(dp1[n][r]!=-1)
    return dp1[n][r]%mod;
  else
  {
    return dp1[n][r]=(pre(n-1,r-1)%mod+pre(n-1,r)%mod)%mod;
  } 
}

int main()
{
  sync;
  ll a,b,c;
  memset(dp1,-1,sizeof(dp1));
  memset(dp,0,sizeof(dp));
  fact(5000);   
  //cout << dp[1] << " " << dp[5000] << " " <<   pre(1,1) << " " << pre(2,1) << endl; 
  cin >> a >> b >> c;   
  ll p = min(a,b);
  //cout << p << endl;
  ll ans=0;
  for(ll i=0;i<=p;i++)
  {
    ans+=((pre(a,i)%mod)*(pre(b,i)%mod)%mod)*(dp[i]);
    ans%=mod;
  }
  p = min(b,c);
  //cout << p << " " << ans << endl;      
  ll sum=0;
  for(ll i=0;i<=p;i++)
  {
    sum+=((pre(c,i)%mod)*(pre(b,i)%mod)%mod)*(dp[i]);
    sum%=mod;
  }
  ans = (ans*sum)%mod;
  sum=0;
  p = min(c,a);
  for(ll i=0;i<=p;i++)
  {
    sum+=((pre(a,i)%mod)*(pre(c,i)%mod)%mod)*(dp[i]);
    sum%=mod;
  }
  ans = (ans*sum)%mod;
  cout << ans << endl;
}

