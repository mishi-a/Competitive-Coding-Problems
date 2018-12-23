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
int arr[MAX];
set<ll> s;
int main()
{
  sync;
  ll n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	ll a,b;
  	cin >> a>>b;
  	s.insert(a+b);
  }
  ll l = 1,r=2e9+2;
  ll ans = 2e9+2;
  while(l<=r)
  {
  	ll mid = (l+r)/2;
  	auto itr = upper_bound(s.begin(),s.end(),mid);
  	if(itr == s.end())
  	{
  		ans = min(ans,mid);
  		r = mid-1;
  	}
  	else
  		l = mid+1;
  }
  cout << ans << endl;
}
