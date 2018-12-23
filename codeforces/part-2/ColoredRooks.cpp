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

vector <int> v[105];
int arr[105],n;
int cur;
map<pii,int> mp;
void print(int idx)
{
	{
		int ans = v[idx].size();
		cout << ans+1 << endl;
		cout << 1+(idx-1) << " " << n-(idx-1) << endl; 
		for(int i=0;i<v[idx].size();i++)
		{
			cout << v[idx][i]<< " " << n-(idx-1)<< endl;
			cur++;
		}
	}
}
int main()
{
  sync;
  int m;
  cin >> n >> m;
  cur = n+1;
  for(int i=0;i<m;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	v[a].pb(cur);
  	v[b].pb(cur);
  	cur++;
  	//arr[min(a,b)]++;
  }
  //cerr << v[2].size() << endl;
  for(int i=1;i<=n;i++)
  {
  	print(i);
  }

}
