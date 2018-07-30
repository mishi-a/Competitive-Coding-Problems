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
vector<ll> v,v1;
int main()
{
  sync;
  ll n,m,cs,ce,vel;
  ll x;
  cin >> n >> m >> cs >> ce >> vel;
  for(ll i=0;i<cs;i++)
  {
  	cin >>x;
  	v.pb(x);
  }
  for(ll i=0;i<ce;i++)
  {
  	cin >> x;
  	v1.pb(x);
  }
  ll q;
  cin >> q;
  ll a,b,c,d;
  while(q--)
  {
  	cin >> a >> b >> c >> d;
  	ll idx = lower_bound(v.begin(),v.end(),b)-v.begin();
  	ll idx1 = lower_bound(v1.begin(),v1.end(),b)-v1.begin();
  	ll res = INT_MAX;
  	//cout << idx << " " << idx1 << endl;
  	if(a==c)
  	{
  		cout << abs(b-d) << endl;
  		continue;
  	}
  	if(1)
  	{
  		ll ans1=INT_MAX,ans=INT_MAX;
  		if(idx!=cs)
  			ans = abs(v[idx]-b)+abs(c-a)+abs(d-v[idx]);
  		if(idx-1>=0)
  		{
  			ans1 = abs(b-v[idx-1])+abs(c-a)+abs(d-v[idx-1]);
  		}
  		res = min(ans,ans1);
  		//cout << ans << " " << ans1 << endl;
  	}
  	if(1)
  	{
  		ll ans1=INT_MAX,ans=INT_MAX;
  		if(idx1!=ce)
  			ans = abs(v1[idx1]-b)+ceil((abs(c-a)*1.0)/vel)+abs(d-v1[idx1]);
  		if(idx1-1>=0)
  		{
  			ans1 = abs(b-v1[idx1-1])+ceil((abs(c-a)*1.0)/vel)+abs(d-v1[idx1-1]);
  		}
  		res = min(res,min(ans,ans1));
  	}
  	cout << (ll)res << endl;
  }
}
