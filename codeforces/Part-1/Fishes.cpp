/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <long long,long long>
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
vector<ll> col(100005,0),row(100005,0);
ll idx[100005];

set<pii> s;
set<pii>:: iterator itr;
int main()
{
  sync;
  ll n,m,r,k;
  //scanf("%d%d%d%d",&n,&m,&r,&k);
  cin >> n >> m >> r >> k;
  for(ll i=1;i<=m;i++)
  {
    if(i+r-1>m)
      break;
    col[i]++;
    col[i+r]--;
  }
  for(ll i=1;i<=m;i++)
    col[i]+=col[i-1];
  for(ll i=1;i<=n;i++)
  {
    if(i+r-1>n)
      break;
    row[i]++;
    row[i+r]--;
    //cout << i << endl;
  }
  for(ll i=1;i<=n;i++)
    idx[i]=1;
  for(ll i=1;i<=n;i++)
    row[i]+=row[i-1];
  //cout << row[1] << " " << row[2] << " " << col[1] << " " << col[2] <<" " << idx[1] << " " << idx[2];
  sort(col.begin()+1,col.begin()+m+1,greater<int>());
  sort(row.begin()+1,row.begin()+n+1,greater<int>()); 
  for(ll i=1;i<=n;i++)
  {
    //cout << row[3] << idx[3]<<endl;
    //cout << (row[i]*(col[idx[i]])) << endl;
    s.insert({(row[i]*(col[idx[i]])),i});
  }
  ll sum=0;
  while(k>0)
  {
    itr = s.end();
    itr--;
    pii f = *itr;
    sum+=f.FI;
    s.erase(itr);
    idx[f.SE]++;
    if(idx[f.SE]<=m)
     s.insert({row[f.SE]*(col[idx[f.SE]]),f.SE});
    //cout << f.SE << " " << sum << endl;
    k--;
  }

  // // //printf("%0.6f",(sum*1.0)/((n-r+1)*(m-r+1)));
  cout << fixed;
  cout << setprecision(10) << (sum*1.0)/((n-r+1)*(m-r+1));
}
