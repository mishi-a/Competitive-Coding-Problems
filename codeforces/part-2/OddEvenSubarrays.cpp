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

ll arr[200005];
ll freq[400005];
int main()
{
  sync;
  ll n;
  cin >> n;
  for(ll i=0;i<n;i++)
  {
  	cin >> arr[i];
  	if(arr[i]%2)
  		arr[i]=-1;
  	else
  		arr[i]=1;
  }
  freq[arr[0]+200001]++;
  for(ll i=1;i<n;i++)
  {
  	arr[i]+=arr[i-1];
  	freq[arr[i]+200001]++;
  }
  ll ans = 0;
  for(ll i=0;i<400005;i++)
  {
  	ans = ans + freq[i]*(freq[i]-1)/2;
  }
  ans += freq[200001];
  cout << ans << endl;
}
