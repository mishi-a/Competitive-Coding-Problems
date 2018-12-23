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
ll arr[MAX],arr1[MAX];
vector<ll> v;
int main()
{
  sync;
  ll n,d;
  cin >> n >> d;
  ll sum = 0;
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  sum = arr[d-1];
  for(int i=0;i<n;i++)
  	cin >> arr1[i];
  sum+=arr1[0];
  int start = 0,idx = n-1;
  v.pb(sum);
  for(int i=0;i<n;i++)
  {
  	if(i == d-1)continue;
  	if(arr[i]>sum)
  	{
  		start++;
  		v.pb(arr[i]+arr1[start]);
  	}
  	else
  	{
  		if(idx == start)
  			break;
  		v.pb(arr[i]+arr1[idx]);
  		idx--;
  	}
  }
  sort(v.begin(),v.end());
  /*for(int i=0;i<v.size();i++)
  	cout << v[i] << " ";
  cout << endl;*/
  idx = upper_bound(v.begin(),v.end(),sum)-v.begin();
  idx--;
  cout << n-idx << endl;
}
