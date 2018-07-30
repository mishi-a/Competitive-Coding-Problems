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
using namespace std;

struct node
{
  int lsum;
  int rsum;
  int sum;
  int bsum;
};

node seg[200009];
vector <int> v;

void update(int node,int start,int end,int idx,int val)
{
  if(start == end)
  {
    seg[node].lsum = seg[node].rsum = seg[node].sum = seg[node].bsum = val;
    return;
  }
  int mid = (start+end)/2;
  if(start <=idx && idx <= mid)
    update(2*node,start,mid,idx,val);
  else
    update(2*node+1,mid+1,end,idx,val);
  seg[node].sum  =  seg[2*node].sum + seg[2*node+1].sum;
  seg[node].lsum = max(seg[2*node].lsum,seg[2*node].sum + seg[2*node+1].lsum);
  seg[node].rsum = max(seg[2*node+1].rsum,seg[2*node].rsum+seg[2*node+1].sum);
  seg[node].bsum = max(max(seg[2*node].bsum,seg[2*node+1].bsum),seg[2*node].rsum + seg[2*node+1].lsum);
}

node query(int node,int start,int end,int l,int r)
{
  if(r < start || l > end)
  {
    struct node p;
    p.sum = p.lsum = p.rsum = p.bsum = -150007;
    return p;
  }
  else if(l <= start && r >= end)
  {
    return seg[node];
  }
  else
  {
    int mid = (start+end)/2;
    struct node x = query(2*node,start,mid,l,r);
    struct node y = query(2*node+1,mid+1,end,l,r);
    struct node z;
    z.sum = x.sum + y.sum;
    z.lsum = max(x.lsum,x.sum+y.lsum);
    z.rsum = max(y.rsum,x.rsum+y.sum);
    z.bsum = max(max(x.bsum,y.bsum),x.rsum+y.lsum);
    return z; 
  }
}

void build(int node,int start,int end)
{
  if(start == end)
  {
    seg[node].lsum = seg[node].rsum = seg[node].sum = seg[node].bsum = v[start];
    return;
  }
  else
  {
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    
    seg[node].sum  =  seg[2*node].sum + seg[2*node+1].sum;
    seg[node].lsum = max(seg[2*node].lsum,seg[2*node].sum + seg[2*node+1].lsum);
    seg[node].rsum = max(seg[2*node+1].rsum,seg[2*node].rsum+seg[2*node+1].sum);
    seg[node].bsum = max(max(seg[2*node].bsum,seg[2*node+1].bsum),seg[2*node].rsum + seg[2*node+1].lsum);
  }
}

int main()
{
  sync;
  int n;
  cin >> n;
  v.pb(-1);
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  build(1,1,n);
  /*for(int i=1;i<=5;i++)
  {
    cout << seg[i].sum << " " << seg[i].lsum << " " << seg[i].rsum << " " << seg[i].bsum << endl;
  }
  cout << endl;*/
  int q;
  cin >> q;
  for(int i=0;i<q;i++)
  {
    int a;
    cin >> a;
    if(a == 0)
    {
      int idx,val;
      cin >> idx >> val;
      update(1,1,n,idx,val);
    }
    else
    {
      int l,r;
      cin >> l >> r;
      struct node ans = query(1,1,n,l,r);
      cout << ans.bsum << endl;
    }

  }
}

