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

ll arr[] = {2,1,0,-1,-2};
ll seq[100005];
ll n;
ll check(ll cnt)
{
   ll p[] = {+1,0,-1};
   vector<ll> v;
   ll ret = LONG_MAX;
   
   for(ll i=0;i<3;i++)
   {
   	ll ans = 0;
   	 int flag = 0;
   	 ll a0 = seq[0]+p[i];
   	 v.pb(a0);
   	 if(i!=1)ans++;
   	 for(ll j=1;j<n;j++)
   	 {
   	 	v.pb(seq[j]);
   	 	if(v[j-1]-v[j]==cnt+1)
   	 	{
   	 		ans++;
   	 		v[j]+=1;
   	 	}
   	 	else if(v[j-1]-v[j]==cnt-1)
   	 	{
   	 		ans++;
   	 		v[j]-=1;
   	 	}
   	 	else if(v[j-1]-v[j]!=cnt)
   	 	{
   	 		flag = 1;
   	 		break;
   	 	}	
   	 }
   	 if(flag==0)
   	 {
   	 	ret = min(ret,ans);
   	 }
   	 v.clear();
   }
   return ret;
}

int main()
{
  sync;
 
  cin >> n;
  ll mun = LONG_MAX;
  for(ll i=0;i<n;i++)
  {
  	cin >> seq[i];
  	if(i>0)
  		mun = min(mun,seq[i-1]-seq[i]);
  }
  ll ans = 1e7;
  for(ll i=0;i<5;i++)
  {
  	ans = min(ans,check(mun+arr[i]));
  }
  if(ans != 10000000)
  	cout << ans << endl;
  else
	cout << "-1" << endl;
}
