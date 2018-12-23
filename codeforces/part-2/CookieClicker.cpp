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

vector<pii> v1;
int solve(int choice,int c,int rate,vector<int> v)
{
	// cout << "hello" << endl;
	int ctime = 0;
	int cMoney = 0;
	int goalTime = ceil(c/(rate*1.0));
	for(int i=0;i<=choice;i++)
	{
		int addTime;
		if(cMoney >=v1[v[i]].FI )
		{
			cMoney = cMoney-v1[v[i]].FI;
			addTime = ceil((c-cMoney)/(rate+v1[v[i]].SE));
			rate = rate + v1[i].SE;
			if(ctime+addTime < goalTime)
				goalTime = ctime+addTime;
		}
		else
		{
			addTime = ceil((v1[v[i]].FI-cMoney)/(rate*1.0));
			//cout << addTime << endl;
			ctime = ctime+addTime;
			cMoney = cMoney + addTime*rate;
			//cout << cMoney << endl;
			cMoney = cMoney-v1[v[i]].FI;
			//cout << cMoney << " " << rate << " " << c-cMoney  << endl;
			addTime = ceil((c-cMoney)/((rate+v1[v[i]].SE)*1.0));
			//cout << addTime << endl;
			rate = rate + v1[v[i]].SE;
			//cout << ctime+addTime << endl;
			if(ctime+addTime < goalTime)
				goalTime = ctime+addTime;
			for(int j=i+1;j<=choice;j++)
			{
				while(cMoney >=v1[v[j]].FI )
				{
					cMoney = cMoney-v1[v[i]].FI;
			addTime = ceil((c-cMoney)/(rate+v1[v[i]].SE));
			rate = rate + v1[i].SE;
			if(ctime+addTime < goalTime)
				goalTime = ctime+addTime;
				}
				i=j;
			}
			
		}
	}
	return goalTime;
}
int main()
{
  sync;
  int n,c,s;
  cin >> n >> c >> s;
  for(int i=0;i<n;i++)
  {
  	int a,b;
  	cin >> a >> b;
  	v1.pb({a,b});
  }
  vector<int> v;
  for(int i=0;i<n;i++)
  	v.pb(i);
  int ans =INT_MAX;
  do
  {
  	//cout << "hi" << endl;
  	for(int i=1;i<n;i++)
  	{
  		ans = min(ans,solve(i,c,s,v));
  		//break;
  	}
  	//break;
  }while(next_permutation(v.begin(),v.end()));
  cout << ans << endl;
}
