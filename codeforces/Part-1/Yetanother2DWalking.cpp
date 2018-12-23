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
struct point
{
	ll x,y;
	point(ll _x,ll _y)
	{
		x = _x;
		y = _y;
	}
	bool operator <(point p) const
	{
		return x<p.x || y>p.y;
	}
};
ll pathsum[MAX],lastLevel;
map<ll,vector<point>> mp,mp1;
ll dp[MAX][2];
ll solve(ll level,ll end)
{
	if(level==mp1.size()-1)
		return pathsum[level];
	if(dp[level][end]!=-1)
		return dp[level][end];
	else
	{
		ll ans = pathsum[level];
		ll sz = mp1[level+1].size();
		ll x2 = mp1[level+1][0].x,y2=mp1[level+1][0].y;
		ll x3 = mp1[level+1][sz-1].x,y3=mp1[level+1][sz-1].y ;
		if(end == 0)
		{
			ll x1 =  mp1[level][0].x,y1=mp1[level][0].y;
			ll dist1 = abs(x1-x2)+abs(y1-y2);
			ll dist2 = abs(x1-x3)+abs(y1-y3);
			return dp[level][end] = ans + min(dist1+solve(level+1,1),dist2+solve(level+1,0));	
		}
		else
		{
			ll sz1 = mp1[level].size();
			ll x1 =  mp1[level][sz1-1].x,y1=mp1[level][sz1-1].y;
			ll dist1 = abs(x1-x2)+abs(y1-y2);
			ll dist2 = abs(x1-x3)+abs(y1-y3);
			return dp[level][end] = ans + min(dist1+solve(level+1,1),dist2+solve(level+1,0));	
		}
	}
}

int main()
{
  sync;
  ll n;
  memset(dp,-1,sizeof(dp));
  cin >> n;
  for(ll i=0;i<n;i++)
  {
  	ll a,b;
  	cin >> a >> b;
  	mp[max(a,b)].pb(point(a,b));
  	//cerr << mp[max(a,b)].size() << endl;
  }
  //cout << mp[2].size() << endl;
  ll level = 0;
  for(auto it=mp.begin();it!=mp.end();it++)
  {
  	sort(mp[it->FI].begin(),mp[it->FI].end());
  	mp1[level] = mp[it->FI];
  	level++;
  }
  level = 0;
  for(auto it=mp1.begin();it!=mp1.end();it++)
  {
  	ll sum = 0;
  	//cerr << it->FI << endl;
  	vector<point> v1 = it->SE;
  	//cerr << v1[0].x << " " << v1[0].y << endl;
  	for(ll i=1;i<v1.size();i++)
  	{//cerr << v1[i].x << " " << v1[i].y << endl;
  		sum += abs(v1[i].x-v1[i-1].x)+abs(v1[i].y-v1[i-1].y);
  	}
    pathsum[level] = sum;
    //cout << level << " " << pathsum[level] << endl;
    level++;
  }
  cout <<  min(mp1[0][0].x+mp1[0][0].y+solve(0,1),mp1[0][mp1[0].size()-1].x+mp1[0][mp1[0].size()-1].y+solve(0,0)) << endl;
}
