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
vector <int> v2;
vector <int> v3;
vector <int> csum;
vector <int> csum1;
int main()
{
  sync;
  int n,m,k,a,b;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++)
  {
     cin >> a >> b;
     if(b==0)
     {
       v.pb(a);
     }
     else if(b==n)
     {
       v1.pb(a);
     } 
     else if(a==0)
     {
       v2.pb(b);
     }
     else
     {
       v3.pb(b);
     }
  }
  sort(v.begin(),v.end());
  sort(v3.begin(),v3.end());
  sort(v1.begin(),v1.end(),greater<int>());
  sort(v2.begin(),v2.end(),greater<int>());
  for(int i=0;i<v.size();i++)
  {
    csum.pb(v[i]);  
  }
  for(int i=0;i<v3.size();i++)
     csum.pb(n+v3[i]);
  for(int i=0;i<v1.size();i++)
     csum.pb(2*n+n-v1[i]);
  for(int i=0;i<v2.size();i++)
     csum.pb(3*n+n-v2[i]);
  int ans = INT_MAX;
  for(int i=0;i<csum.size();i++)
  {
    int tot = 0;
    if(i+k>=csum.size())
    {
      tot = csum[csum.size()-1]-csum[i] + 4*n - csum[csum.size()-1] + csum[(i+k-1)%csum.size()];
      ans = min(tot,ans);
    }
    else
    {
      tot = csum[i+k]-csum[i];
      ans = min(tot,ans);
    }
  }
  sort(v2.begin(),v2.end());
  sort(v1.begin(),v1.end());
  sort(v3.begin(),v3.end(),greater<int>());
  sort(v.begin(),v.end(),greater<int>());
  //cout << ans << endl;
  for(int i=0;i<v2.size();i++)
     csum1.pb(v2[i]);
  for(int i=0;i<v1.size();i++)
     csum1.pb(n+v1[i]);
  for(int i=0;i<v3.size();i++)
     csum1.pb(3*n-v3[i]);
  for(int i=0;i<v.size();i++)
     csum1.pb(4*n-v[i]);
  for(int i=0;i<csum1.size();i++)
    cout << csum1[i] << " ";
  int ans1 = INT_MAX;
  for(int i=0;i<csum1.size();i++)
  {
    int tot = 0;
    if(i+k>=csum1.size())
    {
      tot = csum1[csum1.size()-1]-csum1[i] + 4*n - csum1[csum1.size()-1] + csum1[(i+k-1)%csum1.size()];
      ans1 = min(tot,ans1);
    }
    else
    {
      tot = csum1[i+k]-csum1[i];
      ans1 = min(tot,ans1);
    }
  }
    cout << ans1 << endl;
  cout << min(ans,ans1) << endl;
}

