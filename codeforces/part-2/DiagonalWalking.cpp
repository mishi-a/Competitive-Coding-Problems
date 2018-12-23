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

const int MAX = 4e5;
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

ll p[20];
using namespace std;

ll check1(int x,ll n,int cnt){
  if(cnt<1)return 0;
  cnt--;
  ll ans=0,val;
  for(int i=0;i<=cnt;i++){
    val=x*p[i];
    if(val<=n){
      //cerr<<val<<" ";
      ans++;
    }
  }
  //cerr<<endl;
  return ans;
}
ll check2(int x,int y,ll n,int cnt){
  if(cnt<2)return 0;
  cnt-=2;
  ll ans=0,val;
  for(int i=0;i<=cnt;i++){
      for(int k=0;k<=cnt-i;k++){
        val=x*p[i+k+1]+y*p[k];
        if(val<=n){
          //cerr<<val<<" ";
          ans++;
        }
      }
  }//cerr<<endl;
  return ans;
}
ll check3(int x,int y,int z,ll n,int cnt){
  if(cnt<3)return 0;
  cnt-=3;
  ll ans=0,val;
  for(int i=0;i<=cnt;i++){
    for(int j=0;j<=cnt-i;j++){
      for(int k=0;k<=cnt-i-j;k++){
        val=x*p[i+j+k+2]+y*p[j+k+1]+z*p[k];
        if(val<=n){
          //cerr<<val<<" ";
          ans++;
        }
      }
    }
  }
  //cerr<<endl;
  return ans;
}
ll solve(ll n){
  int cnt=0;
  ll x=n;
  while(x){
    x/=10;
    cnt++;
  }
  ll res=0
;  for(int i=1;i<=9;i++){
    res+=check1(i,n,cnt);
    for(int j=1;j<=9;j++){
      res+=check2(i,j,n,cnt);
      for(int k=1;k<=9;k++){
        res+=check3(i,j,k,n,cnt);
      }
    }
  }
  return res;
}
int main()
{
  sync;
  int t;
  p[0]=1;
  for(int i=1;i<=18;i++)
    p[i]=p[i-1]*10;
  cin>>t;
  ll l,r;//cerr<<solve(1000);
  while(t--){
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<"\n";
  }
}
