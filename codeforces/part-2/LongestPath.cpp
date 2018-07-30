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

int label[100005];
vector<int> tree[100005];
int n,k;
int dp[100005];
int dp1[100005];
int parent[100005];
void dfs(int node,int par)
{
	parent[node] = par;
	for(int v : tree[node])
	{
		if(v == par) continue;
		dfs(v,node);
	}
	int a=0,b=0;
	dp[node]=0;
	dp1[node]=0;
	for(int v:tree[node])
	{
		if(v == parent[node]) continue;
		if(dp1[v]>a)
		{
			b=a;
			a=dp1[v];
		}
		else if(dp1[v]>b)
			b=dp1[v];
	}

	if(label[node]%k==0)
	{
		dp[node]=a+b+1;
		dp1[node]=a+1;
	}
	else
	{
		dp[node]=0;
		dp1[node]=0;
	}
}

int main()
{
  sync;
  cin >> n >> k;
  for(int i=1;i<=n;i++)
  	cin >> label[i];
  for(int i=1;i<n;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	tree[a].pb(b);
  	tree[b].pb(a);
  }
  dfs(1,-1);
  int ans=0;
  for(int i=1;i<=n;i++)
  {
  	ans = max(ans,dp[i]);
  }	
  cout << ans-1 << endl;
}
