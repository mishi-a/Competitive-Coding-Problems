#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

vector < ll > dp(6000,0);
int main()
{
  sync;
  while(1)
  {
    string a;
    cin >> a;
    if(a[0]-'0' == 0)
      break;
    dp[0] = 1;
    int len = a.length();
    for(int i=1;i<len;i++)
    {
      if(a[i]-'0' > 0 )
      {
        dp[i] =  dp[i-1];
      }
      if((a[i-1]-'0')*10+(a[i]-'0')>9 && (a[i-1]-'0')*10+(a[i]-'0') < 27 )
      {
        if(i-2 >= 0)
          dp[i] += dp[i-2];
        else
          dp[i] +=dp[i-1];
      }
    }
    cout << dp[len-1] << endl;
    fill(dp.begin(),dp.begin()+len+10,0); 
  } 
}
