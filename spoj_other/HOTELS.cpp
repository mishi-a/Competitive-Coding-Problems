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

vector <int> v;

int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  int l=0,r=0;
  int sum = 0;
  int ans = 0;
  while(l<=r)
  { 
    while(r<n && sum+v[r] <= m)
    { 
      sum = sum+v[r];
      r++;
      
    }
    ans = max(ans,sum);
    if(sum == 0)
    {
        l++;
        r++;
        if(l==n)
             break;
        continue;
    }
    sum = sum - v[l];
    l++;
    if(l == n)
      break;
  }
  cout << ans << endl;
}

