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

vector<int> g[MAX];
int vis[MAX],sz[MAX];
ll ans = 0,cnt=0,tot;
void dfs(int n,int par,int d)
{
	if(d&1)cnt++;
	sz[n] = 1;
	vis[n] = 1;
	for(int i=0;i<g[n].size();i++)
	{
		int p = g[n][i];
		if(!vis[p])
		{
			dfs(p,n,d+1);
			sz[n]+=sz[p];
		}
	}
	ans += sz[n]*1LL*(tot-sz[n]); 
}

int main()
{
  sync;
  int n;
  cin >> n;
  tot = n;
  for(int i=0;i<n-1;i++)
  {
  	int u,v;
  	cin >> u >> v;
  	g[u].pb(v),g[v].pb(u);
  }
  dfs(1,-1,0);
  cout << ((ans + (n-cnt)*1LL*cnt)>>1) << endl;
}
