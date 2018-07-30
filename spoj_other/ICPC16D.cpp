#include <iostream>
#include <vector>

#define sync ios::syn_with_stdio(false)
#define endl '\n'
#define mod 1000000007

using namespace std;
const int size = 7.5e5 + 1;
vector <int> dp(size,0);
void solve()
{
  int n,x,res=0;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> x;
    dp[x]++;
  }
  /*for(int i=0;i<26;i++)
    cout << dp[i] << " ";
  cout << endl;*/
  for(int i=1;i<size;i++)
  {
    if(dp[i])
    {
      for(int j=i+i;j<size;j+=i)
      {
        if(dp[j])
        {
          dp[j] = dp[j]+dp[i];
        }
      }
    }
  }
  for(int i=1;i<size;i++)
  {
    res = (res%mod + dp[i]%mod)%mod;
  }
  cout << res << endl;
  fill(dp.begin(),dp.end(),0);
  
  
}
int main()
{
  int t;
  cin >> t;
  while(t--)
    solve();  
}
