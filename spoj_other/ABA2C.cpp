/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
#define inf 10000007
using namespace std;

vector <int> v;
int dp[110][110];

int solve(int start,int end,int k)
{
  if(dp[start][k]!=0)
    return dp[start][k];
  if(start > end && k!=0)
    return 1000000;
  if( k==0)
  {
    return 0;
  }
  if(k < 0)
  {
    return 1000000;
  }
  while(v[start] == -1)
  {
    start++;
    if(start > end)
      return 1000000;
  }
  int res = min(v[start]+solve(start,end,k-(start+1)),solve(start+1,end,k));
  dp[start][k] = res;
  return res;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    memset(dp, 0, sizeof(dp));
    //cout << dp[100][100][100] << endl;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
      int a;
      cin >> a;
      v.pb(a);
    }
    int res =  solve(0,v.size()-1,k) ;
    res >= 1000000 ? cout << "-1" << endl : cout << res << endl;
    v.clear();   
  }
}

