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
  int n,m;
  cin >> n >> m;
  vector <int> v;
  vector <int> v1;
  v.pb(-1);
  v1.pb(-1);
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
    v1.pb(a);
  }
  for(int i=0;i<m;i++)
  {
    int l,r,x;
    cin >> l >> r >> x;
    sort(v.begin()+l,v.begin()+r+1);
    if(v[x] == v1[x])
    {
      cout << "Yes" << endl;
    }
    else
      cout << "No" << endl;
    for(int i=l;i<=r;i++)
    {
      v[i] = v1[i];
    }
  }
}
