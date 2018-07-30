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
#define for(i,a,n) for(int i=a;i<n;i++)
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

int evil[100005];
vector <int> g[100005];
int in[100005],out[100005];

void dfs1(int node,int par)
{
  if(evil[node]==1) in[node]=0;
  else in[node] = INT_MIN;
  for(i,0,g[node].size())
  {
    if(g[node][i]==par) continue;
    dfs1(g[node][i],node);
    in[node]=max(in[node],1+in[g[node][i]]);
  }
}

void dfs2(int node,int par)
{
  int mx1= INT_MIN,mx2=INT_MIN;
  for(i,0,g[node].size())
  {
    if(g[node][i]==par)continue;
    if(in[g[node][i]]>mx1)mx2=mx1,mx1=in[g[node][i]];
    else if(in[g[node][i]]>mx2) mx2 = in[g[node][i]];  
  }
  //cout << mx1 << " " << mx2 << endl;
  for(i,0,g[node].size())
  {
    if(par == g[node][i]) continue;
    int res = mx1;
    if(mx1==in[g[node][i]]) res = mx2;
    out[g[node][i]]=max(1+out[node],2+res);
   // cout << "h " << g[node][i] << " " << out[g[node][i]] << endl;
    if(evil[g[node][i]] == 1 && out[g[node][i]]<0)out[g[node][i]]=0;
    dfs2(g[node][i],node);
  }
}
int main()
{
  sync;
  int n,m,d,x;
  cin >> n >> m >> d;
  for(i,0,m) cin >> x,evil[x]=1;
  for(i,1,n)
  {
    int a,b;
    cin >> a >> b;
    g[a].pb(b),g[b].pb(a);
  }
  dfs1(1,0);
  if(!evil[1])out[1] = INT_MIN;
  else out[1]=0;
  dfs2(1,0); 
  int ans = 0;
  //for(i,0,n)cout << in[i+1] << " "<< out[i+1] << " " << endl;
  for(i,0,n)
  {
    if(in[i+1]<=d && out[i+1]<=d)
      ans++;
  } 
  cout << ans << endl;
}

