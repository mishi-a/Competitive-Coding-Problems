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
int arr[MAX];
int main()
{
  sync;
  ll n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<n;i++)
  	cin >>arr[i];
  int cBox = 0,temp = k,ans=0;
  for(int i=n-1;i>=0;i--)
  {
  	if(arr[i]<=temp)
  	{
  		ans++;
  		temp-=arr[i];
  	}
  	else
  	{
  		cBox++;
  		if(cBox == m)
  			break;
  		temp = k;
  		i++;
  	}
  }
  cout << ans << endl;
}
