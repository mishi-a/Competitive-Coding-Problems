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
char arr[105][105],arr1[105][105],check[105][105];
int main()
{
  sync;
  int t;
  cin >> t;
  for(int i=0;i<102;i++)
  {
  	for(int j=0;j<102;j++)
  	{
  		if(i%2==0)
  		{
          if(j%2==0)
          	arr[i][j]='R';
          else
          	arr[i][j]='G';
  		}
  		else
  		{
          if(j%2==0)
          	arr[i][j]='G';
          else
          	arr[i][j]='R';
  		}
  	}
  }
  for(int i=0;i<102;i++)
  {
  	for(int j=0;j<102;j++)
  	{
  		if(i%2==1)
  		{
          if(j%2==0)
          	arr1[i][j]='R';
          else
          	arr1[i][j]='G';
  		}
  		else
  		{
          if(j%2==0)
          	arr1[i][j]='G';
          else
          	arr1[i][j]='R';
  		}
  	}
  }
  while(t--)
  {
  	int n,m;
  	cin >> n >> m;
  	for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<m;j++)
  			cin >> check[i][j];
  	}
  	int ans=0,ans1=0;
  	for(int i=0;i<n;i++)
  	{
  		for(int j=0;j<m;j++)
  		{
  			if(check[i][j]!=arr[i][j]&&check[i][j]=='R')
  				ans+=5;
  			if(check[i][j]!=arr[i][j]&&check[i][j]=='G')
  				ans+=3;
  			if(check[i][j]!=arr1[i][j]&&check[i][j]=='R')
  				ans1+=5;
  			if(check[i][j]!=arr1[i][j]&&check[i][j]=='G')
  				ans1+=3;
  		}
  	}
  	cout << min(ans1,ans) << endl;
  }
}
