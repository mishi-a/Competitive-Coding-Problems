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

vector < vector <int> > v(100005);
vector <int> vis(100005,0);
vector <int> in(100005);
vector <int> out(100005);
vector <int> dis;
vector <int> arr(100005);
vector <int> bit(100005,0);
int curr = 0;
void dfs(int node)
{
  dis.pb(node);
  vis[node] = 1;
  in[node] = ++curr;
  for(int i=0;i<v[node].size();i++)
  {
    if(vis[v[node][i]] == 0)
       dfs(v[node][i]);
  }
  out[node] = curr;
}

int getres(int idx)
{
  idx = idx+1;
  int ans = 0;
  while(idx>0)
  {
    ans = ans + bit[idx];
    idx -= ((idx)&(-idx));
  }
  return ans;
} 

void update(int idx,int val,int n)
{ 
  idx = idx+1;
  while(idx<=n)
  {
    bit[idx]+=val;
    idx += ((idx)&(-idx));
  }
}

int main()
{
  sync;
  int n,q;
  cin >> n >> q;
  dis.pb(-1);
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    v[a].pb(b);
  }
  dfs(1);
  for(int i=1;i<=n;i++)
  {
    int x;
    cin >> x;
    arr[in[i]-1] = x;
  }
  for(int i=0;i<=n-1;i++)
  {
    if(arr[i] == 0)
      update(i,1,n);
  }
  //cout << getres(-1) << endl;
 for(int i=0;i<q;i++)
  {
    char c;
    cin >> c;
    if(c == 'Q')
    {
       int x;
       cin >> x;
       int a = in[x];
       int b = out[x];
       cout << getres(b-1)-getres(a-2) << endl;
    }
    else
    {
      int a,b;
      cin >> a >> b;
      if(arr[in[a]-1] == 0)
      {
        arr[in[a]-1] += b;
        if(arr[in[a]-1] != 0)
          update(in[a]-1,-1,n);
      }
      else
      { 
       arr[in[a]-1] += b;
       if(arr[in[a]-1] == 0)
          update(in[a]-1,1,n);
      }
    }
  }  
}

