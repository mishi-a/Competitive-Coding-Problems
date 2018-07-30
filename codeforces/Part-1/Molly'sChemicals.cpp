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
vector <ll > v;
vector <ll > csum;
int main()
{
  sync;
  ll n,k;
  v.pb(0);
  cin >> n >> k;
  ll maxm = 100000000000005;
  ll minm = -100000000000005;
  ll x = k;
  for(int i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
  }
  csum.pb(0);
  map <ll,ll > mp;
  mp[0] = 1;
  ll tot = 0;
  for(int i=1;i<=n;i++)
  {
    x = 1;
    csum.pb(csum[i-1]+v[i]);
    if(mp.find(csum[i]) == mp.end())
        mp[csum[i]] = 1;
    else
        mp[csum[i]]++;
    while(x<=maxm && x>=minm)
    {
      if(mp.find(csum[i]-x)!=mp.end())
      {
        tot = tot + mp[csum[i]-x];
      }
      if(x == -1)
        break;
      x *=k;
      if(x == 1 && k == 1)
        break;
     
    }
    
  }
  cout << tot << endl;
  
  
  
  
}

