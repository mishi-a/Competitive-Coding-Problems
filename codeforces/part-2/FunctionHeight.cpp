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

const int MAX = 1e5;
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
ll n,k;

bool check(ll mid)
{
	//cout << mid << endl;
	if(n%2 == 1)
	{
		if((long double)mid*(n) >= k )
		{
			return true;
		}
	}
	else
	{
		if((long double)mid*(n)+ceil((mid/2)) >= k )
			return true;
	}
	return false;
}

ll solve()
{
	ll l = 1,r = 1e18;
	ll ans = LLONG_MAX;
	while(l<=r)
	{
		ll mid = (l-r)/2+r;
		//cout << l << " " << r << " " << mid << endl;
		if(check(mid))
		{
			ans = min(mid,ans);
			r = mid-1;
		}
		else
			l = mid+1;
	}	
	return ans;
}
int main()
{
  sync;
  cin >> n >> k;
  cout << solve() << endl;
}
