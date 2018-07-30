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

ll maxjob[1005];
string q[1005];
ll maxs[1005];
ll expe[1005];
ll check[1005];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
          ll n,m;
          cin >> n >> m;
          for(ll i=1;i<=n;i++)
          {
            cin >> expe[i];

          }
          for(ll i=1;i<=m;i++)
          {
            cin >> maxs[i] >> maxjob[i];
                check[i]=maxjob[i];
          }
          for(ll i=1;i<=n;i++)
          {
            cin >> q[i];
          }
          ll tc = 0, ts = 0;
          for(ll i=1;i<=n;i++)
          {
            ll req = expe[i];
            ll flag =0;
            ll ind = -1;
            for(ll j=1;j<=m;j++)
            {
              if(q[i][j-1] == '1' && maxjob[j]!=0)
              {
                if(maxs[j]>=req)
                {
                  req = maxs[j];
                  flag = 1;
                  ind = j;
                }
              }
            }
            if(flag == 1)
            {  
               tc++;
               ts = ts + maxs[ind];
               maxjob[ind]--;
            }
          }
          ll cnt = 0;
          for(int i=1;i<=m;i++)
          {
            if(check[i] == maxjob[i])
              cnt++;
          }
          cout << tc << " " << ts << " " << cnt << endl;
        }
   }

