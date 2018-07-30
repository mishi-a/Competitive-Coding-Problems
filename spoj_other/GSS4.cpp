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

ll seg[400005];
bool marker[100005] = {0};
int mover[100005] = {0};
vector <ll> v;

ll query(int node,int start,int end,int l,int r)
{
   if(r < start || l > end)
     return 0;
   else if(l<=start && r >= end)
     return seg[node];
   else
   {
     int mid = (start + end)/2;
     return query(2*node,start,mid,l,r) + query(2*node+1,mid+1,end,l,r);
   }
   
}


void update(int node,int start,int end,int idx)
{
  if(start == end)
  {
    seg[node] = floor(sqrt(seg[node]));
    if(seg[node] == 1)
    {
      marker[start] = 1;
      mover[start] = 1;
      //cout << start << endl;
      start--;
      while(mover[start]!=0&&start>=1)
      {
        mover[start] = mover[start+1]+1;
        //cout << start <<  " " << mover[start] << endl;
        start--;
      }
    }
    return;
  }
  else
  {
    int mid = (start+end)/2;
    if(idx >= start && idx <= mid)
       update(2*node,start,mid,idx);
    else
       update(2*node+1,mid+1,end,idx);
    seg[node] = seg[2*node] + seg[2*node+1];   
  }
}

void build(int node,int start,int end)
{
  if(start == end)
  {
    seg[node] = v[start];
    return;
  }
  else
  {
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    seg[node] = seg[2*node] + seg[2*node+1];
  }
}

int main()
{
  sync;
  int n,cnt = 1;
  while(cin >> n)
  { 
    v.clear();
    memset(marker,0,sizeof(marker));
    memset(mover,0,sizeof(mover));
    v.pb(-1);
    for(int i=0;i<n;i++)
    {
      ll a;
      cin >> a;
      v.pb(a);
      if(a == 1)
        marker[i+1] = 1;
    }
    build(1,1,n);
    
    int m;
    cout << "Case #" << cnt <<":" << endl;
    cnt++;
    cin >> m;
    for(int i=0;i<m;i++)
    {
      int x;
      cin >> x;
      if(x==0)
      {
        int l,r;
        cin >> l >> r;
        if(l>r)
          swap(l,r);
        for(int j=l;j<=r;)
        {
          if(marker[j] == 1)
          {
            //cout << j << " " << mover[j] << endl;
            j = j+mover[j];

          }
          else
          {
            update(1,1,n,j);
            j++;
          }
        }
      }
      else
      { 
         int l,r;
         cin >> l >> r;
         if(l>r)
          swap(l,r);
         ll res = query(1,1,n,l,r);
         cout << res << endl;
    
      }
    }
  } 
}

