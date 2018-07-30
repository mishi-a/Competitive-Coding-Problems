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
#define INF 2000
using namespace std;

int pf[15][15];
int pt[15][15];

int n,m;
int ans[15][15][210];
int vis[15][15][210];

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin >> pf[i][j]; 
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin >> pt[i][j];
      }
    }
    memset(ans,-1,sizeof(ans));
    
    priority_queue <pair<int,pair<pii,int> > , vector <pair<int,pair<pii,int> >>,greater <pair<int,pair<pii,int> >> > pq;
    pq.push({pf[1][1],{{1,1},pt[1][1]}});
    ans[1][1][pt[1][1]] = pf[1][1];
    while(!pq.empty())
    {
      pair<int,pair<pii,int> >x = pq.top();
      pq.pop();
      int r = x.SE.FI.FI;
      int c = x.SE.FI.SE;
      int t = x.SE.SE;
      if(r+1<= n && c<=m)
      {
        if(ans[r][c][t]+pf[r+1][c] < ans[r+1][c][t+pt[r+1][c]] || ans[r+1][c][t+pt[r+1][c]] == -1 )
        {
             ans[r+1][c][t+pt[r+1][c]] = ans[r][c][t]+pf[r+1][c];
               pq.push({ans[r+1][c][t+pt[r+1][c]],{{r+1,c},t+pt[r+1][c]}});
        }
      }
      if(r<= n && c+1<=m  )
      {
        if(ans[r][c][t]+pf[r][c+1] < ans[r][c+1][t+pt[r][c+1]] || ans[r][c+1][t+pt[r][c+1]]==-1)
        {
          
          ans[r][c+1][t+pt[r][c+1]] = ans[r][c][t]+pf[r][c+1];
          pq.push({ans[r][c+1][t+pt[r][c+1]],{{r,c+1},t+pt[r][c+1]}});
        }
      }
      if(r-1>= 1 && c<=m )
      {
        if(ans[r][c][t]+pf[r-1][c] < ans[r-1][c][t+pt[r-1][c]]||ans[r-1][c][t+pt[r-1][c]]==-1)
        {
          
          ans[r-1][c][t+pt[r-1][c]] = ans[r][c][t]+pf[r-1][c];
          pq.push({ans[r-1][c][t+pt[r-1][c]],{{r-1,c},t+pt[r-1][c]}});
        }
      }
      if(r<= n && c-1>=1)
      {
        if(ans[r][c][t]+pf[r][c-1] < ans[r][c-1][t+pt[r][c-1]]||ans[r][c-1][t+pt[r][c-1]]==-1)
        {
          ans[r][c-1][t+pt[r][c-1]] = ans[r][c][t]+pf[r][c-1];
          pq.push({ans[r][c-1][t+pt[r][c-1]],{{r,c-1},t+pt[r][c-1]}});
        }
      }
    }
    //cout <<mux << " " <<  tmux<< endl;
    int mux = 1000,tmux=1000;
    for(int i=1;i<205;i++)
    {
      if(ans[n][m][i] < mux && ans[n][m][i]!=-1)
      {
        mux = ans[n][m][i];
        tmux = i;
      }
      if(ans[n][m][i] == mux && ans[n][m][i]!=-1)
      {
        mux = ans[n][m][i];
        if(i<tmux)
          tmux = i;
      }
    }
    cout << mux << " " << tmux << endl;
  }
}

