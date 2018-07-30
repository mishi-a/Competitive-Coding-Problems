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

vector <vector <int> > v(100005);
int visited[100005] = {0};
int tot = 0,n;

void dfs(int src)
{
  visited[src] = 1;
  tot++;
  for(int i=0;i<v[src].size();i++)
  {
    if(visited[v[src][i]] == 0)
      dfs(v[src][i]);
  }
}

void solve()
{
  int m,r,l;
  cin >> n >> m >> l >> r;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  int cnt = 0;
  for(int i=1;i<=n;i++)
  {
    if(visited[i] == 0)
    {
     dfs(i);
     cnt += (tot-1)*r+l;
     tot = 0;
    }
  }
  if(l<=r)
  {
    cout << n*l << endl;
  }
  else
  {
    cout << cnt << endl;
  }
}

int main()
{
  sync;
  int q;
  cin >> q;
  while(q--)
  {
    solve();
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
      v[i].clear();
    }
  }
}

