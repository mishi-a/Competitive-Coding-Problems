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

string s;
bool p[5005][5005];
int dp[5005][5005];
int ans[5005] = {0};
int solve(int start,int end)
{
  int an = 0;
  if(start == end)
    return 1;
  if(dp[start][end]!=-1)
    return dp[start][end];
  else if(p[start][end] == true)
  {
    int mid;
    if((end-start+1)%2)
    {
        mid = (end-start+1)/2 ;
        an = 1 + solve(start,start+mid-1);
    }
    else
    {
       mid =  (end-start+1)/2;
       an = 1 + solve(start,start+mid-1);
    }
  }
  else
  {
    return 0;
  }
  ans[an]++;  
  return (dp[start][end]=an);
}

int main()
{
  sync;
  cin >> s;
  memset(p,0,sizeof(p));
  memset(dp,-1,sizeof(dp));
  for(int len = 1;len <=s.length();len++)
  {
    for(int j=0;j<s.length()-len+1;j++)
    {
      int i = j+len-1;
      if(len == 1)
      {
        p[j][i] = true;
      }
      else if(len == 2)
      {
        if(s[i] == s[j])
        {
          p[j][i] = true;
        }
        else
        {
          p[j][i] = false;
        }
      }
      else
      {
        if(p[j+1][i-1] == true && s[i] == s[j])
        {   p[j][i] = true;}
        else
          p[j][i] = false;
      }
    }
  }
  for(int i=0;i<s.length();i++)
  {
    for(int j=i;j<s.length();j++)
    {
      if(i==j)
        ans[1]++;
      else
         solve(i,j);
    }
    //cout << endl;
  }
  int sum = 0;
  for(int i=s.length();i>0;i--)
  {
    sum = sum+ans[i];
    ans[i] = sum;
  }
  for(int i=0;i<s.length();i++)
    cout << ans[i+1] << " ";
  cout << endl;
  
}

