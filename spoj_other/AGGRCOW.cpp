#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
using namespace std;
vector <ll > v;
int c;
int pre(ll dist)
{
  int cunt = c-1;
  int prev = 0;
  for(int i=1;i<v.size();i++)
  {
    if(v[i]-v[prev] >= dist){
      cunt--;
      prev = i;
    }
  }
  if(cunt <= 0)
    return 1;
  else
    return 0;
}

ll dbs()
{
  int low = 0,high = v.size()-1;
  ll dist = v[high];
  ll max = -1;
  while(low <= dist)
  {
    int mid = low + (dist-low)/2;
    if(pre(mid))
    {
      if(mid>max)
        max = mid;
      low = mid+1;
    }
    else
    {
      dist = mid-1;
    }
  }
  return max;
}
void solve()
{
  int n;
  cin >> n >> c;

  for(int i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
  }
  sort(v.begin(),v.end());
  ll res = dbs();
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
    v.clear();
  }
}
