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
ll arr[20];
int main()
{
  sync;
  for(ll i=0;i<14;i++)
  	cin >> arr[i];
  ll res = 0;
  for(ll i=0;i<14;i++)
  {
  	if(arr[i]!=0)
  	{
  		ll arr1[15];
  		memset(arr1,0,sizeof(arr1));
	  	ll tot = arr[i]/14;
	  	ll left = arr[i]%14;
	  	//cout << tot << " " << left << " " << i << endl;
	  	ll start = (i+1)%14;
	  	while(left!=0)
	  	{
	  		arr1[start]++;
	  		left--;
	  		start = (start+1)%14;
	  	}
	  	ll ans = 0;
	  	for(ll j=0;j<14;j++)
	  	{
	  		if(j == i)
	  		{
	  			if((arr1[j]+tot)%2==0)
	  				ans+=arr1[j]+tot;
	  		}
	  		else
	  		{
	  			if((arr[j]+arr1[j]+tot)%2==0)
	  				ans+=arr[j]+arr1[j]+tot;
	  		}
	  		
	  	}
	  	//cout << ans << endl;
	  	res = max(ans,res);
  	}
  	
  }
  cout << res << endl;
}
