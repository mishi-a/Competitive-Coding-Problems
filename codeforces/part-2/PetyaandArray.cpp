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
ll arr[MAX];
ll ans = 0,t;
void merge(ll start,ll mid,ll end)
{
	vector<ll> v,v1,m;
	for(int i=start;i<=mid;i++)
		v.pb(arr[i]);
	for(int i=mid+1;i<=end;i++)
		v1.pb(arr[i]);
	int l=0,r=0;
	while(l<v.size()&&r<v1.size())
	{
		if(v[l]<=v1[r])
		{
			m.pb(v[l++]);
		}
		else
			m.pb(v1[r++]);
	}
	while(l < v.size())
		m.pb(v[l++]);
	while(r < v1.size())
		m.pb(v1[r++]);
	for(int i=start;i<=end;i++)
		arr[i] = m[i-start];


}
void mergeSort(int start,int end)
{
	if(start >= end)
		return;
	int mid = (start+end)/2;
	mergeSort(start,mid);
	mergeSort(mid+1,end);
	for(int i=start;i<=mid;i++)
	{
		ans += (lower_bound(arr+mid+1,arr+end+1,arr[i]+t)-arr)-(mid+1);
	}
	merge(start,mid,end);
}
int main()
{
  sync;
  ll n;
  cin >> n >> t;
  for(int i=1;i<=n;i++)
  {
  	cin >> arr[i];
  	arr[i]+=arr[i-1];
  }
  mergeSort(0,n);
  cout << ans << endl;
}
