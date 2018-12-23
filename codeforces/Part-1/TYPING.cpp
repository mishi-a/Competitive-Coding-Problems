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

map<string,int> mp;
map<char,int> mp1;
int get(string s)
{
	int ans = 2;
	int cHand = 0;
	if(mp1[s[0]]) cHand = 1;
	for(int i=1;i<s.size();i++)
	{
		if(mp1[s[i]]!=cHand)
		{
			ans+=2;
			cHand = mp1[s[i]];
		}
		else
			ans+=4;
	}
	return ans;
}

int solve()
{
	int n;
	string s;
	cin >> n;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		int val = get(s);
		if(mp[s])
		{
			ans += val/2;
		}
		else
			ans+=val;
		mp[s] = 1;
		//cerr << val << " " << ans << endl;
	}
	return ans;
}

int main()
{
  sync;
  int t;
  cin >> t;
  mp1['d'] = mp1['f'] = 1;
  while(t--)
  {
  	cout << solve() << endl;
  	mp.clear();
  }
  
}
