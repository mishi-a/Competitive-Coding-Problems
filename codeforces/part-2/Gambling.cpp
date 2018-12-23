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

const int MAX = 1e5+7;
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

ll a[MAX],b[MAX],n;
ll aMax,bMax;
int main()
{
  sync;
  cin >> n;
  for(ll i=0;i<n;i++)
  	cin >> a[i];
  for(ll i=0;i<n;i++)
  	cin >> b[i];
  sort(a,a+n,greater<ll>());
  sort(b,b+n,greater<ll>());
  //solve(0,0,1);
  ll idx = 0,bIdx = 0;
  for(ll i=0;i<n;i++)
  {
  	if(b[bIdx] > a[idx])
  	{
  		bIdx++;
  	}
  	else
  	{
  		aMax += a[idx];
  		idx++;
  	}
  	if(a[idx]>b[bIdx])
  	{
  		idx++;
  	}
  	else
  	{
  		bMax += b[bIdx];
  		bIdx++;
  	}
  }
  cout << aMax-bMax << endl;
}
