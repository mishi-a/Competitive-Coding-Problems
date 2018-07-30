#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <pair<ll,ll> > v;
vector <pair<ll,ll> > v1;

void calc()
{
  ll x;
}

void solve()
{
  ll n,k,m;
  cin >> n >> k >> m;
  ll ki = (n-k)/2+1;
  ll kf = ki+k;
  for(int i=0;i<m;i++)
  {
    ll hx,hy,tx,ty;
    cin >> hx >> hy >> tx >> ty;
    if(hx==tx&&(hx<ki||hx>=ki+k))
    {
        if(hy<ty )
        v.pb(make_pair(hy,ty));
        else
        v.pb(make_pair(ty,hy));
    }
    else if(hx==tx) 
        v1.pb(make_pair(hx,hx));
    if(hy==ty&&(hy<ki||hy>=ki+k)) 
    {   
        if(hx<tx)
        v1.pb(make_pair(hx,tx));
        else
        v1.pb(make_pair(tx,hx));
    }
    else if(hy==ty) 
        v.pb(make_pair(hy,hy));
  }
  sort(v.begin(),v.end());
  sort(v1.begin(),v1.end());
  /*for(int i=0;i<v.size();i++)
  {
    cout << v[i].first << " " << v[i].second ;
  }
  cout << endl;
  for(int i=0;i<v1.size();i++)
  {
    cout << v1[i].first << " " << v1[i].second ;
  }
  cout << endl;
  */
  ll cunt = 0;
  ll low =0 ;
  ll high = 0;
  for(int i=0;i<v.size();)
  {
    ll cl = v[i].first;
    ll cr = v[i].second;
    if(cr>high && cr >= ki )
    {
      if(cl <=ki)
      {
        low = cl;
        high = cr;
        i++;
        cunt = 1;
      }
      else
      {
        ll nhigh = 0;
        while(i<v.size() && v[i].first <= high+1)
        {
          if(v[i].second > nhigh)
            nhigh = v[i].second;
          i++;
        }
        if(nhigh!=0)
        {
          high = nhigh;
          cunt++;
        }
        else
        {
          i++;
        }
      }
    
    }
    else
      i++;
    if(high >= kf)
      break;
  }
  ll res = cunt;
  cunt = 0;
  ll lowy = 0;
  ll highy = 0;
   for(int i=0;i<v1.size();)
  {
    ll cl = v1[i].first;
    ll cr = v1[i].second;
    if(cr >= ki )
    {
      if(cl <=ki)
      {
        lowy = cl;
        highy = cr;
        i++;
        cunt = 1;
      }
      else
      {
        ll nhigh = 0;
        while(i<v1.size() && v1[i].first <= highy+1)
        {
          if(v1[i].second > nhigh)
            nhigh = v1[i].second;
          i++;
        }
        if(nhigh!=0)
        {
          highy = nhigh;
          cunt++;
        }
        else
        {
          i++;
        }
      }
    
    }
    else
      i++;
    if(highy >= kf)
      break;
  }
  if(low <=ki && high >= ki+k-1&&lowy<=ki && highy >= ki+k-1)
    cout << res+cunt << endl;
  else
    cout << "-1" << endl;
  calc();
  v.clear();
  v1.clear();
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
} 
