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
ll arr[100005];
ll minl[100005],minr[100005];
int main()
{
  sync;
  ll n,k;
  cin >> n >> k;
  ll mux = -100000000000000;
  ll mun = 100000000000000;
  for(ll i=0;i<n;i++)
  {
   cin >> arr[i];
   mux = max(mux,arr[i]);
   mun = min(mun,arr[i]);
  }
  if(k==1)
    cout << mun << endl;
  else if(k>2)
    cout << mux << endl;
  else
  {
    for(ll i=0;i<n;i++)
    {
      if(i==0){minl[i]=arr[i];continue;}
      minl[i] = min(minl[i-1],arr[i]);
    }
    for(ll i=n-1;i>=0;i--)
    {
      if(i==n-1){minr[i]=arr[i];continue;}
      minr[i] = min(minr[i+1],arr[i]);
    }
    ll ans = -100000000000000;
    for(ll i=0;i<n-1;i++)
    {
      ans = max(ans,max(minl[i],minr[i+1]));
    }
    cout << ans << endl;
  }
}

