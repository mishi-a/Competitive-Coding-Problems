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

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
int n;
string s;
int m,x,y;
int dp[200][200][200];
int hcf(int n1, int n2,int flag)
{
    if(flag == 0)
    {
      if(n1==0)
        return 0;
      else if(n2 == 0)
        return 0;
    }
    if (n2 != 0)
       return hcf(n2, n1%n2,1);
    else 
       return n1;
}
int cal(int end,int start)
{
  int len = 1;
  int tot = 0;
  for(int i=end;i>=start;i--)
  {
    tot = tot + (s[i]-'0')*len;
    len*=10;
  }
  return tot;
}
int solve(int idx,int gcd,int sep)
{
  int ans = 0; 
  //cout << idx <<" " <<  gcd << "  "<< sep<< " "<< endl;
  if(idx == n)
  {
    sep++;
    if(y-sep>=x)
      return gcd;
    else
      return 0;
  }
  if(idx==(n-1) && y-sep>=x)
    return hcf(gcd,cal(n-1,idx),0);
  else if(idx==(n-1) && y-sep<x)
    return 0;
  if(dp[idx][gcd][sep]!=-1)
    return dp[idx][gcd][sep];
  if(sep == 0 && n-idx>m)
  {
    return 0;
  }
  else if(sep == 0 && n-idx<=m)
  {
    return hcf(gcd,cal(n-1,idx),0);
  }
  else
  {
    
    if(y-sep>=x && n-idx<=m)
      ans = hcf(gcd,cal(n-1,idx),0);
    for(int i=idx;i<idx+m && i<n;i++)
    {
      int num = cal(i,idx);
      if(num == 0)
        continue;
      else
      {
        ans = max(ans,solve(i+1,hcf(gcd,num,0),sep-1));
      }
    }
  }
  return (dp[idx][gcd][sep] = ans);
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    cin >> s;
    cin >> m >> x >> y;
    int ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m&&i<n;i++)
    {
      int num = cal(i,0);
      if(num == 0)
        continue;
      else
      {
        ans = max(ans,solve(i+1,num,y-1));
      }
    }
    cout << ans << endl;
  }
}

