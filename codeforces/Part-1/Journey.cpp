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

vector <int> v[100005];
int visited[100005];
int d[100005];
vector <int > e;
ll r[100005];
int par[100005];
vector <double> prob(100005);
void dfs(int node,int depth)
{
  d[node] = depth;
  visited[node]=1;
  if(par[node] ==1)
  {
     //cout << node << " " << par[node] << " " << v[par[node]].size() << " " << depth << " " << prob[par[node]] << endl;
     prob[node] = ((1.0)/v[par[node]].size())*prob[par[node]];
  }
  else if(node!=1)
  {
     prob[node] = ((1.0)/(v[par[node]].size()-1))*prob[par[node]];
  }
  int cnt = 0;
  for(int i=0;i<v[node].size();i++)
  {
    if(visited[v[node][i]]==0)
    {
      cnt++;
            par[v[node][i]] = node;
      dfs(v[node][i],depth+1);

    }
  }
  if(cnt == 0)
    e.push_back(node);
}


int main()
{
  sync;
  int n,a,b;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  par[1]=-1;
  prob[1]=1.0;
  d[1] = 0;
  dfs(1,0);
  double res=0.0;
  
  for(int i=0;i<e.size();i++)
  {
    int node = e[i];
    //cout << node << endl;
    //cout << den << endl;
  
   res += prob[node]*d[node];    
  } 
   cout << fixed << setprecision(10); 
  cout << res << endl;
}

