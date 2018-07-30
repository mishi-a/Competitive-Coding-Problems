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
int val[200005],ans[200005],vis[200005];
vector <vector<int> > v(200005);
set <vector<int> > s;
int hcf(int n1, int n2)
{
    if (n2 != 0)
       return hcf(n2, n1%n2);
    else 
       return n1;
}

void solve(int cur,int par,int skip,int curgcd)
{
  //vis[cur] = 1;
  vector <int> k = {cur,par,skip,curgcd};
  ans[cur] = max(ans[cur],hcf(val[cur],curgcd));
  if(skip)
    ans[cur] = max(ans[cur],curgcd);
  if(s.find(k)!=s.end())
    return;
  s.insert(k);
  for(int i=0;i<v[cur].size();i++)
  {
    if(v[cur][i]!=par)
    {
      solve(v[cur][i],cur,skip,hcf(curgcd,val[cur]));
      if(skip)
        solve(v[cur][i],cur,0,curgcd);
    }
  }
  
}
int main()
{
  sync;
  int n,a,b;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    cin >> val[i];
  }
  for(int i=1;i<=n-1;i++)
  {
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  solve(1,0,1,0);
  for(int i=1;i<=n;i++)
   cout << ans[i] << " " ;
  cout << endl;
}

