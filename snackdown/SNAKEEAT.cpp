#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

vector <ll> v;
vector <ll> csum;
ll n;
ll mux;
bool func(ll mid,ll k)
{
  vector <ll> :: iterator itr = lower_bound(v.end()-mid,v.end(),k);
  if(itr == v.end())
  {
    if(mid == 1)
    {
      if(k - v[v.size()-1] <= v.size()-mid )
        return true;
      else
        return false;
    }
    else
    {
      ll i1 = v.size()-1;
      ll i2 = v.size()-mid;
      if(i2 == 0)
      {
        return false;
      }
      else
      {
        if(mid*k - (csum[i1]-csum[i2-1]) <= i2)
          return true;
        else
          return false;
      }
    }
  }
  else
  {
    ll index = itr-v.begin();
    if(index-1 < v.size()-mid)
      return true;
    while(index--)
    {
      if(v[index] < k)
        break;
    }
    ll width = index-(v.size()-mid);
    if(width == 0)
    {
      if(k-v[index] <= index)
      {
        return true;
      }
      else
        return false;
    }
    else
    { 
      ll i1 = index;
      ll i2 = v.size()-mid;
      if(i2 == 0)
      {
        if(v[0] < k)
          return false;
        else
          return true;
      }
      else
      {
        if((width+1)*k - (csum[index]-csum[i2-1]) <= i2)
          return true;
        else
          return false;
      }
    } 
  }
}
void dbs(ll k)
{
  ll l=0,r= n;
  //cout << n << endl;
  ll mid;
  mux = -1;
  while(l<=r)
  {
    mid = (l+r)/2;
    //cout << "mid  " << mid << endl;
    if(func(mid,k) == true)
    {
       if(mid > mux)
       {
         mux = mid;
         //cout << mux << endl;
       }
       l = mid+1;
       //cout << "mid + " << mid << endl;
    }
    else
    {
       r = mid-1;
       //cout << "mid - " << mid << endl;
    }
  }
}

void resolve_query()
{
  ll k;
  cin >> k;
  dbs(k);
}

void solve()
{
  ll q,x;
  cin >> n >> q;
  for(ll i=0;i<n;i++)
  {
    cin >> x;
    v.pb(x);
  }
  sort(v.begin(),v.end());
  for(ll i=0;i<n;i++)
  {
    i==0 ? csum.pb(v[i]) : csum.pb(v[i]+csum[i-1]);
  }
  while(q--)
  {
    resolve_query();
    if(mux!= -1)
     cout << mux << endl;
    else
     cout << "0" << endl;
  }
  v.clear();
  csum.clear();
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}
