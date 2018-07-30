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
const ll mod = 1e9+7;
ll sq[100005],prod[100005],arr[100005],bit1[100005],bit2[100005];
ll n,m;
ll getsum(ll idx,ll flag)
{
  idx++;
  ll res = 0;
  while(idx>0 && flag == 0)
  {
    res+=bit1[idx];
    res%=mod;
    idx-=(idx&(-idx));
  }
  while(idx>0 && flag ==1)
  {
    res+=bit2[idx];
    res%=mod;
    idx-=(idx&(-idx));
  }
  return res;
}

void update(ll idx,ll val,ll flag)
{
  idx++;
  while(idx<=n && flag == 0)
  {
    bit1[idx]+=val;
    bit1[idx]+=mod;
    bit1[idx]%=mod;
    idx += (idx&(-idx));
  }
  while(idx<=n && flag == 1)
  {
    bit2[idx]+=val;
    bit2[idx]+=mod;
    bit2[idx]%=mod;
    idx+=(idx&(-idx));
  }
}

ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % mod;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res%mod;
}

int main()
{
  sync;

  cin >> n >> m;
  ll sz = n;
  for(ll i=0;i<n;i++)
  { 
    cin >> arr[i];
  }
  for(ll i=0;i<n;i++)   	
  {
    sq[i] = (arr[i]*arr[i])%mod;
  }
  prod[0] = 0;
  for(ll i=1;i<n;i++)
  {
    prod[i] = (arr[i]*arr[i-1])%mod;
  }
  for(ll i=0;i<n;i++)
  {
    update(i,sq[i],0);
    update(i,prod[i],1);        
  }
  /*for(int i=0;i<=n;i++)
    cout << bit1[i] << " ";
  cout << endl;
  for(int i=0;i<=n;i++)
    cout << bit2[i] << " ";
  cout << endl;*/
  for(ll i=0;i<m;i++)
  {
    ll a,b,c;
    cin >> a >> b >> c;
    if(a == 1)
    {
        b--;
        arr[b] = c;
        if(b!=0)        
        {
          update(b,-prod[b],1);
          prod[b] = (c*arr[b-1])%mod;
          update(b,prod[b],1);
          if(b+1<sz)
          {
            update(b+1,-prod[b+1],1);
            prod[b+1] = (c*arr[b+1])%mod;
            update(b+1,prod[b+1],1);
          }
        }
        else
        {
          if(b+1<sz)
          {
            update(b+1,-prod[b+1],1);
            prod[b+1] = (c*arr[b+1])%mod;
            update(b+1,prod[b+1],1);
          }
        } 
        update(b,-sq[b],0);
        sq[b] = (c*c)%mod;
        update(b,sq[b],0); 
    }
    else
    {
      b--;
      c--;
      //cout << "hi" << endl;
      ll x = c-b;
      ll ans = (getsum(c,0)-getsum(b-1,0)+mod)%mod;
      ans = (ans -getsum(c,1)+mod)%mod+getsum(b,1);
      ans%=mod;
      //cout << ans << endl;
      ll k = power(2,x);     
      cout << (k*ans)%mod << endl;  
    }
  }
}

