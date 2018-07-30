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

ll arr[100005];
ll n,k;
ll ans = 0;
bool check(ll mid)
{
	ll cnt=0;
	for(ll i=0;i<n;i++)
		cnt+=(arr[i]/mid);
	if(cnt < k)
		return true;
	else
		return false;
}
void dbs()
{
	ll l = 1,r = 1e9;

	while(l<r)
	{
		ll mid = (l+r+1)/2;
		if(check(mid))
			r = mid-1;
		else
		{
          if(mid>ans)
          	ans = mid;
          l=mid;
		}
	}
}

int main()
{
  sync;
  cin >> n >> k;
  for(ll i=0;i<n;i++)
  	cin >> arr[i];
  dbs();
  cout << ans << endl;
}
