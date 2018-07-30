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

int arr[100][100];
int row1[100],col1[100];
set<int> row,col;
int last[100];
int arr1[100][100];
void solve()
{
	set<int>::iterator itr = row.begin();
	set<int>::iterator itr1 = col.begin();
	while(itr!=row.end())
	{
		while(itr1!=col.end())
		{
			arr1[*itr][*itr1]=1;
			itr1++;
		}
		itr1 = col.begin();
		itr++;
	}
	
}
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		char ch;
  		cin >> ch;
  		if(ch == '.')
  			arr[i][j]=0;
  		else
  			arr[i][j]=1;
  	}
  }
  for(int i=0;i<n;i++)
  {
  	if(row1[i]==0)
  	{
 		row1[i]=1;
  		for(int j=0;j<m;j++)
  		{	
  			if(col1[j] == 0 &&arr[i][j]==1)
  			{
  				row.insert(i);
  				col1[j]=1;
  				col.insert(j);
  				for(int k=i+1;k<n;k++)
  				{
  					if((row1[k]==0 || last[k]==i)&&arr[k][j]==1)
  					{
  						row1[k]=1;
  						last[k]=i;
  						row.insert(k);
  					}	
  				}
  			}

  		}
  		
  	}
  	solve();
  	col.clear();
  	row.clear();
  }
 
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		if(arr[i][j]!=arr1[i][j])
  		{
  			cout << "No" << endl;
  			return 0;
  		}
  	}
  }
  cout << "Yes" << endl;
}
