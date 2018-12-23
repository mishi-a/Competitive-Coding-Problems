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

ll s[3005],c[3005];
int main()
{
  sync;
  ll n;
  cin >> n;
  for(ll i=0;i<n;i++)
  	cin >> s[i];
  for(ll i=0;i<n;i++)
  	cin >> c[i];
  ll ans = LLONG_MAX;
  for(ll i=1;i<n-1;i++)
  {
  	ll j = i-1;
  	ll mc = LLONG_MAX;
  	ll tot = c[i];
  	while(j>=0)
  	{
  		if(s[j]<s[i])
  		{
  			mc = min(mc,c[j]);
  		}
  		j--;
  	}
  	j = i+1;
  	if(mc == LLONG_MAX)
  		continue;
  	tot+=mc;
  	mc = LLONG_MAX;
  	while(j<n)
  	{
  		if(s[j]>s[i])
  		{
  			mc = min(mc,c[j]);
  		}
  		j++;
  	}
  	if(mc == LLONG_MAX)
  		continue;
  	tot+=mc;
  	ans = min(ans,tot);

  }
  if(ans == LLONG_MAX)
  {
  	cout << "-1" << endl;
  	return 0;
  }
  cout << ans << endl;
}
