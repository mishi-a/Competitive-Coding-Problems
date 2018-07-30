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
ll n,k1;
ll sum = 0;
vector <ll> v;
vector <ll> csum;
map <pair<ll,pair<ll,ll > >,ll > mp;
ll solve(ll start,ll k,ll isum)
{
  ll ans,ans1,ans2,jsum;
  start == 0 ? jsum = 0 : jsum = csum[start-1]-isum;
  if(k == 0)
  {
    return ((sum-(isum+jsum))*k1-(isum)*(n-start));
  }
  if(start >= n)
    return 1e18;
  if(mp.find({start,{k,isum}})!=mp.end())
      return mp[{start,{k,isum}}];
  else
  {
    ans1 = solve(start+1,k-1,isum+v[start]) + v[start]*(start - (k1-k))-(jsum);
    //cout << ans1 << endl;
    ans2 = solve(start+1,k,isum) + v[start]*(k1-k)-(isum);
    //cout << ans2 << endl;
    ans = min(ans1,ans2); 
  }
  //cout << start << " " << k << " " << ans << endl;
  mp[{start,{k,isum}}] = ans;
  return ans;
}
int main()
{
  sync;
  cin >> n >> k1;
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
    sum+=a;
    
  }
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
  {
       i==0 ? csum.pb(v[i]) :csum.pb(csum[i-1]+v[i]);  
  }
  ll res = solve(0,k1,0);
  cout << res << endl;
}

