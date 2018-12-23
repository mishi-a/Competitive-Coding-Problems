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
  ll ans = n,mun=0;
  for(ll i=2;i<n;i++)
  {
  	ll ans1 = i,res=0;
  	while(ans1<n)
  	{
  		//cerr << ans1 << endl;
  		ans1 = ans1*ans1;
  		res++;
  	}
  	//return 0;
  	//cerr << ans1 << " " << res << endl;
  	//return 0;
  	if(ans1%n==0)
  	{
  		if((ans1/n)!=1)
  			res++;
  		cout << i << " " << res << endl;	
  		return 0;
  	}
  }
  cout << ans << " " << mun << endl;
}