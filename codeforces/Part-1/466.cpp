#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <ll> v;
vector <ll> csum;
ll dp[600000] = {0};
int main()
{
  sync;
  ll sum = 0;
  int n,p;
  ll cunt = 0;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    ll x;
    cin >> x;
    v.pb(x);
    sum+=x;  
  }
  if(sum%3 != 0)
  {
    cout << "0" << endl;
    return 0;
  }
  ll nsum = 0;
  for(int i = n-1;i>=0;i--)
  {
    nsum+=v[i];
    if(nsum == sum/3)
      dp[i] = 1;
  }
  nsum = 0;
  for(int i=0;i<n;i++)
  {
    i==0 ? csum.pb(dp[i]) : csum.pb(csum[i-1]+dp[i]);
  }
  nsum = 0;
  for(int i=0;i<n-2;i++)
  {
    nsum+=v[i];
    if(nsum == sum/3)
    {
      cunt+=(csum[n-1]-csum[i+1]);
    }
  }
  cout << cunt << endl;
  
  
  
}
