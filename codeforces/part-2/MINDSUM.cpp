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
ll value;
int getCount(ll n)
{
	int cnt = 0;
	ll bound = 0;
	ll temp = n;
	{
		bound = 0;
		while(temp!=0)
		{
			bound+=temp%10;
			temp/=10;
		}
		cnt++;
	}
	value = bound;
}
map<int,int> mp;
ll solve(ll n,ll d,int step,int depth)
{
  //cerr << n << " " << d << " " << step << endl;
  
  //cerr << cnt << " " << value << " " << mp[value] <<endl;
  if(n/10 == 0)
  {
    if(mp[n] == 0)
      mp[n] = step;
    else
      mp[n] = min(step,mp[n]);
  }
  if(depth>15 && n/10 == 0)
  {
    mp[n] = min(step,mp[n]);
    return 0;
  }
  else if(depth > 15)
  {
    return 0;
  }
  else
  {
    
    solve(n+d,d,step+1,depth+1);
    getCount(n);
    solve(value,d,step+1,depth+1);
  }
  return 0;
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	ll n,d;
  	cin >> n >> d;
    getCount(n);
    solve(n,d,1,0);
    cout << mp.begin()->FI << " " << mp.begin()->SE - 1 << endl;
    mp.clear();
  }
  
}
