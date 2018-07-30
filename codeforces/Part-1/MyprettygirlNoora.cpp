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

ll arr[5000005];
ll dp[5000005];
void pre()
{
  for(int i=2;i<5000005;i++)
    arr[i] = i;
  for(int i=2;i<5000005;i+=2)
  {
    arr[i] = 2;
  }
  for(int i=3;i*i<5000005;i+=2)
  {
    if(arr[i] == i)
    {
      for(int j=i*i;j<5000005;j+=i)
      {
        if(arr[j] == j)
          arr[j] = i;
      }
    }
  }
}

int main()
{
  sync;
  ll t,l,r;
  cin >> t >> l >> r;
  pre();
  dp[1] = 1;
  ll k=1;
  ll ans = 0;
  for(ll i=2;i<=r;i++)
  {
    if(arr[i] == i)
      dp[i] = (i*(i-1))/2;
    else
    {
      dp[i] = ((i/arr[i])*dp[arr[i]] + dp[i/arr[i]])%MOD; 
    }
    if(i>=l)
    {
      ans = (ans + (k*(dp[i]%MOD)));
      if(ans >= MOD)
       ans = ans%MOD;
      k = (k*t)%MOD;
    }
  }
  cout << ans << endl;
}
