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

int arr[10][200];
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  cout << "YES" << endl;
  if(k<=n-2)
  {
  	{
  		if(k%2 == 1)
  		{
  			arr[1][n/2]=1;
  			k--;	
  		}
  		for(int i=1;k>0&&i<n/2;i++)
  		{
  			arr[1][i] = 1;
  			arr[1][n-1-i]=1;
  			k-=2;
  		}
  	}
  }
  	else
  	{
  		for(int i=1;i<n-1;i++)
  			arr[1][i] = 1;
  		int rem = k-n+2;
  		if(rem%2 == 1)
  		{
  			arr[2][n/2]=1;
  			rem--;
  		}
  		for(int i=1;rem>0&&i<n/2;i++)
  		{
  			arr[2][i] = 1;
  			arr[2][n-1-i]=1;
  			rem-=2;
  		}
  	}
  	for(int i=0;i<4;i++)
  	{
  		for(int j=0;j<n;j++)
  		{
  			if(arr[i][j]==1)
  				cout << "#";
  			else
  				cout <<".";
  		}
  		cout << endl;
  	}
  }
