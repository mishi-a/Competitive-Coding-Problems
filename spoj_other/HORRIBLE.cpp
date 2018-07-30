#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <ll> seg(1000000);
vector <ll> lazy(1000000);

ll query(ll node,ll start,ll end,ll l,ll r)
{
  if(start > end)
    return 0;
  if(lazy[node]!=0)
  {
    seg[node]+=(end-start+1)*lazy[node];
    if(start!=end)
    {
      lazy[2*node] += lazy[node];
      lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(r<start || l>end )
     return 0;
  if(l<=start && r>=end)
     return seg[node];
  ll mid = (start+end)/2;
  return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}

void update(ll node,ll start,ll end,ll l,ll r,ll v)
{
  //cout << start << " " << end << endl;
  if(start > end)
    return;
  if(lazy[node]!=0)
  {
    seg[node] += (end-start+1)*lazy[node];
    if(start!=end)
    {
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node] = 0;
  }
  if(r<start || l > end)
    return;
  if(l<=start && r >=end)
  {
    seg[node] += (end-start+1)*v;
    if(start!=end)
    {
      lazy[2*node]+=v;
      lazy[2*node+1]+=v;
    }
    return;
  }
  ll mid = (start+end)/2;
  update(2*node,start,mid,l,r,v);
  update(2*node+1,mid+1,end,l,r,v);
  seg[node] = seg[2*node]+seg[2*node+1];
}

void build(ll node,ll start ,ll end)
{
  if(start > end)
    return;
  if(start == end)
  {
    seg[start] = 0;
    lazy[start] = 0;
    return;
  }
  ll mid = (start+end)/2;
  build(2*node,start,mid);
  build(2*node+1,mid+1,end);
  seg[node] = 0;
  lazy[node] = 0;
}

void print()
{
  for(int i=1;i<=15;i++)
    cout << seg[i] << " ";
  cout << endl;
}

void solve()
{
  ll n;
  cin >> n;
  //build(1,1,n);
  fill(seg.begin(),seg.end(),0);
  fill(lazy.begin(),lazy.end(),0);
  //print();
  ll c;
  cin >> c;
  for(ll i=0;i<c;i++)
  {
    ll a;
    cin >> a;
    if(a == 0)
    {
      ll p,q,v;
      cin >> p >> q >> v;
      update(1,1,n,p,q,v);
      //print();
    }
    else
    {
      ll p,q;
      cin >> p >> q;
      cout << query(1,1,n,p,q) << endl;
      //print();
    }    
  }
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}
