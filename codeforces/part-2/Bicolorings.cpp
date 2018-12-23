/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
int n,k;
ll mod = 998244353;
int dp[2][2][2005][1005];
ll solve(int t,int b,int k,int level)
{
	//cout << t << " "<< b << " "<< k << " " << level << endl;
	if(k<0)
		return 0;
	if(level > n && k!=0)
		return LLONG_MIN;
		ll ans = 0;	
	if(level>n && k == 0)
		return 1;
	if(dp[t][b][k][level]!=-1)
		return dp[t][b][k][level];
	  for(int i=0;i<4;i++)
	  {
	  	int t1 = k;
	  	if(t != b && t == ((i>>1)&1) && (i&1) == b )
	  		t1-=2;
	  	else if(t == b && ((i>>1)&1) == (i&1) && t!=((i>>1)&1))
	  		t1-=1;
	  	else if(t == b && ((i>>1)&1) != (i&1))
	  		t1-=1;
	  	else 
	  		t1 = t1;
	  	ll val = solve(i&1,(i>>1)&1,t1,level+1);
	  	if(val < 0)
	  		val =0;
	  	ans = (ans + val)%mod;
	  }  
	  dp[t][b][k][level]=ans%mod;
	  //cout << t << b << k << level << endl;
	  return (ans%mod);
}

int main()
{
  sync;
  cin >> n >> k;
  ll ans = 0;
  memset(dp,-1,sizeof(dp));
  //cout << dp[0][0][0][0] << endl;
  for(int i=0;i<4;i++)
  {
  	int t = k;
  	if((i&1) != ((i>>1)&1))
  		t-=2;
  	else
  		t--;
  	ll val = solve(i&1,(i>>1)&1,t,2);
  	if(val < 0)
  		val = 0;
  	ans = (ans + val)%mod;
  }  
  cout << ans%mod << endl;
}
