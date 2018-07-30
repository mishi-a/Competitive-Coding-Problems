/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <pii > v;
vector <int> v1;
int dp[110][510];
int solve(int ind,int b)
{
   if(b <= 0)
     return 0;
   if(dp[ind][b]!=0)
      return dp[ind][b];
   if(v.size()-1-ind == 0)
   {
     if(b-v[ind].first >=0)
       dp[ind][b] = v[ind].second;
     else
       dp[ind][b] = 0;
     return dp[ind][b];
   }
   else
   {
     if(b-v[ind].first >=0)
       dp[ind][b] =  max(v[ind].second+solve(ind+1,b-v[ind].first),solve(ind+1,b));
     else
       dp[ind][b] =  solve(ind+1,b);
   }
   return dp[ind][b];
}

bool acompare(pii a,pii b)
{
   if(a.second > b.second)
      return true;
   else if(a.second == b.second && a.first < b.first)
      return true;
   else
      return false;
}

int main()
{
  sync;
  while(1)
  {
    int n,p;
    cin >> n >> p;
    if(n==0 && p==0)
      break;
    for(int i =0;i<p;i++)
    {
      int a,b;
      cin >> a >> b;
      v.pb({a,b});
    }
    sort(v.begin(),v.end(),acompare);
    memset(dp,0,sizeof(dp));
    int res = solve(0,n);
    /*for(int i=0;i<p;i++)
    {
      for(int j=0;j<=n;j++)
        cout << dp[i][j] << " ";
      cout << endl;
    }*/
    //cout << dp[2][n-v[1].first] << " " << dp[1][n]  << endl;
    int min = n;
    for(int i=0;i<n;i++)
    { 
      //cout << "hi" << " " << i << " " << v[i].second+dp[i+1][n-v[i].first] << " " <<  dp[i][n] << endl;
      if(solve(0,i) == res)
      {
         min = i;
         break;
      }     
    }
    
    cout << min << " " << res << endl;
    v.clear();
    v1.clear();
       
  }
}

