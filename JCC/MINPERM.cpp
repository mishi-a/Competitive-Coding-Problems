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
int ans[100005];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    if(n%2==0)
    {
      int v=2;
      for(int i=0;i<n;i+=2)
      {
        ans[i] = v;
        v+=2;
      }
      v=1;
      for(int i=1;i<n;i+=2)
      {
        ans[i] = v;
        v+=2;
      }
    }
    else
    {
      n=n-3;
      int v=2;
      int mux = INT_MIN;
      for(int i=0;i<n;i+=2)
      {
        mux = max(mux,v);
        ans[i] = v;
        v+=2;
        
      }
      v=1;
      for(int i=1;i<n;i+=2)
      {
        ans[i] = v;
        v+=2;
        mux = max(mux,v);
      }
      if(n==0)
        mux = 1;
      n+=3;
      ans[n-1]=mux;
      ans[n-2]=n;
      ans[n-3]=n-1;
    }
    for(int i=0;i<n;i++)
      cout << ans[i]  << " " ;
    cout << endl;
  }
}

