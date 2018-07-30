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

int v[200][200];
vector <pii > w;
void solve()
{
  int r,c;
  cin >> r >> c;
  for(int i=0;i<r;i++)
  {
     string s;
     cin >> s;
     for(int j=0;j<c;j++)
     {
       v[i][j] = s[j]-'0';
       if(v[i][j] == 1)
         w.pb({i,j});
     }
  }
 
  
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      if(v[i][j] == 0)
      {
        int mux = 10000000;
        for(int k=0;k<w.size();k++)
        { 
          int dist = fabs(i-w[k].first)+fabs(j-w[k].second); 
          if(dist < mux)
          {
            mux = dist;
          }
        }
        cout << mux << " ";
      }
      else
      {
        cout << "0" << " ";
      }
    }
    cout << endl;
  }
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    w.clear();
    memset(v,0,sizeof(v));
  }
}

