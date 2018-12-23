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

int a[MAX],b[MAX],c[MAX];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++)
  	cin >> a[i];
  for(int i=0;i<n-1;i++)
  	cin >> b[i];

  for(int i=0;i<n-1;i++)
  {
  	if(b[i]>a[i])
  	{
  		cout << "NO" << endl;
  		return 0;
  	}
  }
  //cout << "YES"  << endl;
  int flag = 0,start=0;
  while(start <= 3)
  {
  	c[n-1] = start;
  	//cerr << start << endl;
  	for(int i= n-2;i>=0;i-- )
  	{
  		flag = 0;
  		for(int j=0;j<=3;j++)
  		{
  			if(((j&c[i+1]) == b[i]) && ((j|c[i+1]) == a[i]))
  			{
  				//cerr << i << " " << c[i] << endl;
  				c[i] = j;
  				flag = 1;
  				break;
  			}
  		}
  		if(flag == 0)
  			break;
  		
  	}
  	if(flag == 1)
  	{
  		cout << "YES" << endl;
  		for(int i=0;i<n;i++)
  			cout << c[i] << " ";
  		cout << endl;
  		return 0;
  	}
  	start++;
  }
  cout << "NO" << endl;
}
