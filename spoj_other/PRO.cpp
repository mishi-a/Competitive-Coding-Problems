#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
using namespace std;
int main()
{
  sync;
  int t;
  cin >> t;
  multiset<int>::iterator it;
  multiset <ll> ms;
  ll res = 0;
  while(t--)
  {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
      ll x;
      cin >> x;
      ms.insert(x);
    }
    res = res-(*ms.begin()-(*(--ms.end())));
    ms.erase(ms.begin());
    ms.erase(--ms.end());
  }
  cout << res << endl;
}
