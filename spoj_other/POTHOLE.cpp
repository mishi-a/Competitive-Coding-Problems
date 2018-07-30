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
#define INF 100000000
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
int graph[205][205];
  int parent[205] = {0};
  int n;  
bool path()
{
  bool visited[205] = {0};

  queue <int> q;
  q.push(1);
  visited[1] = true;
  while(!q.empty())
  {
    int u = q.front();
    for(int i=1;i<=n;i++)
    {
      if(!visited[i] && graph[u][i]>0)
      {
        q.push(i);
        parent[i] = u;
            visited[i] = true;
      }
    }

    q.pop();
  }
  if(visited[n])
    return true;
  else
    return false;
}
void solve()
{

  cin >> n;
  for(int i=1;i<n;i++)
  {
    int k ;
    cin >> k;
    for(int j=0;j<k;j++)
    {
      int a;
      cin >> a;
      if(i==1 || a == n)
         graph[i][a] = 1;
      else
         graph[i][a] = INF;
    }
  }
  int tot = 0;
  while(path())
  {

     int ans = 1000000;
     for(int i = n;i!=1;i=parent[i])
     {
       ans = min(ans,graph[parent[i]][i]);
     }
     for(int i = n;i!=1;i=parent[i])
     {
       graph[parent[i]][i]-=ans;
       graph[i][parent[i]]+=ans;
     }
     tot+= ans;
     memset(parent,0,sizeof(parent));
  }
  cout << tot << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    memset(graph,0,sizeof(graph));
    solve();

  }
}

