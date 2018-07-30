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

bool check(ll n)
{
	while(n!=0)
	{
		if((n%10)%2==1)
			return false;
		n/=10;
	}
	return true;
}

int main()
{
  sync;
  int t;
  cin >> t;
  int val=1;

  while(t--)
  {
  	ll n,n1,n2;
  	cin >> n;
  	n1=n2=n;
  	ll ans1=n,ans2=n;
  	while(1)
  	{
  		if(check(n))
  		{
  			ans1 = n;
  			break;
  		}
  		n++;
  	}
  	n=n1;
  	while(1&&n>=0)
  	{
  		if(check(n))
  		{
  			ans2=n;
  			break;
  		}
  		n--;
  	}
  	
  	cout << "Case #"<<val<<": " <<min(ans1-n1,n1-ans2) << endl;
  	val++;
  }
}
