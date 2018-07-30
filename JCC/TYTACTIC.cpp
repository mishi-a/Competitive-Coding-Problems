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
int arr[100005];
vector <int> g[100005];
int last[100005],start[100005],BIT[100005];
vector <int> discover;
int cnt = 0,n;
int val[100005];
void dfs(int node,int par)
{
  discover.pb(node);
  start[node] = ++cnt;
  for(int i=0;i<g[node].size();i++)
  {
  	int u = g[node][i];
  	if(u == par) continue;
  	dfs(u,node);
  }
  last[node]=cnt;
}
void update(int idx,int val)
{
	idx++;
	while(idx<=n)
	{
       BIT[idx] += val;
       idx += ((idx)&(-idx));
	}
}
int getsum(int idx)
{
	idx++;
	int sum = 0;
	while(idx>0)
	{
      sum+= BIT[idx];
      idx -= ((idx)&(-idx));
	}
	return sum;
}
int main()
{
  sync;
  int m;
  memset(BIT,0,sizeof(BIT));
  discover.pb(-1);
  cin >> n >> m;
  for(int i=1;i<=n;i++)
  {
    cin >> arr[i];
  }
  for(int i=1;i<n;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	g[a].pb(b);
  	g[b].pb(a);
  }
  dfs(1,-1);
  // for(int i=1;i<discover.size();i++)
  // 	cout << discover[i] << " ";
  // cout << endl;	
  // for(int i=1;i<=n;i++)
  // 	cout << start[i] << " ";
  // cout << endl;
  // for(int i=1;i<=n;i++)
  // 	cout << last[i] << " ";
  // cout << endl;
  for(int i=1;i<=n;i++)
    val[i-1]=arr[discover[i]];
  for(int i=0;i<n;i++)
  {
  	update(i,val[i]);
  }   
  for(int i=0;i<m;i++)
  {		
  	char c;
  	cin >> c;
  	if(c == 'U')
  	{ 
       int a,b,t;
       cin >> a >> b;
       if(b>val[start[a]-1])
           t = b-val[start[a]-1];
       if(b<val[start[a]-1])
       	   t = -(val[start[a]-1]-b);
       if(b==val[start[a]-1])
       	   t = 0;
       //cout << "t " << t << endl;
       update(start[a]-1,t);
       val[start[a]-1]=b;
  	}
  	else
  	{
       int a;
       cin >> a;

       cout << getsum(last[a]-1)-getsum(start[a]-2) << endl;
  	}
  }
}
