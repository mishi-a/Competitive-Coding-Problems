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

vector<int> v;

int main()
{
  sync;
  int n,u;
  cin >> n >> u;
  for(int i=0;i<n;i++)
  {
  	int a;
  	cin >> a;
  	v.pb(a);
  }
  sort(v.begin(),v.end());
  double ans = -1;
  for(int i=0;i<n-2;i++)
  {
  	int val=v[i]+u;
  	int idx = lower_bound(v.begin()+i+1,v.end(),val)-v.begin();
  	if(idx == n)
  		idx--;
  	else if(v[idx] != val)
  		idx--;
  	if(idx == i || idx ==i+1)
  		continue;
  	double val1 = (v[idx]-v[i+1])/((v[idx]-v[i])*1.0);
  	if(val1>ans)
  		ans = val1;
  	//cout << val1 << " " << ans << endl;
  }
  if(ans < 1e-10)
  	ans = -1;
  cout << fixed << setprecision(10) << ans << endl;
}
