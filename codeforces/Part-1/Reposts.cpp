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

map <string,int>mp;
vector <vector<int>>v(205);
int visited[205] = {0};
int ans = -1;
void dfs(int node,int level)
{
  ans = max(ans,level);
  visited[1] = 1;
  for(int i=0;i<v[node].size();i++)
  {
    if(visited[v[node][i]]==0)
      dfs(v[node][i],level+1);
  }
}
int main()
{
  sync;
  int x;
  cin >> x;
  x+=1;
  int z=0;int cnt=2;
  while(x--)
  {
    z++;
    string t;
    getline(cin,t);
    if(z==1)
      continue;
    string a="",b="";
    int ind;
    mp["polycarp"] = 1;
    
    for(int i=0;i<t.length();i++)
    {
       if(t[i]!=' ')
         a = a+t[i];
       else
       {
         ind = i;
         break;
       }
    }
    for(int i=ind+10;i<t.length();i++)
        b = b+t[i];
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    mp[a] = cnt;
    cnt++;
    v[mp[b]].pb(mp[a]);
  }
  dfs(1,1);
  cout << ans << endl;
}

