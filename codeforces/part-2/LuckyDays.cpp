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

int main()
{
  sync;
  ll la,ra,ta,lb,rb,tb;
  cin >> la >> ra >> ta >> lb >> rb >> tb;
  ll ans = max(0*1LL,lb-la+ra-rb);
  cerr << ans << endl;
  ans = max(ans,rb-la+ra-lb);
  cerr << ans << endl;
  if(ra-rb+lb-la>=0)
  	ans = max(ans,rb-lb+1);
  cerr << ans << endl;
  if(rb-ra+la-lb>=0)
  	ans = max(ans,rb-lb+1);
  cerr << ans << endl;
  cout << ans << endl;
}
