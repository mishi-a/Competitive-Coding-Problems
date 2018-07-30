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

int arr[30005] = {0};
int mux = -1;
int dp[30005][505];
int x;
int solve(int d,int p)
{
  int jj = p - (x-245);
  if(d>mux)
    return 0;
  if(dp[d][jj]!=-1)
    return dp[d][jj];
  else 
  {
    //cout << d << " " << p << endl;
    int ans1 = 0,ans2 = 0,ans3 = 0;
    if(p>1)
        ans1 = arr[d]+solve(d+p-1,p-1);
    if(p>-1)
        ans2 = arr[d]+solve(d+p+1,p+1);
    if(p>0)
        ans3 = arr[d]+solve(d+p,p);
    int ans = max(max(ans1,ans2),ans3);
    return (dp[d][jj] = ans);
  }
}

int main()
{
  sync;
  int n;
  cin >> n >> x;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    if(a > mux)
      mux = a;
    arr[a]++;
  }
  //cout << mux << endl;
  cout << solve(x,x) << endl;
}

