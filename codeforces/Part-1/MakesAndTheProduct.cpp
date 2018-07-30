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
int main()
{
  sync;
  ll n;
  cin >> n;
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >>a;
    v.pb(a);
  }
  sort(v.begin(),v.end());
  ll u = 2;
  ll k = 3;
  while(u>=0 && v[u] == v[2] )
  {
    u--;
  }
  while(k < n && v[k] == v[2])
  {
    k++;
  }
  ll tot = 2 - u + k-3;
  if(u == 1)
    cout << tot << endl;
  else if(u == 0)
    cout << (tot*(tot-1))/2 << endl;
  else
    cout << (tot*(tot-1)*(tot-2))/6 << endl;
  
}

