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

vector <vector<int> >v(200005);
vector <pii >v1;
vector <int> c;
int color,curr;
int visited[200005] = {0};
int dfs(int node)
{
  visited[node] = 1;
  int res = 0;
  for(int i=0;i<v[node].size();i++)
  {
    if(v[node][i]==curr)
      continue;
    if(visited[v[node][i]]==0)
    {
      if(c[v[node][i]] == color)
      {
        res = dfs(v[node][i]);
        if(res == -1)
          return res;
      }
      else
      {
        res = -1;
        break;
      }
    }
  }
  return res;
}
int check(int node)
{
  curr = node;
  //cout << "curr : " << curr << endl;
  //cout << v[2].size() << endl;
  for(int i=0;i<v[node].size();i++)
  {
    color = c[v[node][i]];
   //cout << "Color : " << color << endl;
    int res = dfs(v[node][i]);
    //cout << res << endl;
    //cout << "aa " << res << endl;
    if(res == -1)
    {  
      //cout << "HI" << endl;
      return -1;
    }
  }
  return 0;
}
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=1;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    v1.pb({a,b});
    v[a].pb(b);
    v[b].pb(a);
  }
  c.pb(-1);
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    c.pb(a);
  }
  int r1=-1,r2=-1;
  for(int i=0;i<v1.size();i++)
  {
    if(c[v1[i].FI]!=c[v1[i].SE])
    {
      r1 = v1[i].FI;
      r2 = v1[i].SE;
      break;
    }
  }
  //cout << r1 << r2 ;
  if(r1==-1)
    cout << "YES" <<"\n" << 1 << endl;
  else
  {
    int ans = check(r1);
    memset(visited,0,sizeof(visited));
    int ans2 = check(r2);
    if(ans == ans2 && ans == -1)
      cout << "NO" << endl;
    else
    {
      if(ans == 0)
            cout << "YES" <<"\n" << r1 << endl;
      else
            cout << "YES" <<"\n" << r2 << endl;
    }
  }
  
  
}

