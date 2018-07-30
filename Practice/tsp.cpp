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

int m[15][15];
int n;
int dp[15][1<<13];
int solve(int ind,int mask)
{
  int ans = INT_MAX;
  //cout << ind << " " << mask << endl;
  if(1)
  {
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
      if(mask&(1<<i))
           cnt++;
    }
    //cout << cnt << endl;
    if(cnt==n)
      return 0;
  }
  if(dp[ind][mask]!=-1)
    return dp[ind][mask];
  else
  {
    for(int i=0;i<n;i++)
    {
      if(i==0)
      {
    //    cout << "Hi" << endl;
        int cnt = 0;
        for(int j=1;j<n;j++)
        {
          if(mask&(1<<j))
           cnt++;
        }
        if(cnt==n-1)
        {
           ans = m[ind][i]+solve(i,mask|1);
           break;
        }
        else
          continue;
      }
      if(mask&(1<<i))
        continue;
      else
      {
        ans = min(ans,m[ind][i]+solve(i,mask|(1<<i)));
      }
    }
  }
  return (dp[ind][mask] = ans);
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cin >> m[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0) << endl;
  }
}

