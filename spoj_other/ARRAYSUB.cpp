/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

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
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  int k;
  cin >> k;
  int l=0,r=0;
  while(l<=n-k)
  {
    int mux = -1;
    while(r<l+k)
    {
      if(v[r] > mux)
        mux = v[r];
      r++;
    }
    cout << mux << " ";
    l++;
    r = l;
  }
  
}

