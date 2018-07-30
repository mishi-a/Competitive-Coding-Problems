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


//D-S-U


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

int par[1000005];
vector <int > v1;
int dp[1005][1005];

int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))    return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}


int solve(int start,int end)
{
  if(start > end)
    return 0;
  if(start == end)
    return 1;
  if(dp[start][end]!=0)
    return dp[start][end];
  int ans;
  if(v1[start] == v1[end])
  {
    ans = 2 + solve(start+1,end-1);
  }
  else
  {
       if(root(v1[start]) == root(v1[end]))
         ans = 2 + solve(start+1,end-1);
       else
         ans = max(solve(start+1,end),solve(start,end-1));
    }
  
  //cout << start << "  " << end << " " << ans << endl;
  dp[start][end] = ans;
  return ans;
}

int main()
{
  sync;
  int n,k,m;
  memset(dp,0,sizeof(dp));
  memset(par,-1,sizeof(par));
  cin >> n >> k >> m;
  for(int i=0;i<k;i++)
  {
    int a,b;
    cin >> a >> b;
    merge(a,b);
  }  
  for(int i=0;i<m;i++)
  {
    int x;
    cin >> x;
    v1.pb(x);
  }
  int res = solve(0,v1.size()-1);
  cout << res << endl;
}

