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
int arr[1005][1005];
int main()
{
  sync;
  int n,m;
  char ch;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		cin >> ch;
  		if(ch == '.') arr[i][j] = 0;
  		else arr[i][j] = 1;
  	}
  }

  for(int i=1;i<n-1;i++)
  {
  	for(int j=1;j<m-1;j++)
  	{
  		int flag = 0;
  		for(int k=i-1;k<i+2;k++)
  		{
  			for(int l=j-1;l<j+2;l++)
  			{
  				if(k == i && l == j) continue;
  				if (arr[k][l] == 0)
  				{
  					//cerr << k << " " << l <<endl;
  					flag = 1;
  				}	
  			}
  		}
  		if(flag == 0)
  		{
	  		for(int k=i-1;k<i+2;k++)
	  		{
	  			for(int l=j-1;l<j+2;l++)
	  			{
	  				if(k == i && l == j) continue;
	  				arr[k][l] = -1;
	  			}
	  		}
  		}
  	}
  	
  }
  int flag = 0;
  for(int i=0;i<n;i++)
  	for(int j=0;j<m;j++)
  		if(arr[i][j] == 1)
  		{
  			flag = 1;
  			break;
  		}
  if(flag == 0)
  	cout << "YES" << endl;
  else
  	cout << "NO" << endl;
}
