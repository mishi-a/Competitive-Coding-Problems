/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
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
	if(par[y] < par[x])	// balancing the height of the trees
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/
		

using namespace std;

int main()
{
  sync;
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  if(n==1) 
  	cout << "0" << endl;
  else if(n==2)
  	cout << min(a,b) << endl;
  else
  {
	  	int dist = min(a,b)+(n-2)*min(c,min(a,b));
	    cout << dist << endl;
   }
}
