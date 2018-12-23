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

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
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
    return res%p; 
} 

int main()
{
  sync;
  ll n,s,m;
  cin >> n >> s >> m;
  if(n == 1)
  {
  	cout << s << endl;
  	return 0;
  }
  ll ans = power(s,n-2,m);
  // cerr << ans << endl;
  for(ll i=3;i<=n;i++)
  {
  	ll res = 1;
  	for(ll j=2;j<=(i/2+(i%2==1));j++)
  		res = (res*(s-1))%m;
  	ans = (ans+(res*power(s,n-i,m))%m)%m;
  }
  ans = (ans*s)%m;
  cout << (power(s,n,m)-ans+m)%m << endl;
}
