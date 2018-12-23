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
int a[MAX];
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  int sum = 0;
  for(int i=0;i<n;i++) cin >> a[i],sum+=a[i];
  	if(sum%k !=0)
  	{
  		cout << "No" << endl;
  		return 0;
  	}
  vector<int> v;
  int t = 0,last = 0;
  for(int i=0;i<n;i++)
  {
  	t+=a[i];
  	if(t == sum/k)
  	{
  		v.pb(i-last+1);
  		last = i+1;
  		t = 0;
  	}
  	else if(t > sum/k)
  	{
  		cout << "No" << endl;
  		return 0;
  	}
  }
  if(t!=0)
  {
  	cout << "No" << endl;
  		return 0;
  }
  cout << "Yes" << endl;
  for(int i=0;i<v.size();i++)
  	cout << v[i] << " ";
}
