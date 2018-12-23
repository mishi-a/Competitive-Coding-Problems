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

const int MAX = 2e5+7;
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

ll arr[MAX],xorr[MAX];
map <ll,ll> mp;
ll neg(ll num,ll k)
{
	return ~num & ((1 << k)-1);
}
int main()
{
  sync;
  ll n,k;
  cin >> n >> k;
  for(ll i=0;i<n;i++)
  	cin >> arr[i];
  //xorr[0] = arr[0];
  //for(int i=1;i<n;i++) xorr[i] = xorr[i-1]^arr[i];
  
  ll cnt = 0;
  ll cXor =  0;
  for(int i=0;i<n;i++)
  {
  	ll x = cXor^arr[i];
  	ll y = cXor^neg(arr[i],k);
  	if(mp[x] <= mp[y])
  	{
  		cnt+=mp[x];
  		cXor = x;
  		//cXor = cXor^arr[i];
  	}
  	else
  	{
  		cnt+=mp[y];
  		cXor = y;
  	}
  	mp[cXor]++;
  }
  //cerr << cnt << endl;
  cout << ((n*1LL*(n-1)) >> 1)+n-cnt<< endl;
}
