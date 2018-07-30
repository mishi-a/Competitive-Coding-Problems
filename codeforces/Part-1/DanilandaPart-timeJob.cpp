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
int n;
vector <int> g[200005];
int arr1[200005],start[200005],last[200005],arr[200005];
int tree[800005],lazy[800005];
vector <int> discover;
int cnt = -1;
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

void build(int node,int start,int end)
{
	if(start>end)
		return;
	if(start == end)
	{
		tree[node] = arr[start];
		return;
	}
	else
	{
		int mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = tree[2*node]+tree[2*node+1];
	}
}

void update(int node,int start,int end,int l,int r)
{
	if(lazy[node]!=0)
	{
		tree[node] = (end-start+1)-tree[node];
		if(start!=end)
			lazy[2*node]^=1,lazy[2*node+1]^=1;
		lazy[node]=0;
	}
	if(r<start || l > end)
		return;
	if(l<=start && r>=end)
	{
		tree[node] = (end-start+1)-tree[node];
		if(start!=end)
			lazy[2*node]^=1,lazy[2*node+1]^=1;
		return;
	}
	int mid =  (start+end)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);
    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node,int start,int end,int l,int r)
{
	if(r<start || l > end)
		return 0;
	if(lazy[node]!=0)
	{
		tree[node] = (end-start+1)-tree[node];
		if(start!=end)
			lazy[2*node]^=1,lazy[2*node+1]^=1;
		lazy[node]=0;
	}
	if(l<=start && r>=end)
	{
		return tree[node];
    }
    int mid = (start+end)/2;
    return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}

int main()
{
  sync;
  int a;
  cin >> n;
  for(int i=2;i<=n;i++)
  {
    cin >> a;
    g[a].pb(i);
    g[i].pb(a);
  }
  for(int i=1;i<=n;i++)
  	cin >> arr1[i];
  dfs(1,-1);
  for(int i=0;i<n;i++)
    arr[i] = arr1[discover[i]];


  // for(int i=0;i<discover.size();i++)
  // 	cout << discover[i] << " ";
  // cout << endl;
  // for(int i=1;i<=n;i++)
  // 	cout << start[i] << " ";
  // cout << endl;
  // for(int i=1;i<=n;i++)
  // 	cout << last[i] << " ";
  // cout << endl;
  build(1,0,n-1);
  int t;
  cin >> t;
  while(t--)
  {
  	string s;
  	int a;
  	cin >> s >> a;
  	if(s=="get")
  		cout << query(1,0,n-1,start[a],last[a]) << endl;
  	else
  		update(1,0,n-1,start[a],last[a]);
  }



}
