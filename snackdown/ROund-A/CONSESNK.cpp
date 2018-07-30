#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <ll> v;
vector <ll> v1;
vector <ll> v2;
vector <ll> v3;
void solve()
{
  ll n,l,a,b;
  cin >> n >> l >> a >> b;
  for(int i=0;i<n;i++)
  {
    ll x;
    cin >> x;
    if(x<a)
     v.pb(x);
    else if(x+l > b)
     v1.pb(x);
    else
     v2.pb(x);
  }
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  ll res = 0;
  for(int i=0;i<v.size();i++)
  {
    res = res + (a-v[i]);
    a = a+l;
  }
  ll lres = res;
  ll slres = v.size();
  for(int i=0;i<v1.size();i++)
  {
    res = res+fabs(b-(v1[i]+l));
    b = b-l;
  }
  ll rres = res - lres;
  ll sres = v1.size();
  for(int i=0;i<v2.size();i++)
  {
    if(v2[i] < a)
    {
      lres = lres + a-v2[i];
      res = res + a-v2[i];
      slres++;
      v2[i] = -1;
      a = a+l;
    }
    else if(v2[i] > b)
    {
      res = res + fabs(v2[i]+l-b);
      rres = rres + fabs(v2[i]+l-b);
      sres++;
      b = b-l;
      v2[i] = -1;
    }
  }
  for(int i=0;i<v2.size();i++)
  {
    if(v2[i]!=-1)
      v3.pb(v2[i]);
  }
  int flag = 0;
  if(!v3.empty())
  {    //cout << lres << " " << rres << " " << a << " " <<b  << endl;
       flag = 1;
       sort(v3.begin(),v3.end());
       ll ldisp = 0;
       ll rdisp = 0;
       ll msize = v3.size();
       ll g = v3[0];
       ll h = v3[v3.size()-1]+l;
       for(int j=0;j<v3.size();j++)
       {
          ldisp = ldisp+(fabs(g-v3[j]));
          g = g+l;
       }
       for(int j=v3.size()-1;j>=0;j--)
       {
          rdisp = rdisp+(fabs(h-(v3[j]+l)));
          h = h-l;
       }
       //cout << ldisp << " " << rdisp << endl;
     ll min1 = lres+slres*(v3[0]-a) + rres+sres*(fabs(v3[0]+msize*l-b))+ldisp;
     ll min2 = lres+slres*(v3[v3.size()-1]-msize*l-a) + rres+sres*(fabs(v3[v3.size()-1]-b))+rdisp;
     ll min3 = lres+ldisp+rres+msize*(fabs(v3[0]-a))+sres*(b-(a+msize*l));
     ll min4 = lres+rdisp+rres+msize*(fabs(b-v3[v3.size()-1]))+slres*(b-msize*l-a);
     //cout << min1 << " " << min2 << " " << min3 << " " << min4 << endl;
     vector <ll> ans;
     ans.pb(min1);ans.pb(min2);ans.pb(min3);ans.pb(min4);
     cout << *min_element(ans.begin(),ans.end()) << endl;ans.clear();
  }
  if( flag == 0)
  {
        if(a!=b)
        {
          ll min1 = lres + rres+ sres*(b-a);
          ll min2 = slres*(b-a)+lres+rres;
          ll res = min(min1,min2);
          cout << res << endl;
        }
        else
         cout << res << endl;
  }
  v.clear();
  v1.clear();
  v2.clear();
  v3.clear();
  
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}
