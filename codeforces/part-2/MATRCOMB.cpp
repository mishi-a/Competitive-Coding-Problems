/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
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


using namespace std;
ll mod = 1e9+7;
ll fact[1000005],inverse[1000005];
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
ll prod(ll x, ll y)
{
	x%=mod,y%=mod;
	return (x*y)%mod;
}
int main()
{
  sync;
  ll n;
  cin >> n;
  if(n==2)
  {
  	cout<<"0"<<endl;return 0;
  }
  fact[0] = 1;
  for(ll i=1;i<=1000005;i++ )
  {
  	fact[i] = (i*fact[i-1])%mod;
  	inverse[i] = power(fact[i],mod-2);
  }	  
  ll p1 = prod(inverse[n*n-n-2],prod(fact[n*n],inverse[n+2]));
  ll p2 = prod(n*n-n,prod(n*n-n-1,inverse[2]));
  ll p3 = prod(n,prod(n-1,inverse[2]));
  p3 = prod(p3,inverse[2]);
  p2 = (p2-p3+mod)%mod;
  p2 = prod(fact[n],p2);
  p1 = (p1-p2+mod)%mod;
  cout<<p1<<endl;

}
