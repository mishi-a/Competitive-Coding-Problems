/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
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
ll mod = 1e9+7;
ll digSum=0;
ll arr[170];
vector<ll> v;
ll getDigitCount(ll num)
{
	ll cnt = 0;
	while(num!=0)
	{
		digSum+=(num%10);
		v.pb(num%10);
		num/=10;
		cnt++;
	}
	reverse(v.begin(),v.end());
	return cnt;
}
ll dp1[20][200][20][2];
ll counTLess(ll n,ll sum,ll idx,ll is)
{
	//cout << n << " " << sum << " " << idx << " " << v[idx] << endl;
	ll ans = 0;
	if(sum < 0)
		return 0;
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp1[n][sum][idx][is]!=-1)
		return dp1[n][sum][idx][is];
	else
	{
    int k =(is == 0 ?v[idx]:9);
		for(ll i=0;i<=k;i++)
		{
			ans += counTLess(n-1,sum-i,idx+1 , is == 0 ? i<k : is);
			//cout << "hi" << ;
			ans%=mod;
		}
	}
	return (dp1[n][sum][idx][is]=(ans%mod));
}
ll prod(ll x,ll y)
{
	x%=mod,y%=mod;
	return (x*y)%mod;
}

int main()
{
  sync;
  ll t;
  cin >> t;
  ll dp2[165]={0};
  while(t--)
  {
  	ll l,r;
  	cin >> l >> r;
    ll freq[170];
    memset(freq,0,sizeof(freq));
    v.clear();
    ll p = getDigitCount(l-1);
    memset(dp1,-1,sizeof(dp1));
    //cout << p << endl;
    for(ll i=1;i<=9*p;i++)
    {
    	freq[i] = (counTLess(p,i,0,0)+mod)%mod;
    }
    v.clear();
  	p = getDigitCount(r);
  	memset(dp1,-1,sizeof(dp1));
  	for(ll i=1;i<=9*p;i++)
    {
    	freq[i] = (counTLess(p,i,0,0)-freq[i]+mod)%mod;
    }
    ll cnt = 0;
    for(ll i=1;i<163;i++)
    {
    	for(ll j = i+1;j<163;j++)
    	{
    		if(__gcd(i,j) == 1)
    		{
    			cnt += prod(freq[i],freq[j]);
    			cnt%=mod;
    		}
    	}
    }
    cout << (cnt)%mod << endl;
  }
}
