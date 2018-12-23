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

void solve()
{
	int n;
	cin >> n;
	int a,last,first;
	cin >> a;
	last = a,first=a;
	int dec = 0;
	for(int i=1;i<n;i++)
	{
		cin >> a;
		if(a < last)
			dec++;
		last = a;
	}
	if(dec>1)
	{
		cout << "NO" << endl;
		return ;
	}
	//cerr << dec << endl;
	if(last<=first || dec == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	solve();
  }
}
