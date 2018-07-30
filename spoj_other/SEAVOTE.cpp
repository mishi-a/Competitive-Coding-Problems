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

void solve()
{
  int n,tot;
  cin >> n;
  tot = n;
  int sum = 0;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    if(a==0)
      tot--;
    sum+=a;
  }
  n = tot;
  sum = sum-n;
  if(sum >= 100 || sum < 100-n)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  
  

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

