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

vector <vector<pair<ll,ll>  > > v(100005);
ll visited[100005] = {0};
ll parent[100005]={0};
ll depth[100005]={0};
vector <vector<ll> > vec(100005);
vector <vector<ll > > vec2(100005);
ll cost[100005]={0};

void dfs(ll node,ll d)
{
  depth[node] = d;
  visited[node] = 1;
  if(d%1000 == 1)
  {
    ll x = node;
    while(x!=1)
    {
      vec[node].pb(cost[x]);
      x = parent[x];
    }
  }
  for(ll i=0;i<v[node].size();i++)
  { 
    if(visited[v[node][i].FI] == 0)
    {
      parent[v[node][i].FI] = node;
      cost[v[node][i].FI] = v[node][i].SE; 
      dfs(v[node][i].FI,d+1);
    }
  }
}

ll func(ll node,ll x)
{
  ll d = depth[node];
  ll ans = 0;
  while(d%1000!=1)
  {
    if(cost[node] <= x )
       ans = ans^cost[node];
    d--;
    node = parent[node];
  }
  if(node == 1)
    return ans;
  vector<ll> :: iterator itr = lower_bound(vec[node].begin(),vec[node].end(),x);
  while(*itr==x)
  {
    itr++;
  }
  if(itr!=vec[node].end())
  {
     ll idx = itr - vec[node].begin();
     return ans^(vec2[node][vec[node].size()-1] ^ (idx == 0 ? 0 : vec2[node][idx-1]));
  }
  return ans^vec2;
}

int main()
{
  sync;
  ll t,n,m,a,b,c,q;
  cin >> t;
  parent[1] = 1;
  while(t--)
  {
    cin >> n;
    for(ll i=0;i<n-1;i++)
    {
      cin >> a >> b >> c;
      v[a].pb({b,c});
      v[b].pb({a,c});
    }
    dfs(1,1);
       // cout << vec.size() << " " << vec2.size() << endl;
    for(ll i=1;i<=n;i++)
    {
      if(depth[i]%1000 == 1)
      {
        sort(vec[i].begin(),vec[i].end());
        ll cxor = 0;
        for(ll j=0;j<vec[i].size();j++)
        {
          cxor = cxor^vec[i][j];
          vec2[i].pb(cxor);
        }
      }
    }

    cin >> q;
    while(q--)
    {
      cin >> a >> b >> c;
      ll x = func(a,c);
      ll y = func(b,c);
      cout << (x^y) << endl;
    }
    for(ll i=0;i<100005;i++)
    {
       v[i].clear();
       vec[i].clear();
       vec2[i].clear();
    }
    memset(parent,0,sizeof(parent));
    memset(cost,0,sizeof(cost));
    memset(depth,0,sizeof(depth));
    memset(visited,0,sizeof(visited));
  }
}

