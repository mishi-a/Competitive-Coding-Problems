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
int arr[100005];
int n;
int dp[200][8000];
int solve(int idx,int wt)
{
  if(dp[idx][wt]!=-1)
    return dp[idx][wt];
  if(idx == n)
    return 0;
  if(wt == 0)
    return 0;
  else
  {
    int res=0;
    for(int i=idx;i<n;i++)
    {
      if(arr[i]<=wt)
      {
        res = max(res,max(1+solve(i+1,min(6*arr[i],wt-arr[i])),solve(i+1,wt)));
      }
    }
    //cout << idx <<"  " << wt << " " << res << endl;
    return (dp[idx][wt]=res);
  }
}
int main()
{
  sync;
  int t;
  cin >> t;
  int tc = 1;
  while(t--)
  {
    cout << "Case #" << tc << ": ";
    tc++;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=n-1;i>=0;i--)
      cin >> arr[i];
    int res = -1;
    for(int i=0;i<n;i++)
    {
       res = max(res,1+solve(i+1,6*arr[i]));
       //cout << res << endl;
    }
    cout << res << endl;
  }  
}