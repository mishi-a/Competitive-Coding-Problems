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

char arr[505][505];
int mark[505][505] = {0};
int cnt = 0;
int n,m,k;
queue <pii > q;
int tot = 1;
void bfs()
{
  
  while(!q.empty())
  {
    int r = q.front().FI;
    int c = q.front().SE;
    q.pop();
    if(r-1 >= 0 && arr[r-1][c] == '.')
    {
      if(mark[r-1][c] == 0)
      {
        q.push({r-1,c});
        if(tot == cnt - k )
          break;
        mark[r-1][c] = 1;
        tot++;
      }
    }
    if(r+1 < n && arr[r+1][c] == '.')
    {
      if(mark[r+1][c] == 0)
      {
        q.push({r+1,c});
        if(tot == cnt - k )
          break;
        mark[r+1][c] = 1;
         tot++;
      }
    }
    if(c-1 >= 0 && arr[r][c-1] == '.')
    {
      if(mark[r][c-1] == 0)
      {
        q.push({r,c-1});
        if(tot == cnt - k )
          break;
        mark[r][c-1] = 1;
         tot++;
      }
    }
    if(c+1 < m && arr[r][c+1] == '.')
    {
      if(mark[r][c+1] == 0)
      {
        q.push({r,c+1});
        if(tot == cnt - k )
          break;
        mark[r][c+1] = 1;
         tot++;
      }
    }
  }
}

int main()
{
  sync;

  cin >> n >> m >> k;
  int r,c;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> arr[i][j];
      if(arr[i][j] == '.')
      {
        r = i;
        c = j;
        cnt++;
      }
    }
  }
  if(tot == 0)
  {
    for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      cout << arr[i][j] ;
    } 
    cout << endl;
    }
    return 0;
  }
  q.push({r,c});
  mark[r][c] = 1;
  bfs();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j] == '#')
        cout << arr[i][j] ;
      else if(arr[i][j] == '.' && mark[i][j] == 1)
        cout << "." ;
      else
        cout << "X";
    } 
    cout << endl;
  }
}

