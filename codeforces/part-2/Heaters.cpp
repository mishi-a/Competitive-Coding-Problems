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
int arr[1005];
vector<int> v[1005];
int main()
{
  sync;
  int n,r;
  cin >> n >> r;
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  for(int i=0;i<n;i++)
  {
  	if(arr[i]==1)
  	{
  		int l = max(0,i-(r-1));
  		int p = min(n-1,i+r-1);
  		//cerr << l << p << endl;
  		if(v[l].size()>0)
  		{
  			v[l][0] = max(v[l][0],p);
  		}
  		else
  			v[l].pb(p);
  	}
  }
  //cerr << v[4][0] << endl;
  /*for(int i=0;i<5;i++)
  	cerr << i << " " << v[i][0] << endl;*/
  int ans = 0;
  for(int i=0;i<n;)
  {
  	if(v[i].size()==0)
  	{
  		cout << "-1" << endl;
  		return 0;
  	}
  	if(v[i][0]==n-1)
  	{
  		ans++;
  		break;
  	}	
  	ans++;
  	int mux = -1;
  	for(int j=i+1;j<=v[i][0]+1;j++)
  	{
  		if(v[j].size()==0)continue;
  		else
  			mux = j;
  	}
  	if(mux == -1)
  	{
  		cout << -1 << endl;
  		return 0;
  	}
  	i=mux;
  	//ans++;
  	//cerr << i << endl;
  }
  cout << ans << endl;
}
