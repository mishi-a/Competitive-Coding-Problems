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
int graph[20][20],dist[20][20];
map <int,int> mp;
#define INF 1e9
int V;
void floydWarshall () 
{ 
    /* dist[][] will be the output matrix that will finally have the shortest  
      distances between every pair of vertices */
    int  i, j, k; 
  
    /* Initialize the solution matrix same as input graph matrix. Or  
       we can say the initial values of shortest distances are based 
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
         {
            dist[i][j] = graph[i][j];
         }    
  
    for (k = 0; k < V; k++) 
    { 
        // Pick all vertices as source one by one 
        for (i = 0; i < V; i++) 
        { 
            // Pick all vertices as destination for the 
            // above picked source 
            for (j = 0; j < V; j++) 
            { 
                // If vertex k is on the shortest path from 
                // i to j, then update the value of dist[i][j] 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
   /* for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
        cout << dist[i][j] << " ";
      cout << endl;
    }*/
    // Print the shortest distance matrix 
} 
void solve(int itr)
{
  for(int i=1;i<pow(2,V)-1;i++)
  {
    int tot = 0;
    
    for(int j=0;j<V;j++)
    {
      int d = INT_MAX;
      for(int k=0;k<V;k++)
      {
        if(k==j)continue;
        //cout << i << " " << j << " " << k << (i&(1<<j)) <<(i&(1<<k))<< endl;
        //return ;
        if(((i>>j)&(1))!=((i>>k)&(1)))
        {
          //cout << "hi " << k << j << endl;
          d = min(d,dist[j][k]);
        }
      }
      //cout <<"aa " << d << endl;
      tot+=d;
    }
    //cout <<i << " " <<tot << endl;
    if(tot>=0 )
      mp[tot]++;
    //break;
  }
  cout << "Case #" << itr << ": " << mp.begin()->SE << endl;

}
int main()
{
  sync;
  int t;
  cin >> t;
  int itr = 0;
  while(t--)
  {
    itr++;
    int v,e;
    cin >> V >> e;
    for(int i=0;i<V;i++)
      for (int j = 0; j < V; ++j)
      {
        graph[i][j] = INF;
      }
    for(int i=0;i<e;i++)
    {
      int a,b,c;
      cin >> a >> b >> c;
      a--,b--;
      graph[a][b]=c;
      graph[b][a]=c;
    }
    floydWarshall();
    solve(itr);
    mp.clear();
    memset(dist,0,sizeof(dist));
    memset(graph,0,sizeof(graph));
  }
}
