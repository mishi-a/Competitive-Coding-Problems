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
int mv[] = {2,2,-2,-2,1,1,-1,-1};
int mv1[] = {1,-1,1,-1,2,-2,2,-2};
char arr[50][50];
int seen[50][50];
int m,n;
vector < vector<pii> > match(50,vector<pii >(50,{-1,-1}));

bool isvalid(int r,int c)
{
  if(r>=0 && r<m && c>=0 && c<n&&arr[r][c]!='#')
    return true;
  else
    return false;
}

bool dfs(int r,int c)
{
  int x = r,y = c;
  if(seen[r][c] == 1)
    return false;
  seen[r][c] = 1;
  for(int i=0;i<8;i++)
  {
    r = x+mv[i];
    c = y+mv1[i];
    //cout << r << c << endl;
    if(isvalid(r,c))
    {
            if((match[r][c].FI == -1 && match[r][c].SE == -1) || dfs(match[r][c].FI,match[r][c].SE))
            {
               match[r][c].FI = x;
               match[r][c].SE = y;
               match[x][y].FI = r;
               match[x][y].SE = c;
               return true;       
            }
     }
  }
  return false;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> m >> n;
    int tot = 0;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin >> arr[i][j] ;
        if(arr[i][j] == '#')
          tot++;
      }
    }
    int res = 0;
    memset(seen,0,sizeof(seen));
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        
        if(arr[i][j]!='#' && (match[i][j].FI==-1 && match[i][j].SE ==-1) && dfs(i,j))
        { res++;}    
            
      }
    }
    cout << m*n - tot - res << endl;
    for(int i=0;i<50;i++)
    {
      for(int j=0;j<50;j++)
      {
        match[i][j] = {-1,-1};
      }
    }
  }
}

