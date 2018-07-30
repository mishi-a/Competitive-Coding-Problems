#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
using namespace std;

map < ll,ll > mp;
map <ll,ll >:: iterator itr;
ll maxm(ll n)
{

  ll value;
  itr = mp.find(n);
  if(itr!=mp.end())
  {
    return itr->second; 
  }
  if(n < 12)
    return n;
  else
  {
    ll res = maxm(n/2) + maxm(n/3) + maxm(n/4);
    value = max(n,res);
  }
  mp.insert(make_pair(n,value));
  return value;
}

int main()
{
  sync;
  ll n;
  while(cin >> n)
  {
    ll ans = maxm(n);
    cout << ans << endl;
  } 
}
