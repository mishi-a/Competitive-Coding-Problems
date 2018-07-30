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
  ll m ,b;
  cin >> m >> b;
  ll x = m*b;
  ll y = b;
  if(m == 0 || b == 0)
  {
    cout << "0" << endl;
    return 0;
  }
  ll mux = 0;
  for(ll i=0;i<=b;i++)
  {
    x = m*(b-i);
    //cout << x << endl;
    ll res = ((i*(i+1))/2)*(x+1) + (x*(x+1)/2)*(i+1);
    //cout << res << endl;
    mux = max(mux,res);
  }
  cout << mux << endl;
}
