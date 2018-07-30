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
vector <int> v1;
int mux = -1;
int n,m,k,a,b;
int visited[100005] = {0};
int dead[100005] = {0};
int dist[100005] = {0};
int val;
int ans = -1;
int cnt = 0;
bool mfs(int node)
{
  //cout << node << "hello " << endl;
  queue<int > q;
  q.push(node);
  dead[node] = 1;
  dist[node] = 0;
  while(!q.empty())
  {
    int x = q.front();
    cnt++;
    visited[x] = 1;
    q.pop();
    for(int i=0;i<v[x].size();i++)
    {
      if(visited[v[x][i]] == 0 && (dead[v[x][i]] == 0) && dist[x]+1<= val)
      {
        q.push(v[x][i]);
        dead[v[x][i]] = 1;
        dist[v[x][i]] = dist[x]+1;
      }
      else if(visited[v[x][i]] == 0 && (dead[v[x][i]]!=0)  && dist[x]+1<= val)
      {
        //cout << v[x][i] << endl;
        return false;
      }
      
    }
  }
  return true;
}
bool check(int mid)
{
  cnt = 0;
  val = mid;
  for(int i = 0;i<v1.size();i++)
  {
    memset(visited,0,sizeof(visited));
    if(!mfs(v1[i]))
      return false;
  }
  return true;
}
void dbs()
{
  int l=0;int r = 4;
  while(l<=r)
  {
    int mid = (l+r)/2;
    if(check(mid))
    {
      //cout << mid << "HI" << endl;
      mux = max(mux,mid);
      ans = max(ans,cnt);
      l = mid+1;
    }
    else
    {
      r = mid-1;
    }
    memset(dist,0,sizeof(dist));
    memset(dead,0,sizeof(dead));
  }
}
int main()
{
  sync;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++)
  {
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  for(int i=0;i<k;i++)
  {
    cin >> a;
    v1.pb(a);  
    dead[a]++;
  }
  //cout << v1[0] << v1[1] << endl;
  dbs();
  cout <<ans << endl;
}

