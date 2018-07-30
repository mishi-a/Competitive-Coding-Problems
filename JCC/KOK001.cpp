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

vector <int> v;
vector <int> g[10005];
vector <int> v1;
vector <int> v2;
void printspiral(int node,int cnt)
{
  
  while(v1.size()!=0||v2.size()!=0)
  {
    if(cnt%2==0)
    {
     cnt++;
     for(int i=v2.size()-1;i>=0;i--)
       cout << v2[i] << " ";
     for(int i=0;i<v2.size();i++)
      {
        if(g[v2[i]].size()==1)
          v1.pb(g[v2[i]][0]);
        if(g[v2[i]].size()==2)
          v1.pb(g[v2[i]][0]),v1.pb(g[v2[i]][1]);
      }        
      v2.clear();
    }
    else
    {
      for(int i=0;i<v1.size();i++)
        cout << v1[i] << " ";
      for(int i=0;i<v1.size();i++)
      {
        if(g[v1[i]].size()==1)
          v2.pb(g[v1[i]][0]);
        if(g[v1[i]].size()==2)
          v2.pb(g[v1[i]][0]),v2.pb(g[v1[i]][1]);
      }
      cnt++;
      v1.clear();
    }
  }
  
}
void postorder(int node)
{

  if(g[node].size()>=1)
    postorder(g[node][0]);
  if(g[node].size()==2)
    postorder(g[node][1]);
  cout << node << " ";  
}
int main()
{
  sync;
  int t,x;
  cin >> t;
  while(t--)
  {
    int n;
    v.pb(-1);
    cin >> n;
    for(int i=0;i<n;i++)
      cin >> x, v.pb(x);
    for(int i=1;i<=n;i++)
    {
      if(2*i<=n)
       g[v[i]].pb(v[i<<1]);
      if(2*i+1<=n) g[v[i]].pb(v[(i<<1)+1]);
    }
    v1.pb(v[1]);
    printspiral(v[1],1);
    v.clear();
    v1.clear();
    v2.clear();
    cout << endl;   
    postorder(v[1]);
    cout << endl; 
    for(int i=0;i<=10002;i++)
      g[i].clear();        
  }
}

