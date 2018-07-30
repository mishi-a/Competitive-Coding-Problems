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

ll arr[2000009];
ll ans[1000005];
ll solve(ll num)
{
	ll e=0,o=0;
	while(num!=0)
	{
		ll x = num%10;
		if(x&1)
		{
			o+=x;
		}
		else
			e+=x;
		num/=10;
	}
	return abs(e-o);
}
void pre()
{
	arr[0]=0LL;
	for(ll i=1;i<=2000008;i++)
	{
		arr[i]=solve(i+1);
	}
    for(ll i=1;i<=2000008;i++)
    	arr[i]=arr[i]+arr[i-1];
    ans[1]=2LL;
    for(ll i=2;i<=1000001;i++)
    {
    	ans[i] = ans[i-1LL]+2*(arr[2*i-2LL]-arr[i-1LL])+arr[2*i-1LL]-arr[2*i-2];
    }
}

int main()
{
  sync;
  pre();
  ll t;
  cin >> t;
  while(t--)
  {
    ll n;
    cin >> n;
    cout << ans[n] << endl;
  }
}
