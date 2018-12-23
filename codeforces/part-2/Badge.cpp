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
int p[1100];
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  	cin >> p[i];
  map<int,int> mp;
  for(int i=1;i<=n;i++)
  {
  	mp[i]++;
  	bool hole = false;
  	int cul = p[i];
  	while(!hole)
  	{
  		mp[cul]++;
  		cul = p[cul];
  		if(mp[cul] == 2)
  		{
  			cout << cul << " ";
  			mp.clear();
  			hole = true;
  		}
  	}
  }
}
