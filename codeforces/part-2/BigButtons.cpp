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
ll power(ll n,ll p)
{
	if(p == 0) return 1;
	ll ans = 1;
	if(p%2) ans = ans*n;
	return ans*power(n,p/2)*power(n,p/2);
}

int main()
{
  sync;
  int t,tot=1;
  cin >> t;
  while(t--)
  {
  	cout << "Case #"<<tot<< ": ";
  	tot++;
  	int n,p;
  	cin >> n >> p;
  	ll ans = power(2,n);
  	vector<string> v;
  	for(int i=0;i<p;i++)
  	{
  		string s;
  		cin >> s;
  		v.pb(s);
  	}
  	sort(v.begin(),v.end());
  	int start = 0;
  	while(start<v.size())
  	{
  		int end=start+1;
  		while(end<v.size() && v[start] == v[end].substr(0,v[start].size()))
  			end++;
  		ans-=power(2,n-v[start].size());
  		start = end;
  	}
  	cout << ans << endl;

  }
}
