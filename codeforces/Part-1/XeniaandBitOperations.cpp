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

vector <ll> v;
vector <ll> seg;
ll idx,val;
void update(ll node,ll start,ll end,bool op)
{
  if(start == end)
  {
    seg[node] = val;
    v[idx] = val;
  }
  else
  {
    ll mid = (start+end)/2;
    if(start<=idx && mid >=idx)
      update(2*node,start,mid,op==true ?  false :  true);
    else
      update(2*node+1,mid+1,end,op==true ?  false :  true);
    if(op == true)
      seg[node] = seg[2*node] ^ seg[2*node+1];
    else
      seg[node] = seg[2*node]|seg[2*node+1];  
  }
}

void build(ll node,ll start,ll end,bool op)
{
  if(start == end)
  {
    seg[node] = v[start];
  }
  else
  {
    ll mid = (start+end)/2;
    build(2*node,start,mid,op==true ?  false :  true);
    build(2*node+1,mid+1,end,op==true ? false :  true);
    if(op == true)
      seg[node] = seg[2*node] ^ seg[2*node+1];
    else
      seg[node] = seg[2*node]|seg[2*node+1];  
  }
}
int main()
{
  sync;
  ll n,m;
  cin >> n >> m;
  ll tot = pow(2,n);
  v.resize(tot+5);
  seg.resize(4*tot+20);
  for(ll i=1;i<=tot;i++)
  {
    cin >> v[i];
  }
  //cout << v[1] << v[2] << v[3] << v[4] << endl;
  if(n%2 == 0)
    build(1,1,tot,true);
  else
    build(1,1,tot,false);
  for(ll i=0;i<m;i++)
  {
    cin >> idx >> val;
    if(n%2 == 0)
        update(1,1,tot,true);
    else
        update(1,1,tot,false);
    cout << seg[1] << endl;
  }
}

