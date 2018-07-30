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
#define mod 1000000007
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
using namespace std;

int n;
int dp[2005][2005];
int solve(int start,int k)
{
  if(dp[start][k]!=0)
    return dp[start][k];

  if(k == 0)
  {
    return 1;
  }
  int j = 1,tot = 0;
  for(int i = start;i<=n;i = start*j)
  {
    tot = (tot%mod + solve(i,k-1)%mod)%mod;
    j++;
  }
  dp[start][k] = tot%mod;
  return tot;
}

int main()
{
  sync;
  int k;
  cin >> n >> k;
  int tot = 0;
  memset(dp,0,sizeof(dp));
  for(int i =1;i<=n;i++)
  {
    tot = (tot%mod + solve(i,k-1)%mod)%mod;
    //cout << tot << endl;
  }
  cout << tot%mod << endl;
}

