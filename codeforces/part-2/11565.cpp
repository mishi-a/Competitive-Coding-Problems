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
  int n;
  cin >> n;
  while(n--)
  {
  	int a,b,c;
  	cin >> a >> b >> c;
  	int flag = 0;
  	for(int i=-100;i<=100;i++)
  	{
  		for(int j=i+1;j<=100;j++)
  		{
  			for(int k=j+1;k<=100;k++)
  			{
  				if(i+j+k == a && i*j*k == b && i*i + j*j + k*k ==c)
  				{
  					flag = 1;
  					cout << i << " " << j << " " << k << endl;
  					break;
  				}
  			}
  			if(flag == 1)
  				break;
  		}
  		if(flag == 1)
  				break;
  	}
  	if(flag == 0)
  		cout << "No solution." << endl;
  }
}
