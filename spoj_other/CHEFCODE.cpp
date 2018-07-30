#include<iostream>
#include<vector>        
#include <algorithm> 
#include <iterator>

#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long int

using namespace std;
vector <ll> v;
vector <ll> p;
ll cout1 = 0;
ll k;
void solve(ll l,ll r,ll product=1)
{
   //cout << l << "  " << r << " " << product << endl;
   if(product > k || product < 0 )
     return;
   if(l>r)
   {
      
     cout1++;return;

   }
   if(p[r] > 0)
   {
     if(l>=1 && product*(p[r]/p[l-1]) <= k ){
       cout1 = cout1+pow(2,r-l+1);
       return;
       }
   
   }
   
   solve(l+1, r, product*v[l]);
 
    // Subset excluding arr[l]
   solve(l+1, r, product);
   
}
 
int main()
{
  sync;
  ll n;
  ll prt = -1;
  int flag = 0;
  cin >> n;
  cin >> k;
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    if(a<=k){
    if(flag == 0){
      prt = 1;
      flag = 1;
    }
      prt = prt*a;
      v.push_back(a);
    } 
  }
  if(prt<=k && prt > 0)
  {
    cout << pow(2,n)-1 << endl;
    return 0;
  }
  n = (ll)v.size();
  sort(v.begin(),v.end(),greater <ll>());
   if(n>0)
  {
          p.push_back(v[0]);
          for(ll i=1;i<n;i++)
          {
            p.push_back(v[i]*p[i-1]);         
          }
  }
  solve(0,n-1);
  cout << cout1-1 << endl;
}
