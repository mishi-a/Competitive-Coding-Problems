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
int y[] = {0,0,1,-1};
int grid[1005][1005];
int shortest[1005][1005];
int si,sj;
int n,m,q;
void bfs()
{
	queue<pii> q;
	q.push({si,sj});
    shortest[si][sj]=0;
	while(!q.empty())
	{
		pii val = q.front();
		int row = val.FI;
		int col = val.SE;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int r = row+x[i];
			int c = col+y[i];
			if(r>=0&&c>=0&&r<n&&c<m)
			{
				if(grid[r][c]==0)
					shortest[r][c]=-1;
				else if(shortest[r][c]==-1)
				{
					shortest[r][c]=shortest[row][col]+1;
					q.push({r,c});
				}
			}	
		}
	}
}

int main()
{
  sync;

  cin >> n >> m >> q;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		char ch;
  		cin >> ch;
  		if(ch == '*')
  			grid[i][j]=0;
  		else
  			grid[i][j]=1;
  	}
  }
  memset(shortest,-1,sizeof(shortest));
 
  cin >> si >> sj;
  si--,sj--;
  bfs();
  while(q--)
  {
  	int di,dj;
  	cin >> di >> dj;
  	di--,dj--;
  	cout << shortest[di][dj] << endl;
  } 
}
