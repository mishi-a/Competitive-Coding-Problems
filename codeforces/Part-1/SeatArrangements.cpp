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

int arr[2005][2005];
int larr[2005][2005];
int uarr[2005][2005];
int main()
{
  sync;
  int n,m,k;
  cin >> n >> m >> k;
  int ans = 0;
  int tot = 0;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		char ch;
  		cin >> ch;
  		if(ch == '*')
  		{
  			arr[i][j]=-1;
  		}
  		else
  		{
  			tot++;
  			arr[i][j]=1;
  		}
  	}
  }
  if(k==1)
  {
  	cout << tot << endl;
  	return 0;
  }
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;)
  	{
  		if(arr[i][j]==-1)
  		{
  			j++;
  			continue;
  		}
  		else
  		{
  			int c = j;
  			int count=0;
  			while(j<m && arr[i][j]==1)
  			{
  				count++;
  				j++;
  			}
  			if(count>=k)
  				ans+=(count-k+1);
  		}
  	}
  }
  for(int i=0;i<m;i++)
  {
  	for(int j=0;j<n;)
  	{
  		if(arr[j][i]==-1)
  		{
  			j++;
  			continue;
  		}
  		else
  		{
  			int c = j;
  			int count=0;
  			while(j<n && arr[j][i]==1)
  			{
  				count++;
  				j++;
  			}
  			if(count>=k)
  				ans+=(count-k+1);
  		}
  	}
  }
  cout << ans << endl;
  
}
