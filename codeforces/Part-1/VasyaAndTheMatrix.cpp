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
ll a[300005],b[300005];
ll suma[300005],sumb[300005];
int main()
{
  sync;
  ll n;
  cin >> n;
  for(ll i=0;i<n;i++)
  	cin >> a[i];
  for(ll i=0;i<n;i++)
  	cin >> b[i];
  for(int i=1;i<n;i++)
  {
  	a[i]+=a[i-1];
  	b[i]+=b[i-1];
  }
  for(int i=0;i<n;i++)
  {
  	suma[i] = 
  }
  int side = 0;
  ll ans = -1;
  for(int i=0;i<2*n;i++)
  {
  	ll temp = 0;
  	if(side == 0)
  	{
  		temp = i*(i==0 ? a[n-1] : a[n-1]-a[i-1] );

  	}

  }
}
