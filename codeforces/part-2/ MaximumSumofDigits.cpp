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
  ll n;
  cin >> n;
  if(n%10 == 0)
  {
  	ll res = n-1;
  	ll sum = 0;
  	while(res!=0)
  	{
  		sum+=(res%10);
  		res/=10;
  	}
  	cout << sum+1 << endl;
  }
  else
  {
  	ll r = n%10+1;
  	ll sum = 0;
  	n = n-(n%10+1);
  	while(n!=0)
  	{
  		sum+=(n%10);
  		n/=10;
  	}
  	cout << sum+r << endl;
  }
}
