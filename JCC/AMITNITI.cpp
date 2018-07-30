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

vector <ll > s;
vector <ll > arr1;
vector <ll > arr2;
void pre()
{
  s.pb(-1);
  s.pb(2);
  s.pb(7);
  for(ll i=3;i<=32;i++)
  {
    i%2 == 0 ? s.pb(s[i-1]+7) : s.pb(s[i-1]+3*s[i-2]);
  }
}

int main()
{
  sync;
  pre();
  for(ll i=1;i<65536;i++)
  {
    ll sum = 0;
    for(ll j=0;j<16;j++)
    {
      if(i & (1 << j))
        sum+=s[j+1];
    }
    arr1.pb(sum);
  }
  for(ll i=1;i<65536;i++)
  {
    ll sum = 0;
    for(ll j=0;j<16;j++)
    {
      if(i & (1 << j))
        sum+=s[16+j+1];
    }
    arr2.pb(sum);
  }
  sort(arr1.begin(),arr1.end());
  sort(arr2.begin(),arr2.end());
  ll t;
  cin >> t;
  while(t--)
  {
    ll n;
    cin >> n;
    //solve(1,n);
    ll flag = 0;
    for(ll i=0;i<arr1.size();i++)
    {
      if(arr1[i] == n)
      {
          flag = 1;
          break;
      }
      if(arr1[i] < n)
      {
        if(binary_search(arr2.begin(),arr2.end(),n-arr1[i]))
        {
          flag = 1;
          break;
        }
      }
      else
        break;
    }
    if(flag == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

