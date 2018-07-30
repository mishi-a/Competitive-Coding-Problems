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

vector <ll> v;
vector <ll> a1;
vector <ll> b1;
ll mp[17000] = {0};
int main()
{
  sync;
  ll n,a,b;
  cin >> n;
  ll q;
  cin >> q;
  for(ll i=0;i<n;i++)
  {
    cin >> a;
    v.pb(a);
  }
  
  ll ans = 0;
 
  while(q--)
  {
    mp[0] = 1;
    ll ans = 0;
    cin >> a >> b;
    if(a==b)
    {
      cout << (n*(n+1))/2 << endl;
      continue;
    }
    ll cnt=0,cnt1=0;
    for(ll i=0;i<n;i++)
    {
      if(v[i]==a)
      {
        cnt++;
      }
      else if(v[i] == b)
        cnt1++;
      a1.pb(cnt);
      b1.pb(cnt1);
    }
    for(ll i=0;i<n;i++)
    {
      int idx = a1[i]-b1[i];
      if(idx < 0)
        idx+=16005;
      if(mp[idx]!=0)
      {
        ans+=mp[idx];
      }
       mp[idx]++;    
    }
    cout << ans << endl;
    a1.clear();
    b1.clear();
    memset(mp,0,sizeof(mp));
  }
}

