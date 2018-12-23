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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

vector<int> v[MAX];
vector<int> bfs;
map<int,int> mp;
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
  	int u,t;
  	cin >> u >> t;
  	v[u].pb(t);
  	v[t].pb(u);
  }
  for(int i=0;i<n;i++)
  {
  	int k;
  	cin >> k;
  	bfs.pb(k);
  }
  queue<int> q;
  q.push(1);
  int idx = 1;
  int dist[MAX]={0};
  int visited[MAX]={0};
  int par[MAX] = {0};
  visited[1] = 1;
  while(!q.empty())
  {
  	int front = q.front();
  	//cout << front << endl;
  	for(int i=0;i<v[front].size();i++)
  	{
  		if(!visited[v[front][i]])
  		{
  			dist[v[front][i]] = 1 +dist[front];
  			q.push(v[front][i]);
  			par[v[front][i]] = front;
  			visited[v[front][i]] =1 ;
  		}
  	}
  	q.pop();
  }
  //cout << dist[1] << " " << dist[2] << endl;
  for(int i=1;i<n;i++)
  {
  	if(dist[bfs[i]]-dist[bfs[i-1]] > 1 || dist[bfs[i-1]] > dist[bfs[i]] )
  	{
  		cout << "No" << endl;
  		return 0;
  	}
  }
  for(int i=0;i<n;i++)
  {
  	mp[bfs[i]] = i;
  }
  par[1] = 1;
  for(int i=1;i<n;i++)
  {
  	if(i+1 < n && mp[par[bfs[i]]]> mp[par[bfs[i+1]]])
  	{
  		cout << "No" << endl;
  		return 0;
  	}
  }
  cout << "Yes" << endl;
}
