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
vector<int > arr[26];
int tot; string s;
int dp[100005];
int solve(int start)
{
  if(start == tot)
    return 0;
  if(dp[start]!=-1)
    return dp[start];
  else
  {
    int ans2 = INT_MAX; 
    int ans1 = fabs(s[start+1]-s[start])+solve(start+1);
    if(arr[s[start]-'a'].size() > 0)
    {
      if(upper_bound(arr[s[start]-'a'].begin(),arr[s[start]-'a'].end(),start)!=arr[s[start]-'a'].end())
      {
         int idx = upper_bound(arr[s[start]-'a'].begin(),arr[s[start]-'a'].end(),start) - arr[s[start]-'a'].begin();
         ans2 = solve(arr[s[start]-'a'][idx]); 
      }
    }
    return (dp[start] = min(ans1,ans2));
  }
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
   
    cin >> s;
    tot = s.length()-1;
    for(int i=0;i<26;i++)
      arr[i].clear();
    for(int i=0;i<s.length();i++)
    {
      arr[s[i]-'a'].pb(i);
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(0);  
    cout << ans << endl; 
  }
}

