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

const int MAX = 2e5+9;
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
vector<ll> v;
int main()
{
  sync;
  ll n,s;
  cin >> n >> s;
  for(int i=0;i<n;i++)
  {
  	ll a;
  	cin >> a;
  	v.pb(a);
  }
  sort(v.begin(),v.end());
  int idx = lower_bound(v.begin(),v.end(),s)-v.begin();
  int ls = idx;
  if(idx == n/2 && s == v[n/2])
  {
  	cout << "0" << endl;
  }
  else
  {
  	ll ans = 0;
  	for(int i=n/2;i<idx;i++)
  	{
  		ans += (s-v[i]);
  	}
  	for(int i=idx;i<=n/2;i++)
  	{
  		ans += (v[i]-s);
  	}
  	cout << ans << endl;
  }
}
