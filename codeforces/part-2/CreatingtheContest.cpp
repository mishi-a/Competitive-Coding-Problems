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
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
int arr[200005];
int n;
int dp[200005];
int solve(int idx)
{
	int ans = 0;
	if(idx == n)
		return 0;
	if(dp[idx]!=-1)
		return dp[idx];
	else
	{
		for(int i=idx+1;i<n;i++)
		{
			if(arr[i]<=2*arr[idx])
			{
				ans = max(ans,1+solve(i));
				break;
			}
			else
			{
				return 0;
			}
		}
	}
	return (dp[idx] = ans);
}

int main()
{
  sync;
  cin >> n;
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  int ans = -1;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)
  {
  	ans = max(ans,1+solve(i));
  }
  cout << ans << endl;
  
}
