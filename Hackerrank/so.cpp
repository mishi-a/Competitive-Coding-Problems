/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
vector <vector<ll> > vec(8005);
vector <ll> v;
map <ll,ll> mp;
ll tot[17000];
ll vis[17000];
vector<ll> s;
int main()
{
  sync;
  sync;
  ll n,a,b;
  cin >> n;
  ll q;
  cin >> q;
  for(ll i=0;i<n;i++)
  {
    cin >> a;
    v.pb(a);
    if(mp.find(a)!=mp.end())
    {
      vec[mp[a]].pb(i);
    }
    else
    {
      mp[a] = i;
      vec[i].pb(i);
    }
  }
  while(q--)
  {
   s.clear();
    cin >> a >> b;
            ll ans = 0;
    ll cnta=0,cntb=0;
    ll last =0;
    ll last1 =0;
    if(a==b)
    {
      cout << (n*(n+1))/2 << endl;
      continue;
    }
    ll va,vb;
    if(mp.find(a)!=mp.end())
      va = mp[a];
    else
      va = -1;
    if(mp.find(b)!=mp.end())
      vb = mp[b];
    else
      vb = -1;
    ll siza = (va == -1 ? 0 : vec[va].size());
    ll sizb = (vb == -1 ? 0 : vec[vb].size());
    ll i=0,j=0;
    vector <ll> temp;
    while(i<siza && j<sizb)
    {
      if(vec[va][i]<vec[vb][j])
      {
        temp.pb(vec[va][i]);
        i++;
      }
      else
      {
        temp.pb(vec[vb][j]);
        j++;
      }
    }
    while(i<siza)
    {
      temp.pb(vec[va][i]);
      i++;
    }
    while(j<sizb)
    {
        temp.pb(vec[vb][j]);
        j++;
    }
    for(ll i=0;i<temp.size();i++)
     {
        if(v[temp[i]]==a)
      	{
        	cnta++;
      	}
      	else if(v[temp[i]]== b)
        	cntb++;
        ll idx = cnta-cntb;
        if(idx < 0)
        	idx+=16005;
        ll idx1 = idx-1;
        if(last1<0) 
            last1+=16005;
        tot[last1]+=(temp[i]-last); 
        if(!vis[idx]) 
        {
           s.pb(idx);
           vis[idx] = 1;
        }
        tot[idx]++;
        last = temp[i]+1;
        last1 = idx;
     }
      ll idx = cnta-cntb;
      if(idx < 0)
        	idx+=16005;
      tot[idx]+=(n-last);
      if(!vis[idx])
        s.pb(idx);
      if(!vis[0])
        s.pb(0);
      tot[0]++;
      ll x;
      for(ll i=0;i<s.size();i++) 
      {
         x=tot[s[i]]-1;
         ans+=((x*1ll*(x+1))/2);
         tot[s[i]]=0;
         vis[s[i]]= 0;
      }
        cout<<ans<<endl;
  }
}

