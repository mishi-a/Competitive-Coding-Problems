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
char arr[1000][1000];
int main()
{
  sync;
  int r,c;
  cin >> r >> c;
  for(int i=0;i<r;i++)
  {
  	for(int j=0;j<c;j++)
  		cin >> arr[i][j];
  }
  for(int i=0;i<r;i++)
  {
  	for(int j=0;j<c;j++)
  	{
  		if(arr[i][j]=='S')
  		{
  			if((i+1<r && arr[i+1][j]=='W')||(i-1>=0&&arr[i-1][j]=='W'))
  			{
  				cout << "No";
  				return 0;
  			}
 			if((j+1<c&&arr[i][j+1]=='W')||(j-1>=0&&arr[i][j-1]=='W'))
 			{
 				cout <<"No";
 				return 0;
 			}

  		}
  	}
  }
  cout << "Yes" << endl;
  	for(int i=0;i<r;i++)
  	{
  		for(int j=0;j<c;j++)
  		{
  			if(arr[i][j]=='.')
  				cout <<'D';
  			else
  			{
  				cout <<arr[i][j];
  			}
  		}
  		cout << endl;
  	}
}
