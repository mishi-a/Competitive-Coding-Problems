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

ll arr[100005];
vector <ll> v;
vector <pair<pair<ll,ll>,ll>> que;
ll tree[400050];
ll query(ll node, ll start, ll end, ll l, ll r)
{
    if(r < start or end < l or start > end)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1, p2);
}
void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = arr[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = max(tree[2*node] , tree[2*node+1]);
    }
}
int main()
{
  sync;
  ll n,q;
  cin >> n >> q;
  for(ll i=0;i<q;i++)
  {
    ll l,r,x;
    que.pb({{l,r},x});
    cin >> l >> r >> x;
    arr[l]+=x;
    arr[r+1]-=x;
  }
  ll mux = INT_MIN;
  for(ll i=1;i<=n;i++)
  {
    arr[i]+=arr[i-1];
    mux = max(mux,arr[i]);
  }
  build(1,1,n);
  for(ll i=1;i<=n;i++)
  { 
    if(arr[i]==mux)
      v.pb(i);
  }
  ll mun = mux;
  for(ll i=0;i<que.size();i++)
  {
    ll l = que[i].FI.FI;
    ll r = que[i].FI.SE;
    ll x = que[i].SE;
    if(l<=v[0] && r>=v[v.size()-1])
    {
       ll leftmax = query(1,1,n,1,l-1);
       ll rightmax = query(1,1,n,r+1,n);
       ll mid = mux-x;
       ll res = max(leftmax,max(rightmax,mid));
       if(res<mun)
       {
         mun = res;
       }
    }
  }
  cout << mun << endl;
  
}

