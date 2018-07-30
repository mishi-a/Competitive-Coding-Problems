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
 
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	double n,s;
  	cin >> n >> s;
  	if(n==1&s!=0)
  	{
  	  printf("-1\n");
  	  continue;
  	}
  	double b = (n*n*s*s)/(n-1)+3.0;
  	{
  		for(int i=1;i<=n-1;i++)
  			printf("1 ");	
  		double x = (-1+sqrt(b))/2;
  		printf("%0.10lf",x);
  		printf("\n");
  	}
  }
}
 
