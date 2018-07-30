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
ll arr[100005];
ll n,q;
const ll mod = 1e9+7;
vector <ll> v1[100005];
void pre()
{//cout << n << endl;
  for(ll i=1;i<=n;i++)
  {
    ll sum = 0;
    for(ll j=i;j<=n;j+=i)
    {
      sum = sum+v[j]*v[j];
      if(sum >= mod)
        sum%=mod;
    }
    arr[i] = sum%mod;
  }
}
void pre1()
{
  for(ll i=1;i<=100001;i++)
  {
    for(ll j=i;j<=100001;j+=i)
    {
      v1[j].pb(i);
    }
  }
}
int main()
{
  sync;
  pre1();
  ll t;
  cin >> t;
  while(t--)
  {
    v.pb(-1);
    cin >> n >> q;
    for(ll i=0;i<n;i++)
    {
      ll a;
      cin >> a;
      v.pb(a);
    }
    pre();
    ll a,b,c;
    while(q--)
    {
      cin >> a;
      if(a==1)
      {
        cin >> b;
        cout << arr[b] << endl;      
      } 
      else
      {
        cin >> b >> c;
        for(ll i=0;i<v1[b].size();i++)
        {
          arr[v1[b][i]] = ((arr[v1[b][i]]-((v[b]*v[b])%mod)+mod)+((c*c)%mod))%mod;
        }
        v[b]=c;
      }
    }
    v.clear();
  }
}

