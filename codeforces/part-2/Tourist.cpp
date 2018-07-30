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

void solve()
{
	ll n,k,v;
	cin >> n >> k >> v;
	vector<string> V(n);
	for(ll i=0;i<n;i++)
		cin >> V[i];
	ll s = 0;
	ll idx = (k*(v-1))%n;
	
	if((idx+k-1)%n < idx)
	{
		for(ll i=0;i<=	(idx+k-1)%n;i++)
			cout << V[i] << " ";
		k = k - ((idx+k-1)%n)-1;
	}

	while(s!=k)
	{
		cout << V[idx] << " ";
		idx = (idx+1)%n;
		s++;
	}
	cout << endl;
}

int main()
{
  sync;
  ll t;
  cin >> t;
  for(ll i=1;i<=t;i++)
  {
  	cout << "Case #" << i << ": ";
  	solve();
  }
}
