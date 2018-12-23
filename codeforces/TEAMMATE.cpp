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
ll fact[100005],inverse[100005];
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
ll freq[1000007];
set<ll> s;
int main()
{
  sync;
  fact[0] = 1;
  for(ll i=1;i<100005;i++ )
  {
  	fact[i] = (i*fact[i-1])%mod;
  	inverse[i] = power(fact[i],mod-2);
  }	  
  int t;
  cin >> t;
  while(t--)
  {
  	ll n;
  	cin >> n;
  	for(int i=0;i<n;i++)
  	{
  		ll k;
  		cin >> k;
  		s.insert(k);
  		freq[k]++;
  	}
  	ll cur = 0;
  	ll ans = 1;
  	for(auto it = s.rbegin();it!=s.rend();++it)
  	{
  		ll num = freq[*it]; 
  		if(cur%2 == 0)
  		{
  			if(num%2 == 0)
  			{
  				//cout << prod(fact[num],inverse[num/2])<< endl;
  				ll val = power(2,num/2);
  				ll x = power(val,mod-2);
  				ans = prod(ans,prod(prod(fact[num],inverse[num/2]),x));
  			}
  			else
  			{
  				ll val = power(2,(num-1)/2);
  				ll x = power(val,mod-2);
  				if(num-1 == 0)
  				{
  					ans = prod(ans,num);
  				}
  				else
  					ans = prod(num,prod(ans,prod(prod(fact[num-1],inverse[(num-1)/2]),x)));
  			}
  		}
  		else
  		{
  			//if(num%2 == 0)
  			{
  				if(num%2 == 0)
	  			{
	  				int t = num-2;
	  				if(t==0)
	  				{
	  					ans = prod(ans,2);
	  				}
	  				else
	  				{
	  					ll val = power(2,t/2);
  					    ll x = power(val,mod-2);
	  					ans = prod(ans,prod(prod(fact[t],inverse[t/2]),x));
	  					ans = prod(ans,prod(fact[num],inverse[num-2]));	
	  				}
	  				
	  			}
	  			else
	  			{
	  				if(num-1 == 0)
	  				{
	  					ans = prod(ans,num);
	  					
	  				}
	  				else
	  				{
	  					ll val = power(2,(num-1)/2);
  						ll x = power(val,mod-2);
	  					ans = prod(num,prod(ans,prod(prod(fact[num-1],inverse[(num-1)/2]),x)));	
	  				}
  					
	  			}
  			}
  		}
  		cur+=freq[*it];
  	}
  	cout << ans%mod << endl;
  	s.clear();
  	memset(freq,0,sizeof(freq));
  }
  
}
