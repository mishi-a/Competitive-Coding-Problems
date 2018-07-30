#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector <vector<int> > v(10004);
vector <int> visited(10004,0);
vector <int> color(10004,0);
vector <int> parent(10004,0);
ll sum = 0;
bool cycle = false;
void dfs_visit(int node)
{
  visited[node] = 1;
  sum++;
  color[node] = 1;
  for(int i=0;i<v[node].size();i++)
  {
    if(visited[v[node][i]] == 0)
    {
      parent[v[node][i]] = node;
      dfs_visit(v[node][i]);
    }
    else
    {
      if(color[v[node][i]] == 1&& v[node][i]!=parent[node])
        cycle = true;
    }
  }
  color[node] = 2;
}
void dfs(int source)
{
  dfs_visit(source);
}
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  while(m--)
  {
    int a,b;
    cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  dfs(1);
  //cout << sum << cycle <<  endl;
  if(cycle == true || sum!=n)
     cout <<"NO " << endl;
  else
     cout << "YES " << endl;
}
