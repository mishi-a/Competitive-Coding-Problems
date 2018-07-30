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

void solve()
{
  int n;
  cin >> n;
  if(n == 1)
  {
    cout << "1" ;
    return ;
  }
  else if(n == 2)
  {
    cout << "1 2" ;
    return ;
  }
  cout << "1 2 4" << " ";
  n=n-3;
  int t = 7;
  while(n > 0)
  {
    cout << t  << " ";
    n--;
    t = t+3;
  }
  return;
}


int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    cout << endl;
  }
}

