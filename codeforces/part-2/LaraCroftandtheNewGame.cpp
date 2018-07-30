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
  ll n,m,k;
  cin >> n >> m >> k;
  if(k<n)
  {
  	cout << 1+k << " " << "1" << endl;
  }
  else
  {
  	ll rem = k-(n);
  	ll up = rem/(m-1);
  	ll rem1 = rem%(m-1);
  	if(up%2==1)
  	{
  		cout << n-up << " " << m-rem1 << endl;
  	}
  	else
  	{
  		cout << n-up << " " << 2+rem1 << endl;
  	}

  }
}
