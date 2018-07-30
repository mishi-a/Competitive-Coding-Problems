#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <vector<int> > v(10004);
vector <int> dist(10004,0);
vector <int> visited(10004,0);
void dfs_visit(int node)
{
  visited[node] = 1;
  for(int i=0;i<v[node].size();i++)
  {
    if(visited[v[node][i]] == 0)
    {
      dist[v[node][i]] =dist[node]+1;
      dfs_visit(v[node][i]);
    }
  }
}
void dfs(int source)
{
  dfs_visit(source);
}
int main()
{
  sync;
  int n;
  cin >> n;
  n--;
  while(n--)
  {
    int a,b;
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  dist[1] = 0;
  dfs(1);
  int ind = max_element(dist.begin(),dist.end())-dist.begin();
  //cout << ind << endl;
  //cout << dist[3] << endl;
  fill(dist.begin(),dist.end(),0);
  fill(visited.begin(),visited.end(),0);
  dfs(ind);
  cout << *max_element(dist.begin(),dist.end()) << endl;
}
