#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <pii > v(6000,pii(-1,-1));
vector <int> arr(6000);
int dp[6000] ;
int idx[6000] = {0};
int find(int start,int end)
{
  if(dp[start]!=-1)
    return dp[start];
  if(start>end)
    return 0;
  int mux = 0;
  //cout << v[arr[start]].first << " " <<  v[arr[start]].second << endl;
  for(int i=start;i<=end;i++)
  {
    if(i!=v[arr[i]].second || v[arr[i]].first <start )
    {//cout << "hi" << endl;
      continue;
    }
    else
    {
      bool isvalid = true;
      int x = 0;
      set <int> s;
      int r = v[arr[i]].second;
      int l = v[arr[i]].first;
      for(int j=v[arr[i]].second;j>=start;j--)
      { 
        if(v[arr[j]].first <start || v[arr[j]].second > v[arr[i]].second)
        {
          break;
        }
        l = min(l,j=v[arr[j]].first);
        if(idx[arr[j]] == 0)
        {
          x = x^arr[j];
          idx[arr[j]] = 1;
        }
      }
        int ans = x  + find(i+1,end);
        //cout << "X " << x << " " << start << " " << end << endl;
        if(ans>mux)
          mux = ans;
        //cout << mux << endl;
     
    }
  }
  dp[start] = mux;
  return mux;
}
int main()
{
  sync;
  int n;
  cin >> n;
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)
  {
    cin >> arr[i];
    if(v[arr[i]].first == -1)
    {
      v[arr[i]].first = i;
      v[arr[i]].second = i;
    }
    else
    {
      v[arr[i]].second = i;
    }
  }
  
  int res = find(1,n);
  cout << res << endl;
  
}
