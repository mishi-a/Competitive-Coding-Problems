/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
string s;
int dp[6200][6200] = {0};
int calc(int start,int end)
{
  int ans;
  if(dp[start][end]!=0)
     return dp[start][end];
  if(start > end)
  { 
    return 0;
  }
  else
  {
    if(s[start] == s[end])
      ans = calc(start+1,end-1);
    else
      ans = min(1+calc(start,end-1),1+calc(start+1,end));
  }
  dp[start][end] = ans;
  return ans;
  
}

void solve()
{
  cin >> s;
  int len = s.length();
  int res = calc(0,len-1);
  cout << res << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    memset(dp,0,sizeof(dp));
  }
}

