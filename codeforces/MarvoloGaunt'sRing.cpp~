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
ll arr[100005];
ll s[100005];
ll t[100005];
ll rs[100005];
ll rt[100005];
int main()
{
  sync;
  ll n,p,q,r;
  ll mun = 100000000000;
  ll mux = -100000000000;
  cin >> n >> p >> q >> r;
  int k=0;
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    cin >> arr[i];
    mux = max(arr[i],mux);
    s[i]=mux;
    mun = min(arr[i],mun);
    t[i]=mun;
    if(arr[i]==0)
      k = 1;
  }
  mux = arr[n-1];
  mun = mux;
  for(int i=n-1;i>=0;i--)
  {
    mux = max(arr[i],mux);
    mun = min(arr[i],mun);
    rs[i]=mux;
    rt[i]=mun;
  }
  /*for(int i=0;i<n;i++)
  {
    cout << s[i] << " " << t[i] << " " << rs[i] << " " << rt[i] << endl;
  }*/
  if(p>=0&&q>=0&&r>=0)
  {
    ans+=p*mux;
    ans+=q*mux;
    ans+=r*mux;
  }
  else if(p<0&&q<0&&r<0)
  {
    ans+=p*mun;
    ans+=r*mun;
    ans+=q*mun;
  }
  else if(p>=0&&q>=0&&r<0)
  {
    ll tot = LLONG_MIN;
    for(int i=0;i<n;i++)
    {
          ll res=0;
          res+=s[i]*p;
          res+=s[i]*q;
          res+=rt[i]*r;
        tot = max(res,tot);
    }
    ans = tot;
  }
  else if(p>=0&&q<0&&r>=0)
  {
    ll tot = LLONG_MIN;
    for(int i=0;i<n;i++)
    {
          ll res=0;
          res+=s[i]*p;
          res+=arr[i]*q;
          res+=rs[i]*r;
        tot = max(res,tot);
    }
    ans = tot;
  }
  else if(p>=0&&q<0&&r<0)
  {
    ll tot = LLONG_MIN;
    for(int i=0;i<n;i++)
    {
          ll res=0;
          res+=s[i]*p;
          res+=rt[i]*q;
          res+=rt[i]*r;
        tot = max(res,tot);
    }
    ans = tot;
  }
  else if(p<0 && q<0 && r>=0)
  {
    ll tot = LLONG_MIN;
    for(int i=0;i<n;i++)
    {
          ll res=0;
          res+=t[i]*p;
          res+=t[i]*q;
          res+=rs[i]*r;
        tot = max(res,tot);
    }
    ans = tot;
  }
  else if(p<0 && q>=0 && r>=0)
  {
    ll tot = LLONG_MIN;
    for(int i=0;i<n;i++)
    {
          ll res=0;
          res+=t[i]*p;
          res+=rs[i]*q;
          res+=rs[i]*r;
        tot = max(res,tot);
    }
    ans = tot;
  }
  else
  {
    ll tot = LLONG_MIN;
    for(int i=0;i<n;i++)
    {
          ll res=0;
          res+=t[i]*p;
          res+=arr[i]*q;
          res+=rt[i]*r;
        tot = max(res,tot);
    }
    ans = tot;
  }
  cout << ans << endl;
}

