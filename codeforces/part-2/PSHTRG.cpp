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
vector <ll> v;
int main()
{
  sync;
  ll n,q;
  cin >> n >> q;
  for(int i=0;i<n;i++)
  	cin >> arr[i],v.pb(arr[i]);
  while(q--)
  {
  	ll t,l,r;
  	cin >> t;
  	if(t == 1)
  	{
 		cin >> l >> r;
 		v[l-1]=r;
 		arr[l]=r;
  	}
  	else
  	{
  		int flag = 0;
  		cin >> l >> r;
  		vector<ll> v1;
  		for(ll i=l-1;i<r;i++)
  			v1.pb(v[i]);
  		sort(v1.begin(),v1.end(),greater<ll>());
  		for(ll i=0;i+2<v1.size();i++)
  		{
  			if(v1[i+1]+v1[i+2]>v1[i])
  			{
  				cout << v1[i]+v1[i+1]+v1[i+2] << endl;
  				flag = 1;
  				break;

  			}	
  		}
  		if(flag == 0)
  			cout << "0" << endl;
  	}
  }

}
