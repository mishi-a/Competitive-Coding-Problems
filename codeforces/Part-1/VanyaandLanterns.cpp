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
priority_queue <int> pq;
int main()
{
  sync;
  int n,l;
  cin >> n >> l;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }  
  sort(v.begin(),v.end());
  for(int i=1;i<n;i++)
  {
    pq.push(v[i]-v[i-1]);
  }
  int val = 0,res = 0;
  if(!pq.empty())
  {
    res = pq.top();
    val = ceil(res/2.0);
  }
  if(v[0] >= val && v[0] >= l-v[n-1])
  {
    cout << fixed << setprecision(10) ;
    double ans = v[0];
    cout << ans;
  }
  else if(l-v[n-1] >= v[0] && l-v[n-1] >= val )
  {
    cout << fixed << setprecision(10) ;
    double ans = l - v[n-1];
    cout << ans;
  }
  else
  {
    cout << fixed << setprecision(10) ;
    double ans = (res/2.0);
    cout << ans;
  }
}

