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

vector <ll> c,w,csum;
ll arr[1000005] = {0};

void solve()
{
  ll n;
  cin >> n;
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    c.pb(a);
  }
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    w.pb(a);
    i == 0 ? csum.pb(a) : csum.pb(csum[i-1]+a);
  }
  ll l=0,r=0;
  ll min = -1;
  ll mux = -1;
  while(l<=r && l<n)
  {
    while(r<n)
    {
      if(arr[c[r]] == 0 || arr[c[r]] == r+1 || arr[c[r]] < l+1)
      {
        arr[c[r]] = r+1;
        r++;
      }
      else
      { 
         //cout << "hi" <<r<< endl;
         if(arr[c[r]]-1 > min)
           min = arr[c[r]]-1;
         arr[c[r]] = r+1;
         break;
      }
     }
       if(l == 0)
         {
           mux = max(csum[r-1],mux);
         }
         else
         {
           mux = max(csum[r-1]-csum[l-1],mux);
         }
      //cout << mux << endl;
      if(r == n)
        break;
      l = max(min+1,l+1);
   }
  cout << mux << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    c.clear();
    w.clear();
    csum.clear();
    memset(arr,0,sizeof(arr));
  }
}

