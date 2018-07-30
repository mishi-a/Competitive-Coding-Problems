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

vector <int> v;
int dp[1008][1008];
int solve(int start,int end)
{
  int res;
  if(start > end)
  {
    return 0;
  }
  if(dp[start][end]!=0)
    return dp[start][end];
  {
    if(v[start+1] < v[end] && v[start] < v[end-1])
      res = max(v[start]+solve(start+1,end-1),v[end] + solve(start,end-2)); 
    if(v[start+1] >= v[end] && v[start] < v[end-1])
      res = max(v[start]+solve(start+2,end),v[end] + solve(start,end-2)); 
    if(v[start+1] < v[end] && v[start] >= v[end-1])
      res = max(v[start]+solve(start+1,end-1),v[end] + solve(start+1,end-1)); 
    if(v[start+1] >= v[end] && v[start] >= v[end-1])
      res = max(v[start]+solve(start+2,end),v[end] + solve(start+1,end-1)); 
    dp[start][end] = res;
    return res; 
  }
} 
int main()
{
  sync;
  int cnt = 0;
  while(1)
  {
    int n;
    cnt++;
    cin >> n;
    if(n == 0)
      break;
    else
    {
      memset(dp,0,sizeof(dp));
      int sum = 0;
      for(int i=0;i<n;i++)
      {
        int a;
        cin >> a;
        v.pb(a);
        sum+=a;
      }
      int res = solve(0,n-1);
      cout << "In game " << cnt << ", the greedy strategy might lose by as many as " << 2*res-sum << " points. " << endl;
      v.clear();
    }
  }
}

