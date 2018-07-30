#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int dp[2005][20005];

string a,b;

void solve()
{
  cin >> a >> b;
  memset(dp,0,sizeof(dp));
  for(int i=0;i<=b.size();i++)
  {
    for(int j=0;j<=a.size();j++)
    {
      if(i == 0)
      {
        dp[i][j] = j;
        continue;
      }
      if(j==0)
      {
        dp[i][j] = i;
        continue;
      }
      else if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + min(min(dp[i-1][j-1],dp[i][j-1]),min(dp[i][j-1],dp[i-1][j]));
    }
  }
  cout << dp[b.size()][a.size()] << endl;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}
