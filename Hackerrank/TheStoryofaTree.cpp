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

vector <vector <int> >v(100005);
vector <pii > v1;
int par[100005] = {0};
int visited[100005] = {0};

int hcf(int n1, int n2)
{
    if (n2 != 0)
       return hcf(n2, n1%n2);
    else 
       return n1;
}

void dfs(int src)
{
  visited[src] = 1;
  for(int i=0;i<v[src].size();i++)
  {
    if(visited[v[src][i]] == 0)
    {
      par[v[src][i]] = src;
      dfs(v[src][i]);
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  for(int i=1;i<n;i++)
  { 
    int a,b;
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  int g,k;
  cin >> g >> k;
  for(int i=0;i<g;i++)
  {
    int a,b;
    cin >> a >> b;
    v1.pb({a,b});
  }
  int ans = 0;
  for(int i=1;i<=n;i++)
  {
    dfs(i);
    int cnt = 0;
    for(int i=0;i<v1.size();i++)
    {
      if(par[v1[i].SE] == v1[i].FI)
      {
        cnt++;
      }
      if(cnt >= k)
      {
        ans++;
        break;
      }
    }
    memset(par,0,sizeof(par));
    memset(visited,0,sizeof(visited));
  }
  int val = hcf(ans,n);
  int num = ans/val;
  int den = n/val;
  if(num == 0)
    cout << "0/1" << endl;
  else
    cout << num << "/" << den << endl;
}

int main() 
{
  sync;
  int q;
  cin >> q;
  while(q--)
  {
    solve();
    memset(par,0,sizeof(par));
    memset(visited,0,sizeof(visited));
    for(int i=0;i<100004;i++)
      v[i].clear();
    v1.clear();
  }
}

