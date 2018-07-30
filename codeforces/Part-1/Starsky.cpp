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

int arr[105][105][11];
int csum[105][105][11];
int main()
{
  sync;
  int n,q,c;
  //memset(arr,0,sizeof(arr));
  cin >> n >> q >> c;
  for(int i=0;i<n;i++)
  {
    int x,y,s;
    cin >> x >> y >> s;
    for(int j=0;j<=c;j++)
    {
      s+j > c ? arr[x][y][j] = (s+j)%c :arr[x][y][j] = s+j  ;
      if(s+j>c)
        s = (s+j)%c;
    }
  }
  for(int i=0;i<=c;i++)
  {
    for(int k=0;k<=100;k++)
    {
      k == 0 ? csum[0][k][i] = arr[0][0][i] : csum[0][k][i]=csum[0][k-1][i]+arr[0][k][i];
    }
    for(int j=1;j<=100;j++)
    {
      int sum = 0;
      for(int k=0;k<=100;k++)
      {
        sum+=arr[j][k][i];
        csum[j][k][i] = csum[j-1][k][i] + sum;
      }
    }
  }
  for(int i=0;i<q;i++)
  {
    int t,x1,y1,x2,y2;
    cin >> t >> x1 >> y1 >>x2 >> y2;
    {
      t = t%(c+1);
      cout << csum[x2][y2][t] - csum[x1-1][y2][t] -(csum[x2][y1-1][t]-csum[x1-1][y1-1][t]) << endl;    
    }
  }
   
}

