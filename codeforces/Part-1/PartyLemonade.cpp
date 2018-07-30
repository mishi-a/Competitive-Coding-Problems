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
ll n,l,c[50],cap[50];

int main()
{
  sync;
  cin >> n >> l;
  for(ll i=1;i<=n;i++)
  {
  	cin >> c[i];
  }
  cap[1]=1;
  for(ll i=2;i<=30;i++)
  	cap[i] = cap[i-1]*2;
  for(ll i=2;i<=n;i++)
    c[i] = min(c[i],2*c[i-1]);
  ll ans = 2e18;
  ll val = 0;
  ll k = (l)/cap[n];
  ans = (k+1)*c[n];
  val+=(k*c[n]);
  l-=(cap[n]*k);
  if(l==0)
  {
  	cout << val << endl;
  	return 0;
  }
  if(k==0)
  	ans = c[n];
  for(int i=n-2;i>=0;i--)
  {
  	if(l&(1<<(i)))
  	{
       val+=c[i+1];
       l-=cap[i+1];
  	}
  	else
  	{
  		ans = min(ans,val+c[i+1]);
  	}
  	
  } 
  cout << min(ans,val) << endl;

  

}
