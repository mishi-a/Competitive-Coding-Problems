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
long long n,madison;
long long height[100005],price[100005];
int nextGreater[100005];

stack<int> s;
long long dp[100005];
long long solve(long long idx)
{
    if(dp[idx]!=-1)
        return dp[idx];
    if(idx==n-1)
    {
        return 1;
    }
    else
    {
        long long ans = 1e18;
        bool k =false;
        for(int i=idx+1;i<n;i++)
        {
           if(i!=nextGreater[i]&&price[i]<0) 
           {
           	 ans = min(ans,i-idx+abs(height[i]-height[idx])+price[i]+solve(i));
           }
           if(i==nextGreater[idx])
           {
           	 ans = min(ans,i-idx+abs(height[i]-height[idx])+price[i]+solve(i));
           	  k=true;
             break;
           }
           
        }
        if(k==false)
            ans = min(ans,n-idx);
        return (dp[idx]=ans);
    }
    return 0;
}

int main()
{
  sync;
  cin >> n;
  cin >> madison;
      memset(dp,-1,sizeof(dp));

  height[0]=madison;
  for(long long i=1;i<n;i++)
      cin >> height[i];
  for(long long i=1;i<n;i++)
      cin >> price[i];
  s.push(0);
  for(int i=1;i<n;i++)
  {
  	while(!s.empty()&&height[i]>height[s.top()])
  	{
  		nextGreater[s.top()]=i;
  		s.pop();
  	}
  	s.push(i);
  }
  while(!s.empty())
  {
  	nextGreater[s.top()]=-1;
  	s.pop();
  }
    cout << solve(0) << endl;
    return 0;
}
