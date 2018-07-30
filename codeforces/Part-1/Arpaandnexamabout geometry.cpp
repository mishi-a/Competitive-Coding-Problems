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
  ll a1,a2,b1,b2,c1,c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
  ll s = (c2 - b2) * a1 + (b1 - c1) * a2 + (c1 * b2 - b1 * c2);
  if(s==0)
  {
    cout << "NO" << endl;
    return 0;
  }
  ll x = (b1-a1)*(b1-a1)+(b2-a2)*(b2-a2);
  ll y = (c1-b1)*(c1-b1)+(c2-b2)*(c2-b2);
  ll z = (c1-a1)*(c1-a1)+(c2-a2)*(c2-a2);
  
  if(x==y)
   cout << "YES" << endl;
  else
   cout << "NO" << endl;
}

