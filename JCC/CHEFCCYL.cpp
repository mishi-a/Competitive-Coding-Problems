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

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
int n,q;
vector <int> v[100005];
int wt[100005];
vector <pii> g[100005];
vector <int> w[100005]; 
vector <pii>mark(100005,{-1,-1});   
vector <int>dis[100005],dis1[100005];
int mun[100005];
int clock1[100005];
int anti[100005];

void init()
{
   for(int i=1;i<=n;i++)
   {
     v[i].clear(),g[i].clear(),w[i].clear();
     mark[i] = {-1,-1};
     dis[i].clear(),dis1[i].clear();
     mun[i]=0,clock1[i]=0,anti[i]=0,wt[i]=0;
   }
}
void solve(int x)
{
  int cur = 1;
  for(int i=0;i<v[x].size();i++)
  {
    g[cur].clear();
    g[cur].pb({(cur+1)>v[x].size()?1:cur+1,v[x][i]});
    g[cur].pb({cur-1<1?v[x].size():cur-1,v[x][i-1<0?v[x].size()-1:i-1]});
    cur++;
  }
  /*for(int i=1;i<=v[x].size();i++)
  {
    for(int j=0;j<g[i].size();j++)
      cout<<g[i][j].first << "+" << g[i][j].SE << " ";
    cout << endl; 
  }*/
  int f = mark[x].FI;
  int s = mark[x].SE;
  //cout << f << " " << s << endl;
  mun[f]=0;
  dis[x].pb(-1);
  dis1[x].pb(-1);
  
  mun[g[f][0].FI] = g[f][0].SE;
  int prev = f;
  cur = g[f][0].FI;
  while(cur!=f)
  {
    int flag = 0;
    for(int i=0;i<g[cur].size();i++)
    {
      if(g[cur][i].FI!=prev&&g[cur][i].FI!=f)
      {
        flag = 1;
        mun[g[cur][i].FI]=mun[cur]+g[cur][i].SE;
        prev = cur;
        cur = g[cur][i].FI;
      }
    }
    if(flag == 0)
     break;
  }
  //cout << mun[1] << " " << mun[2] << " " << mun[3]  << endl;
   prev = f;
   cur = g[f][1].FI;
   //cout << cur << endl;
  mun[cur] = min(mun[cur],g[f][1].SE);
  while(cur!=f)
  {
    int flag = 0;
    for(int i=0;i<g[cur].size();i++)
    {
      if(g[cur][i].FI!=prev&&g[cur][i].FI!=f)
      {
        flag = 1;
        mun[g[cur][i].FI]=min(mun[cur]+g[cur][i].SE,mun[g[cur][i].FI]);
        prev = cur;
        cur = g[cur][i].FI;
      }
    }
    if(flag == 0)
     break;
  }
  for(int i=1;i<=v[x].size();i++)
    dis[x].pb(mun[i]);//,cout << mun[i] << " " ;
  //cout << endl; 
  memset(mun,0,sizeof(mun));
  prev = s;
  cur = g[s][0].FI;
  mun[cur] = g[s][0].SE;
  //cout << prev << cur << endl;
  while(cur!=s)
  {
    int flag = 0;
    for(int i=0;i<g[cur].size();i++)
    {
      if(g[cur][i].FI!=prev&&g[cur][i].FI!=s)
      {
        flag = 1;
        mun[g[cur][i].FI]=mun[cur]+g[cur][i].SE;
        prev = cur;
        cur = g[cur][i].FI;
      }
    }
    if(flag == 0)
      break;
  }
  //cout << mun[1] << " " << mun[2] << " " << mun[3]  << endl;
  prev = s;
  cur = g[s][1].FI;
  mun[cur] = min(mun[cur],g[s][1].SE);
  while(cur!=s)
  {
    int flag = 0;
    for(int i=0;i<g[cur].size();i++)
    {
      if(g[cur][i].FI!=prev&&g[cur][i].FI!=s)
      {
        flag = 1;
        mun[g[cur][i].FI]=min(mun[cur]+g[cur][i].SE,mun[g[cur][i].FI]);
        prev = cur;
        cur = g[cur][i].FI;
      }
    }
    if(flag == 0)
      break;
  }     
  for(int i=1;i<=v[x].size();i++)
    dis1[x].pb(mun[i]);
  //cout << endl;   
}   

int main()
{
  sync;
  int t,m,a,b,w;
  cin >> t;
  while(t--)
  {
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
       cin >> m;
       for(int j=0;j<m;j++)
       {
         if(m==1)
         {
           cin >> a;
           v[i].pb(0);
         }
         else
         cin >> a,v[i].pb(a);
       }
    }
    for(int i=1;i<=n;i++)
    {
      cin >> a >> b >> w;
      if(mark[i].first==-1)
        mark[i].first = a;
      else
        mark[i].SE = a;
      if(mark[i+1>n?1:i+1].first==-1)
        mark[i+1>n?1:i+1].first = b;
      else
        mark[i+1>n?1:i+1].SE = b;
      wt[i+1>n?1:i+1] = w;  
    }
    /*for(int i=1;i<=n;i++)
    {
      for(int j=0;j<v[i].size();j++)
        cout << v[i][j] << " ";
      cout << endl;
    }
    for(int i=1;i<=n;i++)
      cout << mark[i].FI << " " << mark[i].SE << endl;
    for(int i=1;i<=n;i++)
      cout << wt[i] << " " ;
    cout << endl;*/
    /*for(int i=1;i<=n;i++)
      cout << mark[i].FI << " " << mark[i].SE << endl;*/
    //cout << endl; 
    for(int i=1;i<=n;i++)
    {
      solve(i);
    }
    int curdist = 0;
    for(int i=1;i<=n;i++)
    {
      if(i==1){clock1[i]=0;continue;}
      curdist += wt[i];
      clock1[i] = curdist;
      curdist += dis[i][mark[i].SE];
    }
    curdist=0;
    anti[1]=0;
    anti[n] = wt[1];
    curdist = wt[1];
    for(int i=n-1;i>1;i--)
    {
      curdist += dis1[i+1][mark[i+1].FI];
      curdist += wt[i+1];
      anti[i] = curdist;
      
    }
    /*for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=v[i].size();j++)
        cout << dis[i][j] << " ";
      cout << endl;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=v[i].size();j++)
        cout << dis1[i][j] << " ";
      cout << endl;
    }*/
    /*for(int i=1;i<=n;i++)
      cout << clock1[i] << " ";
    cout << endl;
    for(int i=1;i<=n;i++)
      cout << anti[i] << " ";
    cout << endl;*/
    for(int i=0;i<q;i++)
    {
      int v1,c1,v2,c2;
      cin >> v1 >> c1 >> v2 >> c2;
      if(c1>c2)
       swap(c1,c2),swap(v1,v2);
      if(c1!=1)
      {
       int ans1 = clock1[c2]-(clock1[c1]+dis[c1][v1])+dis[c2][v2];
       int ans2 = clock1[c1]+dis[c1][v1]+dis[1][mark[1].SE]+anti[c2]+dis1[c2][v2];
       cout << min(ans1,ans2) << endl;
      }
      else
      {
        int ans1 = clock1[c2]+dis[c2][v2]+dis[1][v1];
        int ans2 = dis1[1][v1]+anti[c2]+dis1[c2][v2];
        cout << min(ans1,ans2) << endl;  
      } 
    }
    init();
  }
}

