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


using namespace std;
ll y;
// Returns floor of square root of x
ll floorSqrt(ll x)
{
    // Base cases
    if (x == 0 || x == 1)
       return x;
 
    // Staring from 1, try all numbers until
    // i*i is greater than or equal to x.
    ll i = 1, result = 1;
    while (result < x)
    {
       if (result == x)
          return result;
       i++;
       result = i*i;
    }
    return i-1;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	cin >> y;
  	ll p =y;
  	ll ans=0;
  	for(int i=1;i<=700;i++)
  	{

      p=y-i;
      //cout << p << " " << y << endl ;
      if(p<=0)
      	break;
      ans+=(floorSqrt(p));
  	}
  	cout << ans << endl;
  }
}
