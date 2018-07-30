#include <iostream>
#include <vector>
#include <algorithm>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define mod 1000000009
using namespace std;

void solve()
{
  sync;
  cin.tie(NULL);
  long long int n,m;
  cin >> n >> m;
  long long res = 1;
  vector <pair <char,long long int> > v(1);
  for(int i = 0;i< m;i++)
  {
    char ch ;
    long long int x;
    cin >> ch >> x;
    v.push_back(make_pair(x,ch));
  }
  sort(v.begin(),v.end());
  for(long long int i=1;i<m;i++)
  {
    if(v[i+1].second == v[i].second)
    {
      continue;
    }
    int pt = v[i+1].first - v[i].first;
    //cout << pt << endl;
    res = res*pt;
    if(res > mod)
      res = res%mod;
    //res = ((res%mod)*(pt%mod))%mod;
  }
  cout << res%mod << endl;
}
 
int main()
{
  int t;
  cin >> t;
  while(t--)
    solve();
}
