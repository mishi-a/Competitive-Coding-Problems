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
  int t;
  cin >> t;
  while(t--)
  {
    int k,i,j;
    cin >> k >> i >> j;
    int n = floor((sqrt(1+8*k)-1.0)/2.0);
    k = k - (n*(n+1))/2;
    if(i<=n)
      cout << "1" << endl;
    else if(i>n+1)
      cout << "0" << endl;
    else
    {
      //i--;
      int sum = 1;
      int x = 1;
      int y = n+1,y1=1;
      double p = 1.0;
      for(int l=1;l<i;l++) p*=2.0;
      //int c = j%(i/2);
      /*if(j == 1 || j == i)
      {
        cout <<(1.0*k)/p << endl;
        
      }*/
      for(int l = 0;l<=n;l++)
      {
        x*=(x+l);
        y1*=(y-l);
        if(l==j-2)
        {
        cout<<l<<" "<<p<<endl;
          cout<<k<<" "<<x<<" "<<y1<<endl;
          double ans = ((y1*1.0/x)/p)*k;
          cout<<ans<<endl;
          break;
        }
      }
    }
  }
}

