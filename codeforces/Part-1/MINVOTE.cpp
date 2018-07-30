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

ll arr[100005],csum[100005];
ll ans[100005],rsum[100005];
int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
  	ll n;
  	cin >> n;
  	for(ll i=1;i<=n;i++)
  		cin >> arr[i],csum[i]=csum[i-1]+arr[i];
    for(ll i=n-1;i>=0;i--)
    {
    	rsum[i]=arr[i]+rsum[i+1];
    }
    ll idx=0;
  	for(ll i=1;i<=n;i++)
  	{
  		idx=i;
  		ll l=i+1,r=n;
  		while(l<=r)
  		{
  			ll mid = (l+r)/2;
  			if(csum[mid]-csum[i]-arr[mid]<= arr[i])
  			{
  				idx = mid;
  				l = mid+1;
  			}
  			else
  			{
  				r = mid-1;
  			}
  		}
  		ans[idx+1]--;
  		ans[i+1]++;
  		l=1,r=i;
  		idx=i;
  		while(l<=r)
  		{
           ll mid = (l+r)/2;
           if(rsum[mid]-rsum[i]-arr[mid]<=arr[i])
           {
           	 idx = mid;
           	 r = mid-1;
           }
           else
           {
           	 l = mid+1;
           }
  		}
  		ans[i]--;
  		ans[idx]++;
  		//break;
  	}
  	for(ll i=1;i<=n;i++)
  	{
  		ans[i]+=ans[i-1];
  		cout << ans[i] << " ";
  	}
  	memset(ans,0,sizeof(ans));
  	memset(rsum,0,sizeof(rsum));
  	memset(csum,0,sizeof(csum));
  	cout << endl;
  }
}
