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

int main()
{
  sync;
  ll n,q;
  cin >> n >> q;
  ll arr[200005],arr1[200005];
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  for(int i=0;i<q;i++)
  	cin >> arr1[i];

  for(int i=1;i<n;i++)
  	arr[i]+=arr[i-1];
  for(int i=1;i<q;i++)
  {
  	arr1[i]+=arr1[i-1];
  	if(arr1[i-1]>=arr[n-1])
  		arr1[i]-=arr1[i-1];
  }

  vector <ll> v,v1;
  for(int i=0;i<n;i++)
  	v.pb(arr[i]);
  for(int i=0;i<q;i++)
  	v1.pb(arr1[i]);
  for(int i=0;i<q;i++)
  {
  	int idx = lower_bound(v.begin(),v.end(),v1[i])-v.begin();
  	if(idx == n || (idx == n-1 && v[idx]==v1[i]))
  		cout << n << endl;
  	else if(v[idx] == v1[i])
  		cout << n-1-idx << endl;
  	else
  		cout << n-idx << endl;

  }
}
