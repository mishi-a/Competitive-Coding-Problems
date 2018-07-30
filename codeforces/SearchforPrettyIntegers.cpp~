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
  int n,m,a,b;
  vector<int>v,v1;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    cin >> a,v.pb(a);
  }
  for(int j=0;j<m;j++)
  {
    cin >> b,v1.pb(b);
  }
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  int ans = 1000000;
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v1.size();j++)
    {
      if(v[i]==v1[j])
       ans = min(ans,v1[j]);
    }
  }
  if(ans!=1000000)
  {
    cout << ans << endl;
    return 0;
  }
  if(v[0]==v1[0])
    cout << v[0] << endl;
  else
    cout << min(v[0],v1[0]) << max(v[0],v1[0]) << endl;
}

