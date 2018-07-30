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

vector <int > v;

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n,a;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
      cin >> a;
      i==0 ? v.pb(a):v.pb(v[i-1]+a);    
      //cout << v[i] << endl;
    }
    int sum = v[n-1];
    int flag = 0;
    for(int i=0;i<n;i++)
    {
      if(i == 0)
      {
        if(sum-v[0] == 0)
        {
          cout << i << endl;
          flag = 1;
          break;
        }
        continue;
      }
      if(v[i-1] == sum - v[i])
      {
        cout << i << endl;
        flag = 1;
        break;
      }
    }
    if(flag == 0)
      cout << -1 << endl;
    v.clear();
  }
}

