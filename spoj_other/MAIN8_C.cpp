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

vector <int> v;
int n,p;
bool func(int t)
{
 int k = p;
  int i = n-1;
  if(t==0)
    return true;
  while(i>=0)
  {
    if(v[i] >= t)
    {
      k = k - v[i]/t;
      if(k <= 0)
        return true;
    } 
    else if(k!=0 && v[i] < t)
    { 
       return false;
    }
    i--;
  }
  if(k!=0)
    return false;
}

int dbs()
{
  int l = 0;
  int r = v[v.size()-1];
  int ans = 0;
  while(l<=r)
  {
    int mid = (l+r)/2;
    if(func(mid) == true)
    {
      ans = max(ans,mid);
      l = mid+1;
    }
    else
    {
      r = mid - 1;
    }
    
  }
  return ans; 
}

void solve()
{
  cin >> n >> p;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  sort(v.begin(),v.end());
  int res = dbs();
  cout << res << endl;
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

