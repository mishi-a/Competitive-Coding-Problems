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

using namespace std;
int arr[100005];
vector <pair<pii,int>> q;
int val[100005];
int sz;
int answer = 0;
int ans[100005];
bool acompare(pair<pii,int>&a,pair<pii,int>&b)
{
  if(a.FI.FI/sz < b.FI.FI/sz)
     return true;
  else if(a.FI.FI/sz == b.FI.FI/sz && a.FI.SE < b.FI.SE)
     return true;
  else
     return false;
}

void add(int idx)
{
  if(arr[idx]>100000)
    return;
  int val1 = (++val[arr[idx]]);
  if(val1 == arr[idx])
     answer++;
  else if(val1-1 == arr[idx])
     answer--;
}

void remove(int idx)
{
  if(arr[idx]>100000)
    return;
  int val1 = (--val[arr[idx]]);
  if(val1 == arr[idx])
     answer++;
  else if(val1+1 == arr[idx])
     answer--;
}
int main()
{
  sync;
  int n,m,l,r;
  cin >> n >> m;
  for(int i=1;i<=n;i++)
     cin >> arr[i];
  for(int i=0;i<m;i++)
  { 
    cin >> l >> r;
    q.pb({{l,r},i});
  }
  sz = ceil(sqrt(n));
  sort(q.begin(),q.end(),acompare);
  int cl=1;
  int cr =0;
  //
  //for(int i=0;i<q.size();i++) cout << q[i].FI.FI << " " << q[i].FI.SE << endl;
  for(int i=0;i<m;i++)
  {
    int l = q[i].FI.FI,r=q[i].FI.SE;
    while(cr>r)
    { 
      remove(cr);
      cr--;
    }
    while(cr<r)
    {
      cr++;
      add(cr);
    }
    while(cl<l)
    {
      remove(cl);
      cl++;
    }
    while(cl>l)
    {
      cl--;
      add(cl);
    }
    //cout << mp[1] << " " << mp[2] << " " << mp[3] << " " << mp[7] << endl;
    ans[q[i].SE] = answer;
  }      
  for(int i=0;i<m;i++)
    cout << ans[i] << endl;
    
}
