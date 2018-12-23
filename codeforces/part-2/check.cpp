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
ll a[7005];

int main()
{
  sync;
  ll t,tot=0;
  cin >> t;
  while(t--)
  {
  	tot++;
  	ll n;
  	cin >> n;
  	for(int i=0;i<n;i++)
  		cin >> a[i];
  	sort(a,a+n);
  	ll ans = 0;
  	for(int i=0;i<n;i++)
  	{
  		for(int j=i+1;j<n;j++)
  		{
  			for(int k=j+1;k<n;k++)
  			{
  				if(a[k] == a[i]*a[j])
  				{
  					ans++;
  				}	
  				else if(a[i] == a[k]*a[j])
  				{
  					ans++;
  				}
  				else if(a[j] == a[k]*a[i])
  					ans++;
  			}
  		}
  	}
  	cout << "Case #" << tot << ": " << ans << endl;
  }
}
