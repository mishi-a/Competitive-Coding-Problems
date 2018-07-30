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
int n;
int dp[2005][2005];
int solve(int start,int end)
{
  int tot = n - (end-start);
  if(dp[start][end]!=0)
    return dp[start][end];
  if(start == end)
  {
    dp[start][end] = v[start]*tot;
    return dp[start][end];
  }
  else
  {
     dp[start][end] =  max(v[start]*tot + solve(start+1,end),v[end]*tot + solve(start,end-1));
     return dp[start][end];
  }
}

int main()
{
  sync;
  cin >> n;
  memset(dp,0,sizeof(dp));
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  int res = solve(0,n-1);
  cout << res << endl;
}

