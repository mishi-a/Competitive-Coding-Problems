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

ll arr[5005];
ll csum[5005];
ll ans[5005];
ll ans1[5005];
ll p1[5005];
ll p2[5005];
int main()
{
  sync;
  ll n;
  cin >> n;
  for(ll i=0;i<n;i++)
  {
    cin >> arr[i];
    i==0 ? csum[i] = arr[i] : csum[i]=csum[i-1]+arr[i];
  }
  for(ll i=0;i<5005;i++)
  {
    ans[i] = ans1[i] = LLONG_MIN;
  }
  for(ll i=n;i>=0;i--)
  {
    if(i==0)
    {
      ans[i] = 0;
      break;
    }
    ll temp = 0;
    for(ll j=i;j>=0;j--)
    {
       j!=0 ? temp = csum[j-1]-(csum[i-1]-csum[j-1]) : temp = -(csum[i-1]);
       if(temp>ans[i])
       {
         ans[i] = temp;
         p1[i] = j;
       }  
    }
    
  }
  for(ll i=0;i<=n;i++)
  {
    ll temp;
    for(ll j=i;j<=n;j++)
    {
       if(i==0)
       {
         if(j!=0)
         {
           temp = (csum[j-1])-(csum[n-1]-csum[j-1]);
         }
         else
         {
           temp = -csum[n-1];
         }
       }
       else
         temp = (csum[j-1]-csum[i-1])-(csum[n-1]-csum[j-1]);
       if(temp>ans1[i])
       {
         ans1[i] = temp;
         p2[i] = j;
       } 
    }
  }
  ll res = LLONG_MIN;
  ll idx;
  for(ll i=0;i<=n;i++)
  {
    if(ans[i]+ans1[i] > res)
    {
      res = max(res,ans[i]+ans1[i]);
      idx = i; 
    }
  }
  cout << p1[idx] << " " << idx << " " << p2[idx] << endl;
}
