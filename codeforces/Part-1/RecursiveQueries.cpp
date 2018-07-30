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
int arr[15][1000005];

int findProd(int num)
{
	int p = 1;
	while(num!=0)
	{
		if(num%10!=0)
			p=p*(num%10);
		num/=10;
	}
	return p;
}

int solve(int val)
{
	if(val < 10)
		return val;
	else
	{
		int prod = findProd(val);
		return solve(prod);
	}
}

void pre()
{
	for(int i=1;i<=1000001;i++)
	{
		int val = solve(i);
		arr[val][i]=1;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=1;j<=1000001;j++)
			arr[i][j]+=arr[i][j-1];
	}
	// for(int i=0;i<10;i++)
	// {
	// 	for(int j=1;j<=50;j++)
	// 		cout << arr[i][j] << endl;
	// }
}

int main()
{
  sync;
  pre();
  int q;
  cin >> q;
  while(q--)
  {
  	int l,r,k;
  	cin >> l >> r >> k;
  	cout << arr[k][r]-arr[k][l-1]<<endl;
  }
}
