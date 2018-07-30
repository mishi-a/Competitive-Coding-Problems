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
string s;
int dp[5005];
void precompute(int idx)
{
	if(idx == s.length())
		return;
	if(s[idx] = ')')
	{
		dp[idx] = -1;
		precompute(idx+1);
	}
	else
	{
		stack<int> s1;
		s1.push(s[idx]);
		for(int i=idx+1;i< s.length();i++)
		{
           
		}
		precompute(idx+1);
	}
}

int main()
{
  sync;
  cin >> s;
  precompute(0);
}
