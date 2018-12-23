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
const ll mod = 998244353;
ll cnt[MAX];
int main()
{
  sync;
  ll n,m;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;
  cnt[0] = t[0]-'0';
  for(ll i=1;i<m;i++)
    cnt[i] = (t[i]=='1')+cnt[i-1];
  ll ans = 0;
  ll pw = 1;
  for(ll i=0;i<n;i++)
  {
    if(i>=m) break;
    ans+=(s[n-i-1] == '1') ? (cnt[m-i-1]*pw)%mod : 0;
    ans%=mod;
    pw = (pw+pw)%mod;
    //cerr << ans << endl;
  }
  cout << ans << endl;
}
