/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
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

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
int n,a,b,c,v1,v2,v3;
vector <vector<int> > v(100005);
int d[100005];
int vis[100005];
int par[100005];
vector <int> p1,p2,p3;
void dfs(int node,int depth)
{
  d[node] = depth;
  vis[node] = 1;
  for(int i=0;i<v[node].size();i++)
  {
    if(vis[v[node][i]]==0)
    {
      par[v[node][i]] = node;
      dfs(v[node][i],depth+1);
    }
  }
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    cin >> a >> b >> c;
    cin >> v1 >> v2 >> v3;
    par[1]=-1;
    for(int i=0;i<n-1;i++)
    {
      int x,y;
      cin >> x >> y;
      v[x].pb(y);
      v[y].pb(x);
    }
    dfs(1,0);
    while(v1!=-1)
    {
      p1.pb(v1);
      v1 = par[v1];
    }
    while(v2!=-1)
    {
      p2.pb(v2);
      v2 = par[v2];
    }
    while(v3!=-1)
    {
      p3.pb(v3);
      v3 = par[v3];
    }
    int c123=0,c12=0,c23=0,c13=0;
    int i=v1.size()-2;
    int j=v2.size()-2;
    int k = v3.size()-2;
    while(1)
    {
      if(i<0 || j <0 || k<0)
       break;
      if(p1[i])
    }
  }
}

