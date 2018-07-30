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
  int n,r,k;
  cin >> n >> r >> k;
  int b = n-r;
  int mun ,mux;
  if(k<=b)
  	mux = r+k;
  if(k>b)
  	mux = r+b-(k-b);
  if(k<=r)
  	mun = r-k;
  if(k>r)
    mun = 0+k-r;
   cout << mun << " " << mux << endl; 
}
