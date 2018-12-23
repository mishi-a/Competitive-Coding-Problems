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

const int MAX = 1e5;
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

int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  char arr[n+1][m+1];
  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
  		cin >> arr[i][j];
  	}
  }
  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
  		if(arr[i][j] == 'B')
  		{
  			//cout << i << " " << j <<  endl;
  			int len = 1;
  			for(int k=j+1;k<=m;k++)
  			{
  				if(arr[i][k] == 'B')
  					len++;
  			}
  			int row = j+(len/2);
  			len = 1;
  			for(int k=i+1;k<=n;k++)
  			{
  				if(arr[k][j] == 'B')
  					len++;
  			}
  			cout << i+(len/2) << " " << row << endl;
  			return 0;
  		}
  	}
  }
}
