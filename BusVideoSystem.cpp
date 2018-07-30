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

ll arr[1005];
int main()
{
  sync;
  ll n,w;
  cin >> n >> w;
  ll mux = 0;
  ll mun = LONG_MAX;
  ll sum = 0;
  for(int i=0;i<n;i++)
  {
  	ll num;
  	cin >> num;
  	sum+=num;
  	if(sum > mux)
  		mux = sum;
  	if(sum<mun)
  		mun = sum;
  }
  int start = 0;
  int end = w;
  if(mun < 0)
  	start = -1*mun;
  if(mux>0)
  	end = w-mux;
  cout << (end-start+1>0 ?end-start+1:0)  << endl;
  
}
