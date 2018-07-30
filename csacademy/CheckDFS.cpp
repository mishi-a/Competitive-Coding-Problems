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
int per[100005];
vector <set<int> > v(100005);
int visited[100005];
int flag = 0;
int idx=2;
int n,m;
void dfs(int node)
{
  
  if(idx>n)
    return;
  
  //cout << node << " " << idx  << " " << per[idx]<< endl;
  set<int> :: iterator itr = v[node].begin();
    while(idx<=n && v[node].find(per[idx])!=v[node].end() && visited[per[idx]]==0)
    {
      //cout << node << endl;
      int num = per[idx];
      visited[num]=1;
      idx++;
      dfs(num);
      if(flag==1)
        return;
    }
    {
      itr = v[node].begin();
      
      while(itr!=v[node].end())
      {
        if(visited[*itr] == 0)
        {//cout << node << " " << *itr << " hi" << endl;
          flag = 1;
          return;
        }
        itr++;
      }
      //idx++;
      return;
    }
    return;
}

int main()
{
  sync;

  cin >> n >> m;
  for(int i=1;i<=n;i++)
  {
    cin >> per[i];
  }
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    v[a].insert(b);
    v[b].insert(a);
  }
  visited[1] = 1;
  dfs(1);
  //cout << flag  << endl;
  if(flag == 1)
  {
    cout << "0" << endl;
  }
  else
  {
    cout << "1" << endl;
  }
}

