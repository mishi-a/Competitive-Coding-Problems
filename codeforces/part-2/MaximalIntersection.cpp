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
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
const int MAX = 3e5+7;
const int INF = INT_MAX;
vector<pair<ll,ll>> v,v1,v2;

int l[MAX],r[MAX];
int sl[MAX],el[MAX],sr[MAX],er[MAX];
int main()
{
  sync;
  ll n;
  cin >> n;
  for(int i=0;i<n;i++)
  	cin >> l[i] >> r[i];
  sl[0] = l[0],sr[0]=r[0];
  for(int i=1;i<n;i++)
  {
  	sl[i] = max(sl[i-1],l[i]);
  	sr[i] = min(sr[i-1],r[i]);
  }
  el[n-1] = l[n-1],er[n-1] = r[n-1];
  for(int i=n-2;i>=0;i--)
  {
  	el[i] = max(el[i+1],l[i]);
  	er[i] = min(er[i+1],r[i]);
  }
  int ans = 0;
  for(int i=0;i<n;i++)
  {
  	ans = max(ans,min((i==n-1?INF:er[i+1]),(i==0?INF:sr[i-1]))-max((i==0?0:sl[i-1]),(i==n-1?0:el[i+1])));
  }
  cout << ans << endl;
}
