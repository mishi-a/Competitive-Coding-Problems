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

int arr[505][505],ans[505][505];
int n,m;
void reach(int row,int col)
{
	int i = row,j=col;
	//cout << i << " " << j << endl;
	int min = arr[row][col];
	while(1)
	{
		int idx = i,idx1=j;
		if(i-1>=0 && arr[row-1][j]<min)
			min = arr[row-1][j],i=row-1,j=col;
		if(row+1<n && arr[row+1][col]<min)
			min = arr[row+1][col],i = row+1,j=col;
		if(col-1>=0 && arr[row][col-1]<min)
			min = arr[row][col-1],j=col-1,i=row;

		if(col+1<m && arr[row][col+1]<min)
			min = arr[row][col+1],j = col+1,i=row;
		if(row-1>=0 && col-1>=0 && arr[row-1][col-1]<min)
			min = arr[row-1][col-1],i = row-1,j=col-1;
        if(row-1>=0 && col+1<m && arr[row-1][col+1]<min)
			min = arr[row-1][col+1],i = row-1,j=col+1;
		if(row+1<n && col-1>=0 && arr[row+1][col-1]<min)
			min = arr[row+1][col-1],i = row+1,j=col-1;
		if(row+1<n && col+1<m && arr[row+1][col+1]<min)
			min = arr[row+1][col+1],i = row+1,j=col+1;
        if(i==idx && j==idx1)
        {
        	ans[i][j]++;
        	return;
        }
        row = i,col = j;
       //cout << min << " " << i << " " << j << endl;
	}
}

int main()
{
  sync;

  cin >> n >> m;
  for(int i=0;i<n;i++)
  	for(int j=0;j<m;j++)
  		cin >> arr[i][j];
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		reach(i,j);
  	//   cout << "hi";
  	}
  	//break;
  }
  //	 reach(2,1);

  
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  		cout << ans[i][j] << " ";
  	cout << endl;
  }
}
