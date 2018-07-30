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
vector <int> ans;
int n;

int solve(int num)
{
	int val = num;
	int tot = 0;
	while(num!=0)
	{
		tot+=(num%10);
		num/=10;
	}
	//cout << val << " " << tot << endl;
	if(tot+val == n)
	{
		ans.pb(val);
		return 1;
	}
	else
		return 0;
}
int main()
{
  sync;
  cin >> n;
  int cnt = 0;
  for(int i=n;i>=0&&i>n-100;i--)
  {
    cnt+=solve(i);
  }
  cout << cnt << endl;
  for(int i=ans.size()-1;i>=0;i--)
  	cout << ans[i] << endl;
}
