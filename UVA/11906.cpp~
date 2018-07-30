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
vector <int> x;
vector <int> y;
int arr[105][105];
int vis[105][105];
int mark[105][105];
int w,R,C,m,n;
void dfs(int r,int c)
{
  vis[r][c]=1;
  int cnt=0;
  set <pii > s;
  for(int i=0;i<8;i++)
  {
    if(r+y[i]<R && r+y[i]>=0 && c+x[i]<C && c+x[i]>=0 && arr[r+y[i]][c+x[i]]!=1 )
    {
      if(s.find({r+y[i],c+x[i]})==s.end())
        cnt++;
      s.insert({r+y[i],c+x[i]}) ; 
      if(vis[r+y[i]][c+x[i]]==0)
      {
        dfs(r+y[i],c+x[i]);
      }
      
    }
  }
  if(cnt%2==0)
  {
    mark[r][c]=2;
  }
  else 
    mark[r][c]=1;
}

int main()
{
  sync;
  int t;
  cin >> t;
  int tot=0;
  while(t--)
  {
    tot++;
    cin >> R >> C >> m >> n;
    x.pb(m),x.pb(m),x.pb(-m),x.pb(-m),x.pb(n),x.pb(-n),x.pb(n),x.pb(-n);
    y.pb(n),y.pb(-n),y.pb(n),y.pb(-n),y.pb(m),y.pb(m),y.pb(-m),y.pb(-m);
    cin >> w;
    memset(arr,0,sizeof(arr));
    memset(vis,0,sizeof(vis));
    memset(mark,0,sizeof(mark));
    for(int i=0;i<w;i++)
    {
      int a,b;
      cin >> a >> b;    
      arr[a][b]=1;
    }
    dfs(0,0);
    int cnt=0,cnt1=0;
    for(int i=0;i<R;i++)
    {
      for(int j=0;j<C;j++)
      {
        if(mark[i][j]==2)
          cnt++;
        else if(mark[i][j]==1)
          cnt1++;
      }
    }
    cout << "Case " << tot << ": " ;
    cout << cnt << " " << cnt1 << endl;
    x.clear();
    y.clear();
  }
}

