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
ll arr[MAX],arr1[MAX],n,m;
bool check( ll mid)
{
  ll x = m;
  for(int i=0;i<n;i++)
  {
    ll z = arr[i]*arr1[i]; 
    if(z <= mid) continue;
    else
    {
      //cerr << i << " " << x << endl;
      x -= ceil(arr[i]-(mid/arr1[i]*1.0));
      //cerr << x << endl;
    }
  }
  //cerr << x << endl;
  if(x<0)
    return false;
  else
    return true;
}
int main()
{
  sync;
  cin >> n >> m;
  for(int i=0;i<n;i++)
    cin >> arr[i];
  for(int i=0;i<n;i++)
    cin >> arr1[i];
  ll l = 0,r=2e18;
  ll ans = 0;
  while(l<=r)
  {
    ll mid = l+((r-l)/2);
    if(check(mid))
    {
      ans = mid;
      r = mid-1;;
    }
    else
      l = mid+1;
  }
  cout << ans << endl;
}
