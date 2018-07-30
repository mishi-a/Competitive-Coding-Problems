/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push
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

queue <pii > q;
int v[10][10];
int d[10][10];
void solve()
{   
  string src,dest;
  cin >> src >> dest;
  int xsrc = src[0]-'a';
  int ysrc = src[1]-'0'-1;
  int xdest = dest[0]-'a';
  int ydest = dest[1]-'0'-1;
  q.push({xsrc,ysrc});
  while(!q.empty())
  {
    int x = q.front().FI;
    int y = q.front().SE;
    v[x][y] = 1;
      if(x+2 < 8 && y+1 < 8)
      {
        if(v[x+2][y+1]!=1)
        {
          d[x+2][y+1] = d[x][y]+1;
          v[x+2][y+1] = 1;
          q.pb({x+2,y+1});
        }
      }
      if(x+2 < 8 && y-1 >= 0)
      {
        if(v[x+2][y-1]!=1)
        {
          d[x+2][y-1] = d[x][y]+1;
          v[x+2][y-1] = 1;
          q.pb({x+2,y-1});
        }
      }
      if(x-2 >= 0 && y+1 < 8)
      {
        if(v[x-2][y+1]!=1)
        {
          d[x-2][y+1] = d[x][y]+1;
          v[x-2][y+1] = 1;
          q.pb({x-2,y+1});
        }
      }
      if(x-2 >= 0 && y-1 >= 0)
      {
        if(v[x-2][y-1]!=1)
        {
          d[x-2][y-1] = d[x][y]+1;
          v[x-2][y-1] = 1;
          q.pb({x-2,y-1});
        }
      }
      if(x+1 < 8 && y+2 < 8)
      {
        if(v[x+1][y+2]!=1)
        {
          d[x+1][y+2] = d[x][y]+1;
          v[x+1][y+2] = 1;
          q.pb({x+1,y+2});
        }
      }
      if(x-1 >= 0 && y+2 < 8)
      {
        if(v[x-1][y+2]!=1)
        {
          d[x-1][y+2] = d[x][y]+1;
          v[x-1][y+2] = 1;
          q.pb({x-1,y+2});
        }
      }
      if(x+1 < 8 && y-2 >= 0)
      {
        if(v[x+1][y-2]!=1)
        {
          d[x+1][y-2] = d[x][y]+1;
          v[x+1][y-2] = 1;
          q.pb({x+1,y-2});
        }
      }
      if(x-1 >= 0 && y-2 >=0)
      {
        if(v[x-1][y-2]!=1)
        {
          d[x-1][y-2] = d[x][y]+1;
          v[x-1][y-2] = 1;
          q.pb({x-1,y-2});
        }
      }
     q.pop();
    
  }
  cout << d[xdest][ydest] << endl;
  
}    

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    memset(v,0,sizeof(v));
    memset(d,0,sizeof(d));
    solve();
    q = queue <pii > ();
  }
}

