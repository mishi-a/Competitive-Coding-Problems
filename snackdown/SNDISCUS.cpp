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

vector <pair<int,pii > > v;
vector <pair<int,pii > > v1;

void solve()
{
  int n;
  cin >> n;
  v.clear();
  v1.clear();
  for(int i=0;i<n;i++)
  {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)
      v.pb({a,{min(b,d),max(b,d)}});
    else
      v1.pb({b,{min(a,c),max(a,c)}});
  }
  int mux = 1000000;
  int res = 1000000;
  for(int i=1;i<=50;i++)
  {
    for(int j=1;j<=50;j++)
    {  
      int tot = 0;
      int mov = 0;
      int min = -1;
      
      for(int k =0;k<v.size();k++)
      {
        if( j <= v[k].second.second && j>= v[k].second.first)
        {
          tot = tot+fabs(v[k].first - i);
          mov = fabs(v[k].first - i);
        }
        else if(j < v[k].second.first)
        {
          tot = tot+fabs(v[k].first-i) + v[k].second.first-j;
          mov = fabs(v[k].first-i) + v[k].second.first-j;
        }
        else
        {
           tot = tot+fabs(v[k].first-i) + j - v[k].second.second;
           mov = fabs(v[k].first-i) + j - v[k].second.second;
        }
        if(mov > min)
          min = mov;
      }
      for(int k =0;k<v1.size();k++)
      {
        if( i <= v1[k].second.second && i>= v1[k].second.first)
        {
          tot = tot+fabs(v1[k].first - j);
          mov = fabs(v1[k].first - j);
        }
        else if(i < v1[k].second.first)
        {
          tot = tot+fabs(v1[k].first-j) + v1[k].second.first-i;
          mov =fabs(v1[k].first-j) + v1[k].second.first-i;
        }
        else
        {
           tot = tot+fabs(v1[k].first-j) + i - v1[k].second.second;
           mov = fabs(v1[k].first-j) + i - v1[k].second.second;
        }
         if(mov > min)
          min = mov;
      }
      if(min < res)
         res = min;
  
    }
  }
   cout << res << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}

