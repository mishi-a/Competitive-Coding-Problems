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
int n,e;
int deg[100005];
int par[100005];
vector <pii> inp;
int ncom;
set <int> s[100005];
vector <int> p;
set<pii > check;

void dfs(int node)
{
  set <int> :: iterator itr ;
  while(s[node].size()>0)
  {
    itr = s[node].begin();
    int x = *itr;
    s[node].erase(x);
    s[x].erase(node);
    dfs(x);
  }
  p.pb(node);
}
int visited[100005]={0};
void dfs1(int node)
{
  visited[node] = 1;
  set <int> :: iterator itr = s[node].begin();
  while(itr!=s[node].end())
  {
    if(visited[*itr] == 0)
    {
      dfs1(*itr);
    }
    itr++;
  }
}
bool dfscheck()
{
  int cnt = 0;
  for(int i=1;i<=n;i++)
  {
    if(visited[i] == 0)
    {  cnt++;
    //cout << cnt << endl;
    if(cnt == 2)
      return true;
    dfs1(i);
    }
  }
  return false;
}
int main()
{
  sync;
  int a,b;
  cin >> n >> e;
  ncom = n;
  memset(par,-1,sizeof(par));
  for(int i=0;i<e;i++)
  {
    cin >> a >> b;
    s[a].insert(b);
    s[b].insert(a);
    deg[a]++;
    deg[b]++;
    inp.pb({a,b});
  }
  if(dfscheck())
  {
    cout << "NO" << endl;
      return 0;
  }
  for(int i=1;i<=n;i++)
  {
    if(deg[i]%2)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  dfs(1); 
  for(int i=0;i<p.size();i++)
    cout << p[i] << " ";
  cout << endl;
  for(int i=0;i<p.size()-1;i++)
    check.insert({p[i],p[i+1]});
  cout << "YES" << endl;
  for(int i=0;i<e;i++)
  {
    if(check.find({inp[i].FI,inp[i].SE})==check.end())
    {
      cout << inp[i].SE << " " << inp[i].FI << endl;
    }
    else
    {
      cout << inp[i].FI << " " << inp[i].SE << endl;
      check.erase({inp[i].FI,inp[i].SE});
    }
  }
  
}

