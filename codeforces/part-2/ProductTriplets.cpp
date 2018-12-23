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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
ll a[7005];
map<ll,ll> mp;
int main()
{
  sync;
  ll t,tot=0;
  cin >> t;
  while(t--)
  {
  	tot++;
  	ll n;
  	cin >> n;
  	for(int i=0;i<n;i++)
  		cin >> a[i],mp[a[i]]++;
  	sort(a,a+n);
  	ll ans = 0;
  	for(int i=0;i<n;i++)
  	{
  		for(int j=i+1;j<n;j++)
  		{
  			ll k = a[i]*a[j];
  			if(mp[k] == 0)continue;
  			ll start = lower_bound(a+j+1,a+n,k)-(a);
  			ll end = lower_bound(a+j+1,a+n,k+1)-a;
  			ans+=(end-start);
  		}
  	}
  	/*ll cnt = 0;
  	//cout << ans << endl;
  	for(int i=0;i<n;i++)
  	{
  		if(a[i]!=0)
  			cnt++;
  	}
  	ll zero = n - cnt;
  	ans  = ans + ((zero*(zero-1))/2)*cnt;
  	cout << "Case #" << tot << ": " << ans << endl;*/
  }
}
