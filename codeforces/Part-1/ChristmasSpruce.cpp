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

vector <int> v[10005];
int arr[10005];

void dfs(int root)
{
	arr[root]=v[root].size();
	for(int i=0;i<v[root].size();i++)
		dfs(v[root][i]);
}

int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=2;i<=n;i++)
  {
  	int p;
  	cin >> p;
  	v[p].pb(i);
  }
  dfs(1);
  for(int i=1;i<=n;i++)
  {
  	int cnt=0;
  	if(arr[i]>0){
  	for(int j=0;j<v[i].size();j++)
  	{
      if(arr[v[i][j]]==0)
      	cnt++;
  	}
  	if(cnt <3)
  	{
  		cout << "No" << endl;
  		return 0;
  	}
  }
  }
  cout << "Yes" << endl;
}
