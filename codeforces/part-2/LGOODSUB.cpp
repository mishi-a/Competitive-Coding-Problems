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
vector<pair<ll,ll>> v;
vector<ll> v1;

ll maxDiff(vector<ll> arr, ll arr_size)
{
  ll max_diff = arr[1] - arr[0];
  ll min_element = arr[0];
  ll i;
  for(i = 1; i < arr_size; i++)
  {       
    if (arr[i] - min_element > max_diff)                               
      max_diff = arr[i] - min_element;
    if (arr[i] < min_element)
         min_element = arr[i];                     
  }
  return max_diff;
}

bool acompare(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.FI<b.FI)
		return true;
	else if(a.FI == b.FI)
    {
    	if(a.SE<b.SE)
    		return false;
    	else
    		return true;
    }
	else
		return false;
}
void solve()
{
	ll n;
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	for(ll i=0;i<n;i++)
		v.pb({arr[i],i});
	sort(v.begin(),v.end(),acompare);
	for(ll i=0;i<n;i++)
		v1.pb(v[i].SE);
	reverse(v1.begin(),v1.end());
    ll a = maxDiff(v1,v1.size()) +1;
    if(a == 0)
    	a= 1;
	cout << a << endl;
	v.clear();
	v1.clear();


}

int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
  	solve();
  }
}
