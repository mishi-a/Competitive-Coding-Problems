#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int main()
{
  sync;
  int n;
  cin >> n;
  vector <pii > v;
  for(int i=0;i<n;i++)
  {
    int x,y;
    cin >> x >> y;
    v.pb(make_pair(x,y));
  }
  sort(v.begin(),v.end());
  int mun = min(v[0].first,v[0].second);
  for(int i=1;i<n;i++)
  {
    if(v[i].second >=mun)
      mun = v[i].second;
    else
      mun = v[i].first;
  }
  cout << mun << endl;
}
