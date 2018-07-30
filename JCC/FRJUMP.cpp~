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


using namespace std;

ll arr[100005];
ll n,q;
ll val[100005];
double fd[100005];
ll mod = 1e9+7;
ll zidx = -1;
vector <ll> divisor;
ll inv;
ll modularExponentiation(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    //cout << result << endl;
    return result;
}
ll minverse(ll A)
{
    return modularExponentiation(A,mod-2,mod);
}
void getdiv(ll num)
{
  divisor.clear();
  ll i; 
  for(i=1;i*i<num;i++)
  {
    if(!(num%i))
    {
      divisor.pb(i),divisor.pb(num/i);
    }
  }
  if(i*i==num)
    divisor.pb(i);
}


void pre()
{
  for(ll i=1;i<n;i++)
  {
    ll prod = arr[0];
    double logsum = log10(arr[0]);
    for(ll j=i;j<n;j+=i)
    {
      prod = arr[j]*prod;
      if(prod > mod)
        prod %= mod;
      logsum += log10(arr[j]);
    }
    val[i] = prod;
    fd[i] = logsum;
  }
}

void update(ll idx,ll nval)
{
  getdiv(idx);
  //cout << divisor.size() << " " << divisor[0] << " " << divisor[1] << endl; 
  ll val1 = minverse(arr[idx]);
  for(ll i=0;i<divisor.size();i++)
  {
    ll r = divisor[i];
    val[r] = val[r]*val1;
    if(val[r] > mod)
      val[r]%=mod;
    val[r]*=nval;
    if(val[r] > mod)
      val[r]%=mod;
    fd[r] = fd[r]-log10(arr[idx]) + log10(nval);
  }
  if(idx!=0)
    arr[idx] = nval;
  else
    zidx = nval;
}

void solve(ll r)
{
  
  if(zidx!=-1 && r < n)
  {
    double temp = fd[r];
    ll temp1 = val[r];
    temp = temp-log10(arr[0]) + log10(zidx);
    temp1 = temp1*inv;
    if(temp1 > mod)
      temp1%=mod;
    temp1*=zidx;
    if(temp1 > mod)
      temp1%=mod;
    cout << (ll)pow(10,temp-floor(temp)) << " " << temp1 << endl;
    return ;
  }
  if(r<n)
  cout << (ll)pow(10,fd[r]-floor(fd[r])) << " " << val[r] << endl;
  else
  {
    ll x = arr[0];
    while(x>=10)
    {
      x/=10;
    }
    cout << x << " " << arr[0] << endl;
  }
}
int main()
{
  sync;
  ll a,b;
  cin >> n;
  for(ll i=0;i<n;i++)
     cin >> arr[i];
  pre();
  inv = minverse(arr[0]);
  cin >> q;
  for(ll i=0;i<q;i++)
  {
    cin >> a;
    if(a==1)
    {
      cin >> a >> b;
      update(a-1,b);
    }
    else
    {
      cin >> b;
      solve(b);
    }
  }
  
}
