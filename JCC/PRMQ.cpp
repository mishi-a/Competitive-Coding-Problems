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
vector < pair<vector<int>, vector<int> > > seg(400007);
int p[1000007] = {0};
vector <vector <int> > v(1000007);
vector <vector <int> > csum(400007);
vector <int> v1;
int l1,r1,x1,y2;
void pre()
{
  for(int i=2;i<=1000002;i++)
  {
    if(p[i] == 0)
    {
      v[i].pb(i);
      for(int j=i*2;j<=1000002;j+=i)
      {
        v[j].pb(i);
        p[j] = 1;
      }
    }
  }
}
void merge(int l,int r,int p)
{
  int n1 = seg[l].first.size();
  int n2 = seg[r].first.size();
  int t1 = n1;
  int t2 = n2;
  int i=0,j=0,k = 0;
  while(n1 > 0 && n2 > 0)
  {
    if(seg[l].first[i] < seg[r].first[j] )
    {
      seg[p].first.pb(seg[l].first[i]);
      seg[p].second.pb(seg[l].second[i]);
      if(k == 0)
        csum[p].pb(seg[l].second[i]);
      else
        csum[p].pb(seg[l].second[i]+ csum[p][k-1]);
      i++;
      k++;
      n1--;
    }
    else if(seg[l].first[i] > seg[r].first[j])
    {
      seg[p].first.pb(seg[r].first[j]);
      seg[p].second.pb(seg[r].second[j]);
      if(k == 0)
        csum[p].pb(seg[r].second[j]);
      else
        csum[p].pb(seg[r].second[j]+ csum[p][k-1]);
      j++;
      k++;
      n2--;
    }
    else
    {
      seg[p].first.pb(seg[r].first[j]);
      seg[p].second.pb(seg[r].second[j]+ seg[l].second[i]);
      if(k == 0)
        csum[p].pb(seg[r].second[j]+ seg[l].second[i]);
      else
        csum[p].pb(seg[r].second[j]+ seg[l].second[i]+ csum[p][k-1]);
      j++;
      i++;
      k++;
      n2--;
      n1--;
    }
  }
  while(i<t1)
  {
    seg[p].first.pb(seg[l].first[i]);
    seg[p].second.pb(seg[l].second[i]);
    if(k == 0)
        csum[p].pb(seg[l].second[i]);
      else
        csum[p].pb(seg[l].second[i]+ csum[p][k-1]);
    k++;
    i++;
  }
  while(j<t2)
  {
    seg[p].first.pb(seg[r].first[j]);
    seg[p].second.pb(seg[r].second[j]);
    if(k == 0)
        csum[p].pb(seg[r].second[j]);
      else
        csum[p].pb(seg[r].second[j]+ csum[p][k-1]);
    k++;
    j++;
  }
  
}
void build(int node,int start,int end)
{
  if(start == end)
  {
     seg[node].first = v[v1[start]];
     for(int i=0;i<v[v1[start]].size();i++)
     {
       int tot = 0;
       int x1 = v1[start];
       while(x1!=0)
       {
         if(x1%seg[node].first[i] == 0)
         {
           tot++;
           x1 = x1/seg[node].first[i];
         }
         else
           break;
       }
       seg[node].second.pb(tot);
       i == 0 ? csum[node].pb(tot) : csum[node].pb(tot+csum[node][i-1]);
     }
     
  }
  else
  {
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    merge(2*node,2*node+1,node);
  }
}
int query(int node,int start,int end)
{
  if(r1<start || l1 > end)
    return 0;
  if(start>=l1 && end <= r1)
  {
    vector <int> :: iterator itr,itr1;
    itr = lower_bound(seg[node].first.begin(),seg[node].first.end(),x1);
    if(itr == seg[node].first.end())
    {
      return 0;
    } 
    if(*itr > y2)
      return 0;
    int index = itr - seg[node].first.begin();
    itr1 = lower_bound(seg[node].first.begin(),seg[node].first.end(),y2);
    if(itr1 == seg[node].first.end())
      itr1--;
    while(*itr1 > y2 )
      itr1--;
    int index1 = itr1 - seg[node].first.begin();    
    int cnt = 0;
    if(index == 0 && index1 == 0)
    {
      cnt =  csum[node][index];
    }
    else if(index == 0 && index1!=0)
    {
      cnt =  csum[node][index1];
    }
    else
    {
      cnt = csum[node][index1]-csum[node][index-1];
    }
    return cnt;
  }
  int mid = (start+end)/2;
  return query(2*node,start,mid) + query(2*node+1,mid+1,end);
}
int main()
{
  sync;
  pre();
  int n;
  cin >> n;
  v1.pb(-1);
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v1.pb(a);
  }
  build(1,1,n);
  int q;
  cin >> q;
  while(q--)
  {
    cin >> l1 >> r1 >> x1 >> y2;
    int ans = query(1,1,n);
    cout << ans << endl;
  }
  /*for(int i=1;i<=9;i++)
  {
    cout << i << " ------- " << endl;
    for(int j=0;j<seg[i].first.size();j++)
    {
      cout << seg[i].first[j] << " " << seg[i].second[j] << "  " << csum[i][j] << endl;
    } 
  }*/
  
}

