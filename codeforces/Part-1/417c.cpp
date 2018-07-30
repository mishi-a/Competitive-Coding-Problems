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
ll b[100005];
ll sum ;
bool func(ll k,ll n,ll s)
{
  sum = 0;
  for(int i=0;i<n;i++)
  {
    b[i] = v[i]+(i+1)*k;
  }
  sort(b,b+n);
  for(int i=0;i<k;i++)
     sum = sum + b[i];
  //cout << k << " " << sum << endl;
  if(sum > s)
    return false;
  else
    return true;
}

void dbs(ll n,ll s)
{
  ll l = 0, r = n;
  ll res = 0,tot = 0;
  while(l<=r)
  {
    ll mid = (l+r)/2;
    if(func(mid,n,s) == true)
    { // cout << mid << endl;
      if(mid > res)
      {
        res = mid;
        tot = sum;
      }
      l = mid+1;
    }
    else
    {
      r = mid-1;
    }
  
  }
  cout << res <<" " << tot <<  endl;
}


int main()
{
  sync;
  ll n,s,a;
  cin >> n >> s;
  for(int i=0;i<n;i++)
  {
    cin >> a;
    v.pb(a);
  }
  dbs(n,s);
}

