#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <ll > v;

int main()
{
  sync;
  ll sum = 0;
  ll n,f,k,l;
  cin >> n >> f;
  for(ll i=0;i<n;i++)
  {
    cin >> k >> l;
    if(k > l)
    {
      v.pb(0);
      sum+=l;
    }
    else if( 2*k >= l)
    {
      v.pb(l-k);
      sum+=k;
    }
    else
    {
      v.pb(k);
      sum+=k;
    }
  }
  sort(v.begin(),v.end(),greater <ll> ());
  for(ll i=0;i<f;i++)
  {
    sum+=v[i];
  }
  cout << sum << endl;
}
