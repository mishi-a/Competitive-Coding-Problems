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
ll arr[MAX];
map<ll, ll> mp;
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	ll n,k,x,d,tot,ans=0;
  	cin >> n >> k >> x >> d;
  	for(int i=0;i<k;i++)
  		cin >> arr[i],mp[arr[i]]=1,ans+=arr[i];
  	sort(arr,arr+k);
  	tot = k;
  	//cout << tot << endl;
    for(int i=0;i<k-1;i++)
    {
    	if( arr[i]+d < arr[i+1] )
    	{
    		mp[arr[i]+d] = 1;
    		//v.pb(arr[i]+d);
    		ans+=(arr[i]+d);
    		ll val = arr[i]+d;
    		tot++;
    		while(val+d < arr[i+1])
    		{
    			tot++;
    			mp[val+d] = 1;
    			ans += (val+d);
    			//v.pb(val+d);
    			val += d;
    		}
    	}
    }
    //cout << tot << endl;
    if(x<n || tot> n)
    {
    	cout << -1 << endl;
    	continue;
    }
    ll last = arr[k-1];
    while(last+d <= x)
    {
    	mp[last+d] = 1;
    	tot++;
    	ans += (last+d);
    	last += d;
    	if(tot == n)
    		break;
    }
 	last = x;
    while(tot< n && last >=1)
    {
    	if(!mp[last])tot++,ans+=last;
    	last--;
    }
    cout << ans << endl;
  }  
}
