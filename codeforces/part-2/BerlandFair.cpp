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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
ll arr[MAX+5],sum[MAX+5];
int main()
{
  sync;
  ll n,t;
  cin >> n >> t;
  for(int i=0;i<n;i++)
  	cin >> arr[i],sum[i]=arr[i];
  for(int i=1;i<n;i++) sum[i]+=sum[i-1];
  ll ans = (t/sum[n-1])*n;
  ll rem = t%sum[n-1];
  while(rem)
  {
    int flag = 0;ll tot=0,cnt=0;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
      if(rem-arr[i]>=0)
      {
        ans++,cnt++;
        tot+=arr[i];
        v.pb(tot);
        flag = 1;
        rem-=arr[i];
      }
    }
    if(flag == 0)
      break;
    ans += (rem/tot)*cnt;
    rem = rem%tot;
  }
  cout << ans << endl;
}
