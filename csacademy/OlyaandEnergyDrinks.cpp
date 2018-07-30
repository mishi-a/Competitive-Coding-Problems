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


using namespace std;

int x[] = {1,-1,0,0};
int y[] = {0,0,-1,1};

vector <vector<char>> v(1001);
int dist[1001][1001];
pii par[1001][1001];
int main()
{
  sync;
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		char c;
  		cin >> c;
  		v[i].pb(c);dist[i][j]=1e9;
  	}
  }
 // memset(dist,-1,sizeof(dist));
  memset(par,-1,sizeof(par));
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--,x2--,y1--,y2--;
  if(v[x1][y1]=='#'||v[x2][y2]=='#')
  {
    cout << "-1" << endl;
    return 0;
  }
  dist[x1][y1]=0;
  queue<pii> q;
  q.push({x1,y1});
  while(!q.empty())
  {
    pii cur = q.front();
    q.pop();
    int px = cur.FI,py=cur.SE;
    for(int i=0;i<4;i++)
    {
      for(int j=1;j<=k;j++)
      {
        int xx = px + j*x[i],yy = py+j*y[i];
        //cout << xx << " " << yy << endl;
        if(xx<0 || yy <0 || xx>=n || yy>=m)
          break;
        if(v[xx][yy]=='#'||dist[xx][yy]<1+dist[px][py])
          break;
        
        
        if(dist[xx][yy]==1e9)
          q.push({xx,yy}),dist[xx][yy] = 1+dist[px][py];
      }
      
      
    }
  }
  if(dist[x2][y2]!=1e9)
  {
  	cout << dist[x2][y2] << endl;
  } 
  else
  	cout << "-1" << endl;
}