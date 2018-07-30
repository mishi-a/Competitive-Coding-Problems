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

int main()
{
  sync;
  ll n,k;
  cin >> n >> k;
  ll x = (2*n)/(k)/(k+1);
  //cout << x << endl;
  if(x == 0)
  {
    cout << "-1" << endl;
    return 0;
  }
  {
    vector <ll> v;
    for(ll i=1;i*i<=n;i++)
    {
      if(n%i == 0)
      { v.pb(i);v.pb(n/i);}
    }
    ll g;
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
    {
      ll z  = v[i];
      ll tot = z*((k*(k-1))/2);
      if(n-tot > (k-1)*z && (n-tot)%z == 0)
      {
        g=z;
        break;
      }
    }
      ll p = g;
      ll tot = p*((k*(k-1))/2);
      for(int i=1;i<k;i++)
      {
        x = p*i;
        cout << x <<" ";
      }
      cout << n-tot << endl;
    
  }
}
