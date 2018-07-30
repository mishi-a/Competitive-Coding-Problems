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

int val[200005];
int dp[200005],parent[200005];
vector <int> tree[200005];
void dfs(int n,int par)
{
	dp[n] = val[n];
	parent[n] = par;
	for(int node : tree[n])
	{
		if(node == par) continue;
		dfs(node,n);
		dp[n] = dp[n]|dp[node];
	}
}
int main()
{
  sync;
  int n;
  cin >> n;
  int overall = 0;
  for(int i=1;i<=n;i++)
  	cin >> val[i],overall|=val[i];

  for(int i=1;i<n;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	tree[a].pb(b);
  	tree[b].pb(a);
  }
  dfs(1,-1);
  int ans = 0;
  cout << overall << endl;
  for(int i=1;i<=n;i++)
  {
    cout << dp[i] << " " << i << endl;
  	if(overall == dp[i])
      ans++;
  }
  cout << ans << endl;
}
