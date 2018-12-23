/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

vector<pii> v;
int main()
{
  sync;
  ll n,m,k;
  ll ans = -1,ans1 = -1;
  cin >> n >> m >> k;
  if (2*n*m % k != 0)
    cout << "NO" << endl;
  else
  {
    for(int i=1;i*i<=k;i++)
      v.pb({i,k/i}),v.pb({k/i,i});
    ll val = (2*n*m)/k;
    for(int i=0;i<v.size();i++)
    {
      ll x = v[i].FI,y=v[i].SE;
      if(2%x == 0 && m*n%y == 0 && ((2/x <=m&&(m*n)/y<=n)||(2/x <=n&&(m*n)/y<=m) ))
      {
        ans = 2/x,ans1=(m*n)/y;
        break; 
      }
      if(2*m%x == 0 && n%y == 0 && ((2*m/x <=m&&(n)/y<=n)||(2*m/x <=n&&(n)/y<=m) ))
      {
        ans = 2*m/x,ans1=(n)/y; 
        break;
      }
      if(2*n%x == 0 && m%y == 0 && ((2*n/x <=m&&(m)/y<=n)||(2*n/x <=n&&(m)/y<=m) ))
      {
        ans = 2*n/x,ans1=(m)/y; 
        break;
      }
    }
    if(ans!=-1 && ans1!=-1)
    {
      cout << "YES" << endl;
      cout << 0 << " " << 0 << endl;
      //cout << ans << " " << ans1 << " " << m << " " << n << endl;
      if(ans <= m && ans1 <= n)
      {cout << 0  << " " << ans << endl;
            cout << ans1 << " " << 0 << endl;}
      else if(ans <=n && ans1 <= m)
      {
        cout << 0  << " " << ans1 << endl;
            cout << ans << " " << 0 << endl;
      }
    }
    else
      cout <<"NO" << endl;

  }
  
}
