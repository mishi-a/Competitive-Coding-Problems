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
vector <pii > vertex;
vector <int > len;
int func(int a,int b,int c,int d)
{
  return ceil(sqrt((c-a)*(c-a)+(d-b)*(d-b)));
}

int find(int startn,int endn,int startm,int endm)
{
  if(startm == endm)
  {
    int cunt = 0;
    for(int i=startn;i<=endn;i++)
    {
       cunt = cunt + ceil(len[i]/vertex[startm].first);
    }
    return cunt*vertex[startm].second;
   
  }
}

void solve()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    vertex.pb({a,b});
  }
  
  for(int i=1;i<n;i++)
  {
     int dist = func(vertex[i].first,vertex[i].second,vertex[i-1].first,vertex[i-1].second);
     len.pb(dist);
  }
  int dist = func(vertex[n-1].first,vertex[n-1].second,vertex[0].first,vertex[0].second);
  len.pb(dist);
  vertex.clear();
  int m;
  cin >> m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    vertex.pb({a,b});
  }
  int res = find(0,n-1,0,m-1);
  cout << res << endl;
  len.clear();
  vertex.clear();
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}

