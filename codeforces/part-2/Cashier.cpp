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
  int n,m,a;
  cin >> n >> m >> a;
  int ans = 0;
  int lastTime = -1;
  if(n == 0)
  {
  	cout << m/a << endl;
  	return 0;
  }
  for(int i=0;i<n;i++)
  {
  	int t,l;
  	cin >> t >> l;
  	if(i==0)
  	{
  		ans+=(t/a);
  		lastTime = t+l;
  		if( i == n-1)
  		{
  			ans+= (m-lastTime)/a;
  		}
  	}
  	else if(i == n-1)
  	{
  		ans+= (t-lastTime)/a;
  		ans += (m-(t+l))/a;
  	}
  	else
  	{
  		ans+=(t-lastTime)/a;
  		lastTime = t+l;
  	}
  }
  cout << ans << endl;
}
