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
int n,ts,tf;
vector <pair<int,pii > > v;
int dp[2005][5005];
int solve(int start,int time)
{
  int ans = -1;
  if(time > tf)
  {
    return -2005;
  }
  if(start == n-1)
  {
    return 0;
  } 
  if(dp[start][time]!=-1)
    return dp[start][time];
  else
  {
     int ans1,ans2;
     if(time + ts <= v[start].FI)
     {
       ans1 = 1+solve(start+1,v[start].FI+v[start].SE.SE);
     }
     else
     {
       int rtime = ceil(((time + ts - v[start].FI)*1.0)/v[start].SE.FI)*v[start].SE.FI + v[start].FI;
       ans1 = 1+solve(start+1,rtime+v[start].SE.SE);
     }
     if(time <= v[start].FI)
       ans2 = solve(start+1,v[start].FI+v[start].SE.SE);
     else
     {
       int rtime = ceil(((time-v[start].FI)*1.0)/v[start].SE.FI)*v[start].SE.FI + v[start].FI;
       ans2 = solve(start+1,rtime+v[start].SE.SE);
     }
        ans = max(ans1,ans2);
  }

  return (dp[start][time] = ans);
}

int main()
{
  sync;
  int t;
  cin >> t;
  int cnt = 0;
  while(t--)
  {
    memset(dp,-1,sizeof(dp));
    cnt++;
    cin >> n >> ts >> tf;
    for(int i=0;i<n-1;i++)
    {
      int a,b,c;
      cin >> a >> b >> c;
      v.pb({a,{b,c}});
    }
    int ans = solve(0,0);
    if(ans < 0)
      cout << "Case #" << cnt <<":" <<" IMPOSSIBLE" << endl;
    else
      cout << "Case #" << cnt <<": " << ans << endl;
    v.clear();
  } 
}

