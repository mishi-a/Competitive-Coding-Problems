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

vector <int> c;
vector <int> a;
vector <int> d;
vector <int> b;
int n,m,x,y,z,za;
int dp[1005][1005] = {0};

int solve(int start,int tot)
{
  if(dp[start][tot]!=0)
    return dp[start][tot];
  if(start == m+1)
    return 0;
  if(tot <= 0)
  {
    return 0;
  }
  int bound;
  start==0 ? bound = tot/c[0] : bound = min(a[start]/b[start] , tot/c[start]);
  int mux = -1;
  for(int i=0; i<=bound ;i++ )
  {
     int res =d[start]*i + solve(start+1,tot-i*c[start]);
     //cout << res << endl;
     if(res > mux)
       mux = res;
  }
  dp[start][tot] = mux;
  return mux;
}

int main()
{
  sync;
  cin >> n >> m >> x >> y;
  a.pb(0);
  b.pb(0);
  c.pb(x);
  d.pb(y);
  for(int i=0;i<m;i++)
  {
    cin >> x >> y >> z >> za;
    a.pb(x);
    b.pb(y);
    c.pb(z);
    d.pb(za);
  }
  int res = solve(0,n);
  cout << res << endl;
}

