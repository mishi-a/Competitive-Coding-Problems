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
#define INF 1000000000
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
int k;
string s1,s2;
int dp[2005][2005];
int solve(int start1,int start2)
{
  int ans;
  if(dp[start1][start2]!=0)
    return dp[start1][start2];
  if(start1 == s1.length() || start2 == s2.length())
  {
    if(start1 == s1.length() &&  start2 == s2.length())
    {
      return 0; 
    }
    else if((start1 == s1.length()))
      return (k*(s2.length()-start2));
    else if((start2 == s2.length()))
      return (k*(s1.length()-start1));
    else
      return INF;
  }
  else
  {
    int ans1 = min(k + solve(start1,start2+1),k + solve(start1+1,start2));
    int ans2 = INF;
    if(start1 < s1.length() && start2 < s2.length())
        ans2 = fabs(s1[start1]-s2[start2]) + solve(start1+1,start2+1);
    ans = min(ans1,ans2);
  }
  dp[start1][start2] = ans;
  return ans;
}
 
int main()
{
  sync;
  cin >> s1 >> s2;
  cin >> k;
  memset(dp,0,sizeof(dp));
  int res = solve(0,0);
  cout << res << endl;
}

