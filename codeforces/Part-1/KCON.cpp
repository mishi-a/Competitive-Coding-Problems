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
ll arr[100005],n;
ll ls,rs,ts,as;

ll solve(ll k)
{
  if(k==1)
  {
  	return as;
  }
  else
  {
  	ll val=0;
  	ll mid = k/2;
  	ll led = k-mid;
  	if(ts>=0&&mid>1)
  		val = ts*(mid-1)+rs;
  	if(ts>=0&&led>1)
  		val+=(ts*(led-1)+ls);
  	if(ts<0)
  		val+=(rs+ls);
  	if(ts>=0 && mid==1)
  		val+=rs;
  	if(ts>=0&&led==1)
  		val+=ls;
  	return max(val,max(solve(mid),solve(led)));
       
  }
}

int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
  	ll k;
    cin >> n >> k;
    ts=0;
    for(ll i=0;i<n;i++)
    {
    	cin >> arr[i];
    	ts+=arr[i];
    }
    ls = arr[0],as=ls;
    ll mux = as,mux1=as;
    for(ll i=1;i<n;i++)
    {
     ls+=arr[i];
     if(ls>mux)
     	mux=ls;
     if(as<0)
     	as=0;
     as+=arr[i];
     if(as>mux1)
     	mux1=as;
    }
    ls=mux,as=mux1;
    rs = arr[n-1];
    mux1=rs;
    for(ll i=n-2;i>=0;i--)
    { 
      rs+=arr[i];
      if(rs>mux1)
      	mux1=rs;
    }
    rs=mux1;
    cout << solve(k) << endl;
  }
}
