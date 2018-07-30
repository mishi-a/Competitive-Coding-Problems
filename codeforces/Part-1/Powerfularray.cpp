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

int arr[200005],freq[1000005];
ll ans[200005];
vector <pair<pii,int> > q;
int sz;
ll answer=0;
bool acompare(pair<pii,int>& a,pair<pii,int>& b)
{
   if(a.FI.FI/sz<b.FI.FI/sz)
     return true;
   else if(a.FI.FI/sz==b.FI.FI/sz && a.FI.SE<b.FI.SE)
     return true;
   else
     return false;
}

void add(int idx)
{
  int prev = freq[arr[idx]];
  int curr = ++freq[arr[idx]];
  answer -= (ll)prev*prev*arr[idx];
  answer += (ll)curr*curr*arr[idx];
}

void remove(int idx)
{
  int prev = freq[arr[idx]];
  int curr = --freq[arr[idx]];
  answer -= (ll)prev*prev*arr[idx];
  answer += (ll)curr*curr*arr[idx];
}



int main()
{
  sync;
  int n,t,l,r;
  cin >> n >> t;
  sz = sqrt(n);
  for(int i=1;i<=n;i++)
     cin >> arr[i];
  for(int i=0;i<t;i++)
  {
     cin >> l >> r;
     q.pb({{l,r},i});  
  }
  sort(q.begin(),q.end(),acompare);
  int cl = 1;
  int cr = 0;
  for(int i=0;i<t;i++)
  {
    int l = q[i].FI.FI,r = q[i].FI.SE;
    
    while(cl<l)
      remove(cl++);
    while(cl>l)
      add(--cl);
    while(cr<r)
      add(++cr);
    while(cr>r)
      remove(cr--);
    ans[q[i].SE] = answer;
  }
  for(int i=0;i<t;i++)
    cout << ans[i] << endl;
}
