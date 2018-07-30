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
vector<ll> v[200005];
vector<ll> v1,v2;
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++)
  {
  	int a;
  	cin >> a;
  	v1.pb(a);
  	v2.pb(a);
  }
  sort(v1.begin(),v1.end());
  for(int i=0;i<k;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	v[a].pb(b);
  	v[b].pb(a);
  }
  for(int i=0;i<n;i++)
  {
  	int idx = lower_bound(v1.begin(),v1.end(),v2[i])-v1.begin();
  	int ans = idx;
  	for(int j=0;j<v[i+1].size();j++)
  	{
  		if(v2[v[i+1][j]-1]<v2[i])
  			ans--;
  	}
    cout << ans << " ";
  }
}
