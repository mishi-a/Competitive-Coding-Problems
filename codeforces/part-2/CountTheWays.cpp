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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
ll mod = 1e9+7;
ll fact[200005],inverse[200005];
ll power(ll x, ll y)
{
    ll res = 1;      
    x = x % mod;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod; 
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
  fact[0] = 1,inverse[0]=1;
  for(ll i=1;i<200005;i++ )
  {
  	fact[i] = (i*fact[i-1])%mod;
  	inverse[i] = power(fact[i],mod-2)%mod;
  }	  
  int t,tot=1;
  cin >> t;
  while(t--)
  {
  	cout << "Case #"<<tot<< ": ";
  	tot++;
  	ll n,m;
  	cin >> n >> m;
  	ll ans = 0;
  	for(int i=1;i<=m;i++)
  	{
  		ll val = prod(fact[(n-i)*2+i],power(2,i));
  		//cerr << val << endl;
  		if(i%2==1)
  		{
  			ans+= prod(val,prod(prod(fact[m],inverse[m-i]),inverse[i]));
  			//cerr << ans << endl;
  			ans%=mod;
  		}
  		else
  		{
  			ans-= prod(val,prod(prod(fact[m],inverse[m-i]),inverse[i]));
  			ans = (ans+mod)%mod;
  		}
  	}
  	cout << (fact[2*n]-ans+mod)%mod << endl;
  }
}
