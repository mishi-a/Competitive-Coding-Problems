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

map<pair<ll,ll>,vector<ll>> mp;
vector<pair<ll,ll> > v;
vector <ll> v1;

int main()
{
  sync;
  ll n,l,r;
  cin >> n;
  for(ll i=1;i<=n;i++)
  {
  	cin >> l >> r;
  	v.pb({l,r});
  	mp[{l,r}].pb(i);
  }
  sort(v.begin(),v.end());
  for(ll i=0;i<n;i++)
  {
  	v1.pb(v[i].FI);
  }
  for(ll i=0;i<n;i++)
  {
  	ll l = v[i].FI;
  	ll idx = lower_bound(v1.begin()+i+1,v1.end(),l)-v1.begin();
  	if(idx!=n)
  	{
  		if(v[idx].FI==l)
  		{
  			if(v[idx].SE == v[i].SE)
  			{
  				cout << mp[{v[idx].FI,v[idx].SE}][0] << " " << mp[{v[idx].FI,v[idx].SE}][1] << endl;
  				return 0;

  			}
  			cout << mp[{v[i].FI,v[i].SE}][0] <<" "<< mp[{v[idx].FI,v[idx].SE}][0] << endl;
  			return 0;
  		}
  		if(v[idx].SE<=v[i].SE && v[idx].FI>=v[i].FI)
  		{
  			cout << mp[{v[idx].FI,v[idx].SE}][0] << " " << mp[{v[i].FI,v[i].SE}][0] << endl;
  			return 0;
  		}
  	}
  }
  cout << "-1 -1" << endl;
}
