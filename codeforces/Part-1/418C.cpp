/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
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
char c;
int solve(int start,int tot,string s)
{
  int res;
  if(tot == 0)
  {
    int cnt =1;
    int mux = 0;
    for(int i=1;i<s.length();i++)
    {
      if(s[i] == s[i-1] && s[i] == c)
      {
        cnt++;
        mux = max(cnt,mux);
      }
      else 
      {
        cnt = 1;
      }
    }
    if(mux == 0)
    {
      for(int i=0;i<s.length();i++)
        if(s[i] == c)
          mux = 1;
    }
    dp[start][tot] = mux;
    return mux;
  }
  if(start > s.length())
    return 0;
  else
  {
    string p = s;
      p[start] = c;
    string q = s;
    if(start+tot == s.length())
    {
      res = solve(start+1,tot-1,p);
    } 
    else
    {
      res = max(solve(start+1,tot-1,p),solve(start+1,tot,q));
    }
  }
  return res;
}
int main()
{
  sync;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  
  for(int i=0;i<q;i++)
  {
    memset(dp,0,sizeof(dp));
    int a;
    cin >> a >> c;
    int res = solve(0,a,s);
    cout << res << endl;
    
  }
}

