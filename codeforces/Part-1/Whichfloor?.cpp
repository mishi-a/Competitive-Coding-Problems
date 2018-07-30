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
vector <pii > v;

int main()
{
  int n,m,a,b;
  cin >> n >> m;
  if(n==1)
  {
    cout << "1" << endl;
    return 0;
  }
  int ans=-1;
  for(int i=0;i<m;i++)
  {
    cin >> a >> b;
    v.pb({a,b});
  }
  int cnt=0;
  for(int i=1;i<=105;i++)
  {
    int flag = 0;
    for(int j=0;j<v.size();j++)
    {
      if(ceil(v[j].FI/(i*1.0)) != v[j].SE)
      {
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      if(cnt==0)
      {
        ans = ceil((n*1.0)/i);
      }
      else
      {
        int ans1 = ceil((n*1.0)/i);
        if(ans1!=ans)
        {
          cout << "-1" << endl;
          return 0;
        }
      }
      cnt++;
    }
   //cout << i << " " << flag << endl;
  }
  cout << ans << endl;
}
