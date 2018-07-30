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

ll check(ll num)
{
	ll sum = 0;
	while(num!=0)
	{
		sum+=(num%10);
		num/=10;
	}
	return sum;
}

int main()
{
  sync;
  int k;
  cin >> k;
  ll num = 19;
  k--;
  while(k--)
  {
  	num+=9;
  	if(check(num)!=10)
  	{
  		while(1)
  		{
  			num+=9;
  			if(check(num)==10)
  				break;
  		}
  	}
  }
  cout << num << endl;
}
