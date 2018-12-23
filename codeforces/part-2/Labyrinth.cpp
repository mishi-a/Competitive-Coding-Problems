/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second
#define INF 1e9
const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

ll x[] = {-1,1,0,0};
ll y[] = {0,0,1,-1};
ll arr[2005][2005],distl[2005][2005],distr[2005][2005],vis[2005][2005];
ll ml,mr,ans = 0,n,m;
struct location
{
  int row,col,left,right;
  location(int _row,int _col,int _l,int _r)
  {
    row = _row;
    col = _col;
    left = _l;
    right = _r;
  }
  bool operator<(location x) const
  {
    return x.left+x.right<left+right;
  }
};

bool valid(ll r,ll c)
{
  if(r>=1 && r<=n && c>=1 && c<=m && arr[r][c]!=1)
    return true;
  else
    return false;
}

int main()
{
  sync;
  cin >> n >> m;
  ll sr,sc;
  cin >> sr >> sc;
  cin >> ml >> mr;
  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
  		char ch;
  		cin >> ch;
  		if(ch == '.')arr[i][j]=0;
  		else arr[i][j] = 1;
      distl[i][j] = INF;
      distr[i][j] = INF;
  	}
  }
  priority_queue<location> pq;
  pq.push(location(sr,sc,0,0));
  while(!pq.empty())
  {
    location loc = pq.top();
    pq.pop();
    if(loc.left>ml || loc.right > mr || vis[loc.row][loc.col]) continue;
    ans++;
    vis[loc.row][loc.col]=1;
    for(int i=0;i<4;i++)
    {
      int nr = loc.row+x[i];
      int nc = loc.col+y[i];
      if(valid(nr,nc) && vis[nr][nc] == 0)
      {
        int le = 0,ri=0;
        if(nc<loc.col)
          le++;
        else if(nc > loc.col)
          ri++;
        if(distl[nr][nc]>loc.left+le )
        {
          distl[nr][nc] = loc.left+le;
          pq.push(location(nr,nc,loc.left+le,loc.right+ri));
        }
        if(distr[nr][nc]>loc.right+ri)
        {
         distr[nr][nc]=loc.right+ri;
         pq.push(location(nr,nc,loc.left+le,loc.right+ri)); 
        }
      }
    }
  }
  cout << ans << endl;
}