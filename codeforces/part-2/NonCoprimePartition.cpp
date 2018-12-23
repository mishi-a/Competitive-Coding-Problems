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

const int MAX = 1e5;
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
  int val = (n*(n+1))/2;
  //cout << val << endl;
  for(int i=1;i<=val;i++)
  {
  	if(val%(1+i) == 0 && val/(1+i) <= n)
  	{
  		if(val/(1+i) == 1)
  		{
  			cout << "No" << endl;
  			return 0;
  		}
  		else
  		{
  			cout << "Yes" << endl;
  			cout << 1 << " " << val/(1+i) << endl;
  			cout << n-1 << " ";
  			for(int j=1;j<=n;j++)
  			{
  				if(j == (val/(1+i))) continue;
  				cout << j << " ";
  			}
  			cout << endl;
  			return 0;
  		}
  	}
  }
  cout << "No" << endl;  
}
