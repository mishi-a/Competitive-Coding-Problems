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

ll phi[1000005];
ll res[1000005];
void precalc()
{
  for(int i=1;i<=1000000;i++)
  {
    phi[i] =i;
  }
  for(int i = 2;i<=1000000;i++)
  {
    if(phi[i] == i)
    {
      for(int j = i;j<=1000000;j = j+i)
      {
        phi[j] = (phi[j]/i)*(i-1);
      }
    }
  }
  for(int i=1;i<=1000000;i++)
  {
    for(int j=i;j<=1000000;j+=i)
    {
      res[j] = res[j] + phi[i]*i;
    }
  }
  
}

int main()
{
  sync;
  precalc();
  int t;
  cin >> t;
  while(t--)
  {
    ll n;
    cin >> n;
    ll ans = res[n] + 1;
    cout << (n*(ans))/2 <<  endl;
  }
}
