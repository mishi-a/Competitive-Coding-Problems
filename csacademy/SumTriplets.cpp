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

int f[5005];

int main()
{
  sync;
  int n,a;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> a,f[a]++;
  }
  int ans = 0;
  if(f[0]>2)
  {
    ans = (f[0]*(f[0]-1)*(f[0]-2))/6;
  }
  if(f[0]!=0)
  {
    for(int i=1;i<=5000;i++ )
    {
      if(f[i]>1)
      ans +=((f[0]*(f[i]*(f[i]-1)))/2);
    }
  }
  for(int i=1;i<=5000;i++)
  {
    if(f[i]>1)
     ans+=((((f[i]*(f[i]-1)))/2)*(f[2*i]));
  }
  for(int i=1;i<=5000;i++)
  {
    for(int j=i+1;j<=5000-i;j++)
      ans+=(f[i]*f[j]*f[i+j]);
  }
  cout << ans << endl;
}
