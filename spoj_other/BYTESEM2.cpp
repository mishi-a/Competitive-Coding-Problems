#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

vector <vector<int> > v(105,vector<int>(105,0));
int h,w;
int dp[105][105];
int find(int i,int col)
{
  int res = 0;
  
  if(col>h)
    return 0;
  if(i <= 0 || i>w)
    return 0;
  if(dp[col][i]!=-1)
    return dp[col][i];
  if(i > 1 && i < w)
  {
      res += v[col][i] + max(max(find(i-1,col+1),find(i,col+1)),find(i+1,col+1));
  }
  else if(i==1)   
  {
      res += v[col][i] + max(find(i,col+1),find(i+1,col+1));
  }
  else
  {
     res += v[col][i] + max(find(i,col+1),find(i-1,col+1));
  }
  dp[col][i] = res;
  return res;
}

void solve()
{
  cin >> h >> w;
  for(int i=1;i<=h;i++)
  {
    for(int j=1;j<=w;j++)
    {
      cin >> v[i][j];
    } 
  }
  int res  ;
  int mux = -2;
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=w;i++)
  {
    res = 0;
    if(i > 1 && i < w)
    {
      res += v[1][i] + max(max(find(i-1,2),find(i,2)),find(i+1,2));
    }
    else if(i==1)
    {
     res += v[1][i] + max(find(i,2),find(i+1,2));
    }
    else
    {
     res += v[1][i] + max(find(i,2),find(i-1,2));
    }
    if(res > mux)
      mux = res;
  }
  cout << mux << endl;
  for(int i=0;i<105;i++)
    fill(v[i].begin(),v[i].end(),0);
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}
