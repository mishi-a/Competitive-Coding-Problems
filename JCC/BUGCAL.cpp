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
vector <int> v;
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int a,b;
  	cin >> a >> b;
  	while(a!=0&&b!=0)
  	{
  		int x = a%10;
  		int y = b%10;
  		v.pb((x+y)%10);
  		a = a/10;
  		b = b/10;
  	}
  	while(a!=0)
  	{
  		v.pb(a%10);
  		a/=10;
  	}
  	while(b!=0)
  	{
  		v.pb(b%10);
  		b/=10;
  	}
  	int idx = v.size()-1;
  	int flag = 0;
  	while(v[idx]==0)
  		idx--;
  	for(int i=idx;i>=0;i--)
  		cout << v[i],flag=1 ;
  	if(flag==0)
  		cout <<"0";
  	cout << endl;
  	v.clear();
  }
}
