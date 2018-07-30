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
ll n,b,x;
ll func(ll a)
{
  return ((n-a*b)/b)*(a*b+x);
}
int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
    cin >> n >> b;
    ll a;
    a = n%b;
    if(a == 0 )
    {
      x = b;
      n = n-b;
    }
    else
    {
      x = a;
      n = n-a;
    }
    ll ans = 0;
    ll l = 0,r = n/b;
    while(r-l>=3)
    {
      ll mid1 = l+(r-l)/3;
      ll mid2 = r-(r-l)/3;
      if(func(mid1) > func(mid2))
      {
        r = mid2; 
      }
      else if(func(mid1)<func(mid2))
      {
        l = mid1;
      }
      else
      {
        l=mid1;
        r = mid2;
      }
    }
    for(int i=l;i<=r;i++)
    {
      ans = max(ans,func(i));
    }
    
    cout << ans << endl;
    
  }
}

