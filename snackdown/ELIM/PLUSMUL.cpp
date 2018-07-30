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

ll func(ll ind,int sym)
{ 
  ll res1,res2;
  if(v.size()-1-ind == 0&&sym == 0)
  {
    return v[ind];
  }
   if(v.size()-1-ind == 0&&sym == 1)
  {
    return v[ind]*v[ind-1];
  }
  else
   {
    if(sym == 0)
      res1 = (pow(2,v.size()-2-ind)*v[ind]+func(ind+1,0));
    else
      res1 = (pow(2,v.size()-2-ind)*v[ind]*v[ind-1]+func(ind+1,0));
    cout << res1 << endl;
    if(sym == 0)
      res2 = pow(2,v.size()-2-ind)*func(ind+1,1);
    else
      res2 = pow(2,v.size()-2-ind)*v[ind-1]*func(ind+1,1);
    cout << res2 << endl;
   }
   return res1+res2;
}

void solve()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
  }
  ll res = func(0,0);
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

