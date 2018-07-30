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
int a[1005],b[2005];
int n,k,p;
int dp[1005][2005];
int solve(int astart,int bstart)
{
  int ans = 0;
  if(n-astart>k-bstart)
    return INT_MAX;
  if(astart == n)
  {
    return 0;
  }
  if(dp[astart][bstart]!=-1)
    return dp[astart][bstart];
  else
  {
    ans = min(max((abs(a[astart]-b[bstart])+abs(b[bstart]-p)),solve(astart+1,bstart+1)),solve(astart,bstart+1));
  }
  return (dp[astart][bstart] = ans);
}


int main()
{
  sync;
  cin >> n >> k >> p;
  for(int i=0;i<n;i++)
    cin >> a[i];
  for(int i=0;i<k;i++)
    cin >> b[i];
  memset(dp,-1,sizeof(dp));
  sort(a,a+n);
  sort(b,b+k);
  int res = solve(0,0);
  cout << res << endl;
}

