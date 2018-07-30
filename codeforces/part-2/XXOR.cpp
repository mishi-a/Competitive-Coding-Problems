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

int arr[100005];
int dp[35][100005];

int main()
{
  sync;
  int n,q;
  cin >> n >> q;
  for(int i=1;i<=n;i++)
  {
  	cin >> arr[i];
  	for(int j=0;j<31;j++)
  	{
  		if(arr[i]&(1<<j))
  			dp[j][i]=1;
  	}
  }
  for(int i=0;i<31;i++)
  {
  	for(int j=1;j<=n;j++)
  	{
  		dp[i][j]+=dp[i][j-1];
  	}  
  }
  int ans;
  while(q--)
  {
  	int l,r;
  	cin >> l >>r;
  	ans = 0;
  	for(int i=0;i<31;i++)
  	{
      int n1 = dp[i][r]-dp[i][l-1];
      int n0 = r-l+1-n1;
      //cout << i << " " << n1 <<" " << n0 << endl;
      if(n0>n1)
      {
      	ans = ans|(1<<i);
      	//cout << ans << endl;
      }
  	}
  	cout << ans << endl;
  }
}
