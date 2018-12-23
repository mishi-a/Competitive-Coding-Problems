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

int main()
{
  sync;
  int n;
  cin >> n;
  if(n == 3)
  	cout << "1 1 3";
  else if (n==2)
  	cout << "1 2";
  else if(n == 1)
  	cout << "1";
  if(n>3)
  {
  	for(int i=1;i<=n;i+=2)
  		cout << 1 << " " ;
  	for(int j=2;j<=n;j=j*2)
  	{
  		for(int i=j;i<=n;i+=2*j)
  		{
  			if(n/j == 3)
  			{
  				cout << j << " " << i << " " << i*3 << endl;
  				return 0;
  			}
  			cout << j << " " ;
  		}
  	}
  }
}
