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

vector <int> v;
vector <int> v1;

int main()
{
  sync;
  int n,m;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  cin >> m;
  for(int i=0;i<m;i++)
  {
    int b;
    cin >> b;
    v1.pb(b);
  }
  int ans = 0; 
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(fabs(v[i]-v1[j]) <= 1)
      {
        ans++;
        v1[j] = -10;
        break;
      }       
    }
  }
  cout << ans << endl;
  
}

