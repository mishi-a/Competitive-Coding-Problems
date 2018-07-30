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

vector <pii > v;

void solve()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    v.pb({a,b});
  }
  sort(v.begin(),v.end());
  int high = v[0].second;
  int cnt = 1;
  for(int i=1;i<n;i++)
  {
    if(v[i].first > high)
    {
      cnt++;
      high = v[i].second;
    }
    else if(v[i].second < high)
    {
      high = v[i].second;
    }
    
  }
  cout << cnt << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    v.clear();
  }
}

