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
int a[1005],b[1005];
int main()
{
  sync;
  int n,s;
  cin >> n >> s;
  for(int i=1;i<=n;i++)cin >> a[i];
  for(int i=1;i<=n;i++)cin >> b[i];
  if(a[1] == 0 || (a[s] == 0 && b[s] == 0))
  {
  	cout << "NO" ;
  }	
  else
  {
  	if(a[s] == 1)
  	{
  		cout << "YES" << endl;
  		return 0;
  	}
  	for(int i=s+1;i<=n;i++)
  	{
  		if(a[i]==1 && b[i]==1)
  		{
  			if(b[s] == 1)
  			{
  				cout << "YES" << endl;
  				return 0;
  			}
  		}
  	}
  	cout << "NO" ;
  }
}
