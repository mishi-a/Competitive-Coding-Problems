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
int n,k;

int solve(int i1,int k)
{
  int cnt = 0;
  if(k == 0)
    return 1;
  if(i1<1 || i1>n)
    return 0;
  else
  {
    if(i1-1>=1)
     cnt+=solve(i1-2,k-1);
    if(i1+1 <= n)
     cnt+=solve(i1+2,k-1);
  } 
  return cnt;
  
}

int main()
{
  sync;
  cin >> n >> k;
  int ans = 0;
  for(int i=1;i<=n;i++)
    ans+=solve(i,k);
  cout << ans << endl;
}

