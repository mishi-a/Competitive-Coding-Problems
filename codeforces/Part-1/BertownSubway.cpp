/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
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
int arr[100005],vis[100005];
int main()
{
  sync;
  vector<int> v;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  	cin >> arr[i];
  ll sum = 0;
  for(int i=1;i<=n;i++)
  {
  	if(vis[i]==0)
  	{
  	  int cnt = 0;
  	  int idx = i;
      while(vis[idx]==0)
      {
        cnt++;
        vis[idx]=1;
        idx = arr[idx];
      }
      v.pb(cnt);
   	}
  }
  sort(v.begin(), v.end(),greater<int>());

  if(v.size()>2)
  {
  	int cnt = v[0]+v[1];
  	sum += 1LL*cnt*cnt;
  	for(int i=2;i<v.size();i++)
  		sum+=1LL*v[i]*v[i];
  }
  else if(v.size()==2)
  {
  	int cnt = v[0]+v[1];
  	sum += 1LL*cnt*cnt;
  }
  else
  	sum+=1LL*v[0]*v[0];
  cout << sum << endl;
}
