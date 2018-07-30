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

vector <int> c;
vector <vector <int> > T(50005);
vector <pii> vec;
int vis[50005] = {0};
int par[50005] = {0};
map <int,int> mp;
int u,v,k;
int flag = 0;
void dfs(int node)
{
  vis[node] = 1;
  for(int i=0;i<T[node].size();i++)
  {
     if(flag == 1)
       return;
     if(vis[T[node][i]] == 0)
     {
       par[T[node][i]] = node;
       if(T[node][i] == v)
       {
         flag = 1;
         return;
       }
       dfs(T[node][i]);
     }
  }
}
bool acomp (pii a,pii b)
{
  if(a.first > b.first)
    return true;
  else if(a.first == b.first && a.second > b.second )
    return true;
  else
    return false;
}
int main()
{
  sync;
  int n,q;
  cin >> n >> q;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    c.pb(a);
  }
  for(int i=1;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    T[a].pb(b);
    T[b].pb(a);
  }
  for(int i=0;i<q;i++)
  {
    flag = 0;
    cin >> u >> v >> k;  
    dfs(u);
    int node = v;
    par[u] = -1;
    while(node!=-1)
    {
      if(mp.find(c[node-1])!=mp.end())
          mp[c[node-1]] ++;
      else
          mp[c[node-1]] = 1;
      node = par[node];
    }
    map <int,int> :: iterator itr = mp.begin();
    for(;itr!=mp.end();itr++)
    {
      vec.pb({itr->second,itr->first});
    }
    sort(vec.begin(),vec.end(),acomp);
    cout << vec[k-1].SE << endl;
    vec.clear();
    mp.clear();
    memset(vis,0,sizeof(vis));
  }
}

