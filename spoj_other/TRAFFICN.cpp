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

vector <vector<pii > > G(10001);
vector <vector<pii > > TG(10001); 
int dist1[10001];
int dist2[10001];
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

priority_queue <pii , vector<pii > ,comp > q;
int visited [10001] = {0};
void djikstra(int node)
{
  q = priority_queue <pii , vector<pii > ,comp > ();
  q.push({node,0});
  dist1[node] = 0;
  while(!q.empty())
  {
    int u = q.top().first;
    q.pop();
    if(visited[u]) continue;
    for(int i = 0;i<G[u].size();i++)
    {
      int v = G[u][i].first;
      int w = G[u][i].second;
      if(!visited[v] && dist1[v] > dist1[u]+w)
      {
        dist1[v] = dist1[u] + w;
        q.push({v,dist1[v]});
      }
    }
    visited[u] = 1;
  }
}
void djikstra1(int node)
{
  q = priority_queue <pii , vector<pii > ,comp > ();
  memset(visited,0,sizeof(visited));
  q.push({node,0});
  dist2[node] = 0;
  
  while(!q.empty())
  {
    int u = q.top().first;
    q.pop();
    if(visited[u]) continue;
    for(int i = 0;i<TG[u].size();i++)
    {
      int v = TG[u][i].first;
      int w = TG[u][i].second;
      if(!visited[v] && dist2[v] > dist2[u]+w)
      {
        dist2[v] = dist2[u] + w;
        q.push({v,dist2[v]});
      }
    }
    visited[u] = 1;
  }
}
void solve()
{
  int n,m,k,s,t;
  cin >> n >> m >> k >> s >> t;
  for(int i=1;i<=m;i++)
  {
    int a,b,w;
    cin >> a >> b >> w;
    G[a].pb({b,w});
    TG[b].pb({a,w});
  }
  for(int i=0;i<=n;i++)
  {
    dist1[i] = 10000000;
    dist2[i] = 10000000;
  }
  djikstra(s);
  djikstra1(t);
  int mina = dist1[t];
  for(int i=0;i<k;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    mina = min(min(dist1[a]+dist2[b] + c, dist1[b] + dist2[a] + c),mina);
  }
  if(mina < 10000000)
    cout << mina << endl;
  else
    cout << "-1" << endl;
  //djikstra(s,1);
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    for(int i=0;i<10001;i++)
    {
      G[i].clear();
      TG[i].clear();
    }
    memset(visited,0,sizeof(visited));
  } 
}

