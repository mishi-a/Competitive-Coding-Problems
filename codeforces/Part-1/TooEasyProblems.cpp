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
vector<pair<pii,int>> v;
int n,t,a,b;

bool check(int val)
{
  int cnt=0,ttime=0;
  if(val==0)
  	return true;
  for(int i=0;i<v.size();i++)
  {
    int a=v[i].FI.FI,b=v[i].FI.SE;
    if(val<=b)
    {
    	ttime+=a;
    	if(ttime>t)
    		return false;
    	cnt++;
    	if(cnt==val)
    		return true;
    }
  }
  return false; 
}
int check1(int val)
{
  int cnt=0,ttime=0;
  for(int i=0;i<v.size();i++)
  {
    int a=v[i].FI.FI,b=v[i].FI.SE;
    if(val<=b)
    {
    	ttime+=a;
    	if(ttime>t)
    		return 0;
    	cnt++;
    	cout << v[i].SE << " ";
    	if(cnt==val)
    		return 0;
    }
  }
  return 0; 
}
int solve()
{
	int low=0,high=n;
	int ans=0;
	while(low<=high)
	{
	  //cout << low << " " << high << endl;
      int mid = (low+high)/2;
      if(check(mid))
      	low = mid+1,ans=max(ans,mid);
      else
      {
      	high = mid-1;
      }
	}
	return ans;
}
int main()
{
  sync;
  cin >> n >> t;
  for(int i=0;i<n;i++)
  {
     cin >> a >> b;
     v.pb({{b,a},i+1});
  }
  sort(v.begin(),v.end());
  int val = solve();
  cout << val << endl;
  cout << val << endl;
  check1(val);
}
