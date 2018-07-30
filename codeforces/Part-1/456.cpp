#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
#define mp make_pair

using namespace std;

const ll size = 1e5+7;

vector <ll> cnt(size,0);
vector <ll> dp(size,0);

ll max(ll a,ll b)
{
  return a<b ? b : a;
}

int main()
{
  sync;
  ll n,a;
  cin >> n;
  for(ll i = 0;i<n;i++)
  {
    cin >> a;
    cnt[a]++;
  }
  dp[0] = 0;
  dp[1] = cnt[1];
  for(ll i = 2;i<size;i++)
  {
    dp[i] = dp[i-1];
    dp[i] = max(dp[i],dp[i-2]+i*cnt[i]);
  }
  cout << dp[size-1] << endl;
}
