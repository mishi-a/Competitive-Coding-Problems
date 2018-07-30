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

vector<int> g[300005];
int dp[300005][26];
int color[300005];
int cycle = 0;
string s;
bool checkCycle(int node)
{
	//cout << node << endl;
    color[node]=1;
    for(int v:g[node])
    {
       	if(color[v]==1)
    	{
    		cycle = 1;
    	}	
    	if(!color[v])
    		checkCycle(v);
    }
    color[node]=2;
}

void solve(int node)
{
	color[node]=1;
	for(int v: g[node])
	{
		if(!color[v])
		{
			solve(v);
		}
	}
	for(int i=0;i<26;i++)
	{
		for(auto v:g[node])
		{
           dp[node][i] = max(dp[node][i],dp[v][i]+(s[node-1]-'a'==i));
		}
	}
}

int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  cin >> s;
  for(int i=0;i<s.length();i++)
  {
    dp[i+1][s[i]-'a']++;
  }
  bool flag=false;
  while(m--)
  {
  	int u,v;
  	cin >> u >> v;
  	if(u==v)
    {
    	flag = true;
    	break;
    }
    g[u].pb(v);
  }
  if(flag)
  {
  	cout << "-1" << endl;
  	return 0;
  }
  for(int i=1;i<=n;i++)
  {
  	if(!color[i])
  	{  
  		checkCycle(i) ;
  		if(cycle == 1)
  		{
  			cout << "-1" << endl;
  			return 0;
  		}
  	}
  }
  memset(color,0,sizeof(color));
  for(int i=1;i<=n;i++)
  {
  	if(!color[i])
  	{
  		solve(i);
  	}
  }
  int ans = -1;
  for(int i=1;i<=n;i++)
  {
  	for(int j=0;j<26;j++)
  	{
  		ans = max(ans,dp[i][j]);
  	}
  }
  cout << ans << endl;
}
