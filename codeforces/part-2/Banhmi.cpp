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

const int MAX = 2e6+7;
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
ll mod = 1e9+7;
ll arr[MAX],arr1[MAX];
int main()
{
  sync;
  arr[1] = 1;
  for(int i=2;i<=1e6+2;i++) arr[i] = (arr[i-1]*2)%mod;
  for(int i=2;i<=1e6+2;i++) arr[i] = (arr[i]+arr[i-1])%mod;
  ll n,q;
  cin >> n >> q;
  string s;
  cin >> s;	
  for(int i=1;i<=s.size();i++)
  	arr1[i] = s[i-1]-'0';
  for(int i=2;i<=n;i++)
  	arr1[i]+=arr1[i-1];
  while(q--)
  {
  	ll l,r;
  	cin >> l >> r;
  	ll c1 = arr1[r]-arr1[l-1];
  	ll c0 = (r-l+1)-c1;
  	cout << (arr[c1]+(arr[c1]*arr[c0])%mod)%mod << endl;
  }
}
