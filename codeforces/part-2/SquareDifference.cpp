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

int check(ll x)
{
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	ll a,b;
  	cin >> a >> b;
  	if(a-b !=1 && a+b!=1)
  	{
  		cout << "NO" << endl;
  	}
  	else if(check(a-b) && check(a+b))
  	{
  		cout << "YES" << endl;
  	}
  	else
  	{
  		cout << "NO" << endl;
  	}
  }
}
