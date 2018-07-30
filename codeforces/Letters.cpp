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
vector<ll> v;
int main()
{
  sync;
  ll n,m;
  cin >> n >> m;
  for(ll i=0;i<n;i++)
  {
  	ll num;
  	cin >> num;
  	(v.size()==0)?(v.pb(num)):v.pb(num+v[v.size()-1]); 
  } 
 for(ll i=0;i<m;i++)
  {
  	ll room;
  	cin >> room;
  	ll dorm = lower_bound(v.begin(),v.end(),room)-v.begin()+1;
  	ll r = dorm==1 ? room : room - v[dorm-2];
  	cout << dorm <<" " <<  r << endl;
  }
}
