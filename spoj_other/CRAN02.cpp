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

vector <ll> v;
vector <ll> csum;
map <ll,ll> m;
void solve()
{
  ll n;
  cin >> n;
  ll cnt = 0;
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
  }
  for(ll i=0;i<n;i++)
  {
    i==0 ? csum.pb(v[i]) : csum.pb(csum[i-1]+v[i]);
    if(m.find(csum[i]) == m.end())
      m[csum[i]] = 1;
    else
      m[csum[i]]++;
  }
  ll res = 0;
  map <ll,ll> :: iterator itr = m.begin();
  while(itr!=m.end())
  {
    int n = (*itr).second;
    res = res + (ll)n*(n-1)/2;
    itr++;
  }
  cout << res+m[0] << endl;  
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    v.clear();
    m.clear();
    csum.clear();
  }
}

