/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
ll n,m,a;
vector<ll>g[1000001];
vector <pair<ll,ll>> v[1000001];
vector <ll> dp[1000001];
vector <ll> arr[1000001];
vector <ll> arr1[1000001];
vector <ll> muxl[1000001];
vector <ll> muxr[1000001];
vector <int> v1[1000001];

void init()
{
  for(ll i=1;i<=n;i++)
  {
    g[i].clear(),v[i].clear(),dp[i].clear(),arr[i].clear();
    arr1[i].clear(),muxl[i].clear(),muxr[i].clear(),v1[i].clear();
  }
}

void solve()
{
   for(ll i=1;i<=n;i++)
   {
     for(ll j=0;j<v[i].size();j++)
     {
       if(i==1){ dp[i][v[i][j].SE]=0; continue;}
       ll ft = v[i][j].SE+1<v[i].size()?v[i][j].SE+1:0;
       ll val = g[i][ft];
       ll idx = upper_bound(v1[i-1].begin(),v1[i-1].end(),g[i][ft])-v1[i-1].begin();
       if(idx==v1[i-1].size())
       {
         if(val<=v1[i-1][idx-1])
           idx--;
       }
       if(idx == v1[i-1].size())
       {
         dp[i][v[i][j].SE] = muxl[i-1][idx-1] + val*(i-1);
         continue;
       }
       if(val < v1[i-1][idx])
         idx--;
       if(idx<0)
       {
         dp[i][v[i][j].SE] = muxr[i-1][v1[i-1].size()-2-idx]-val*(i-1);
         continue;
       }
       if(idx == v1[i-1].size()-1)
       {
         dp[i][v[i][j].SE]  = muxl[i-1][idx] + val*(i-1);
         continue;
       }
       dp[i][v[i][j].SE] = max(val*(i-1)+muxl[i-1][idx],muxr[i-1][v1[i-1].size()-2-idx]-val*(i-1));
      
     }
     for(ll j=0;j<v[i].size();j++)
     {
       arr[i].pb(dp[i][v[i][j].SE] - v[i][j].FI*i);
       arr1[i].pb(dp[i][v[i][j].SE] + v[i][j].FI*i);
     }
     ll mux = -1e18;
     for(ll j=0;j<v[i].size();j++)
        mux = max(mux,arr[i][j]),muxl[i].pb(mux);
     mux = -1e18;
     for(ll j=v[i].size()-1;j>=0;j--)
        mux = max(mux,arr1[i][j]),muxr[i].pb(mux);
   }
   ll ans = -1e18;
   for(ll i=0;i<dp[n].size()-1;i++)
     ans = max(dp[n][i],ans);
   cout << ans << endl;

}

int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for(ll i=1;i<=n;i++)
    {
      cin >> m;
      dp[i].resize(m+1);
      for(ll j=0;j<m;j++)
        cin >> a,g[i].pb(a),v[i].pb({a,j}),v1[i].pb(a);
      sort(v[i].begin(),v[i].end());
      sort(v1[i].begin(),v1[i].end());
    }
    solve();
    /*for(int i=1;i<=n;i++)
    {
      for(int j=0;j<dp[i].size();j++)
        cout << dp[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<arr[i].size();j++)
        cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<arr1[i].size();j++)
        cout << arr1[i][j] << " ";
        cout << endl;
    }
    cout << endl;*/ 
       init();
  }
}

