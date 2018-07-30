/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
#define mod 1000000007
using namespace std;
vector <ll> A;
vector <ll> B;
vector <ll> C;
vector <ll> v;
vector <ll> v1;

void solve()
{
  ll p,q,r,x;
  cin >> p >> q >> r;
  for(ll i=0;i<p;i++)
  { 
    cin >> x;
    A.pb(x);
  }
  for(ll i=0;i<q;i++)
  {
    cin >> x;
    B.pb(x);
  }
  for(ll i=0;i<r;i++)
  {
    cin >> x;
    C.pb(x);
  }
  //cout << v1[1]<<endl;
  sort(A.begin(),A.end());
  for(ll j = 0;j<A.size();j++)
  {
    j == 0 ? v.pb(A[j]%mod) : v.pb((v[j-1]%mod+A[j]%mod)%mod);
  }
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  for(ll j = 0;j<C.size();j++)
  {
    j == 0 ? v1.pb(C[j]%mod) : v1.pb((v1[j-1]%mod+C[j]%mod)%mod);
  }
  ll cunta,cuntb;
  ll res = 0;
  vector <ll> :: iterator itr1,itr2;
  for(ll i=0;i<B.size();i++)
  {
    if(A[0] > B[i] ||  C[0]> B[i])
       continue;
    itr1 = upper_bound(A.begin(),A.end(),B[i]);
    if(itr1!=A.end())
    {
      while(itr1!=A.begin()&&*itr1 > B[i])
        itr1--;
    }
    itr1 == A.end() ? cunta = (itr1-A.begin()) : cunta = itr1-A.begin()+1;
    itr2 = upper_bound(C.begin(),C.end(),B[i]);
    if(itr2!=C.end())
    {
      while(itr2!=C.begin() && *itr2 > B[i])
        itr2--;
    } 
    itr2 == C.end() ? cuntb = (itr2-C.begin()) : cuntb = itr2-C.begin()+1;
    res = (res%mod + (((cunta*cuntb)%mod)*((B[i]*B[i])%mod))%mod)%mod;
    res = (res%mod + ((((cunta)*(v1[cuntb-1]))%mod)*(B[i]%mod))%mod)%mod;
    res = (res%mod + ((((cuntb)*(v[cunta-1]))%mod)*(B[i]%mod))%mod)%mod;
    res = (res%mod  +  (((v[cunta-1]%mod)*(v1[cuntb-1]%mod)))%mod)%mod;
    /*cout << (cunta)*(cuntb)*(B[i])*(B[i]) << endl;
    cout << (cunta)*(v1[cuntb-1])*(B[i]) << endl;
    cout << (cuntb)*(v[cunta-1])*(B[i]) << endl;
    cout << v[cunta-1]*v1[cuntb-1] << endl;*/
    
  }
  cout << res%mod << endl;
  
}

void init()
{
  A.clear();
  B.clear();
  C.clear();
  v.clear();
  v1.clear();
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    init();
  }
}

